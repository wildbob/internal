#pragma once

#include "window_includes.hpp"
#include <sstream>

class c_utils
{
private:
	inline PVOID*& getvtable(PVOID inst, size_t offset = 0)
	{
		return *reinterpret_cast< PVOID** >((size_t)inst + offset);
	}
	inline const PVOID* getvtable(const void* inst, size_t offset = 0)
	{
		return *reinterpret_cast< const PVOID** >((size_t)inst + offset);
	}
public:
	c_utils();
	~c_utils();
	template< typename Fn >
	inline Fn get_virtual_func(const void* inst, size_t index, size_t offset = 0)
	{
		return reinterpret_cast< Fn >(getvtable(inst, offset)[index]);
	}
	template< class T > T* get_interface(std::string szModuleName, std::string szInterfaceName, bool bSkip = false)
	{
		if (szModuleName.empty() || szInterfaceName.empty())
			return nullptr;

		typedef PVOID(*CreateInterfaceFn)(const char* pszName, int* piReturnCode);
		CreateInterfaceFn hInterface = nullptr;
		while (!hInterface)
		{
			hInterface = (CreateInterfaceFn)GetProcAddress(GetModuleHandleA(szModuleName.c_str()), "CreateInterface");
			Sleep(5);
		}

		char pszBuffer[256];
		for (int i = 0; i < 100; i++)
		{
			sprintf_s(pszBuffer, "%s%0.3d", szInterfaceName.c_str(), i);
			PVOID pInterface = hInterface(pszBuffer, nullptr);

			if (pInterface && pInterface != NULL)
			{
				if (bSkip)
					sprintf_s(pszBuffer, "%s%0.3d", szInterfaceName.c_str(), i + 1);

				Sleep(5);
				break;
			}
		}

		return (T*)hInterface(pszBuffer, nullptr);
	}
	template<class T, class U>
	T clamp(T in, U low, U high)
	{
		if (in <= low)
			return low;

		if (in >= high)
			return high;

		return in;
	}
};

extern c_utils g_utils;