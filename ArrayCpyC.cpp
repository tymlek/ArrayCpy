// ArrayCpyC.cpp

#include "ArrayCpyC.h"

void array_cpy_c(long source[], long destination[], unsigned count)
{
	for (auto i = 0; i != count; ++i)
		destination[i] = source[i];
}
