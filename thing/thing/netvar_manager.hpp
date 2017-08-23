#pragma once
#include "instance.hpp"
#include <vector>
#include <fstream>
#include <utility>
#include <unordered_map>

class NetvarDatabase;
struct NetvarTable;

class c_netvars
{
	static c_netvars* instance;

	c_netvars();
	~c_netvars();

	c_netvars(const c_netvars&) = delete;

public:
	static c_netvars* Instance()
	{
		if (!instance) instance = new c_netvars;
		return instance;
	}

	void CreateDatabase();
	void DestroyDatabase();

	void Dump(std::ostream& stream);
	void Dump(const std::string& file);

	int GetNetvarCount() { return m_netvarCount; }
	int GetTableCount() { return m_tableCount; }

	template<typename ...Args>
	uint32_t GetOffset(const std::string& szTableName, Args&&... args)
	{
		return GetOffset(szTableName, { std::forward<Args>(args)... });
	}
private:
	std::unique_ptr<NetvarTable>  InternalLoadTable(RecvTable* pRecvTable, uint32_t offset);
	void                          Dump(std::ostream& output, NetvarTable& table, int level);
	uint32_t                      GetOffset(const std::string& szTableName, const std::initializer_list<std::string>& props);

private:
	std::unique_ptr<NetvarDatabase>    m_pDatabase = nullptr;
	uint32_t                           m_tableCount = 0;
	uint32_t                           m_netvarCount = 0;
};

#define NETVAR(table, ...) c_netvars::Instance()->GetOffset(table, __VA_ARGS__)

