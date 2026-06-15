#pragma once

#include <string>
#include <iostream>
#include <iomanip>  // for setprecision
#include <limits>   // for numeric_limits
#include <cmath>    // for isinf, isnan
#include <cstdlib>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& cpyfrom);
		ScalarConverter& operator=(const ScalarConverter& cpyfrom);
		~ScalarConverter();

	public:
		static void convert(const std::string &str);
} ;