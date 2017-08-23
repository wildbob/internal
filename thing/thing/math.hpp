#pragma once
#include "instance.hpp"
#include "vector.hpp"

class c_math
{
private:
public:
	c_math();
	~c_math();
	void vector_transform(const float *in1, const matrix3x4_t& in2, float *out);
};

extern c_math g_math;