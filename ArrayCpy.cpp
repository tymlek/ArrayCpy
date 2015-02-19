// ArrayCpy.cpp

#include <iostream>
#include <chrono>
#include <stdexcept>
#include "ArrayCpyAsm.h"
#include "ArrayCpyC.h"

//-----------------------------------------------------------------------------

int main()
{
	try {
		const unsigned long array_size = 100000;
		const unsigned long copy_times = 50000;
		long source[array_size];
		long dest[array_size];
		auto t0 = std::chrono::steady_clock::now();
		auto t1 = std::chrono::steady_clock::now();
	
		// Fill an array with pseudorandom integers
		for (auto i = 0; i != array_size; ++i)
			source[i] = rand();

		// Test the Assembly language procedure
		std::cout<<"Please wait...\n";

		t0 = std::chrono::steady_clock::now();

		for (auto i = 0; i != copy_times; ++i)
			array_cpy_asm(source,dest,array_size);

		t1 = std::chrono::steady_clock::now();

		std::cout<<"Elpased ASM time: "
					<<std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count()
					<<"ms.\n";

		// Test the C++ language function
		std::cout<<"Please wait...\n";

		t0 = std::chrono::steady_clock::now();

		for (auto i = 0; i != copy_times; ++i)
			array_cpy_c(source,dest,array_size);

		t1 = std::chrono::steady_clock::now();

		std::cout<<"Elpased C++ time: "
					<<std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count()
					<<"ms.\n";
	}
	catch(std::exception e) {
		std::cerr<<"An exception has occurred:\n"<<e.what()<<std::endl;
		return 1;
	}
	catch(...) {
		std::cerr<<"An exception has occurred:\n";
		return 2;
	}

	return 0;
}
