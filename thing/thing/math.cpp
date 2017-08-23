#pragma once
#include "math.hpp"

c_math g_math;

c_math::c_math()
{

}

c_math::~c_math()
{

}

auto c_math::vector_transform(const float *in1, const matrix3x4_t& in2, float *out) -> void
{
	Assert(s_bMathlibInitialized);
	Assert(in1 != out);
	//cast to VECTOR
	out[0] = DotProduct(*(Vector*)in1, *(Vector*)in2[0]) + in2[0][3];
	out[1] = DotProduct(*(Vector*)in1, *(Vector*)in2[1]) + in2[1][3];
	out[2] = DotProduct(*(Vector*)in1, *(Vector*)in2[2]) + in2[2][3];
}
