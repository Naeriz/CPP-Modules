#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cstdlib>

class Bitcoin
{
	private:
		std::map<std::string, float>	_db;

		void 	anti_whitespace(std::string &strip);
		bool	date_valid(const std::string &date);
		int		month_leap_check(int month, int year);
		float	value_valid(std::string value, int which);
		void	lookup_print(float valid_val, const std::string &date, const std::string &raw_val);
	
	public:
		Bitcoin();
		Bitcoin(const Bitcoin &cpyfrom);
		Bitcoin& operator=(const Bitcoin &cpyfrom);
		~Bitcoin();
		void	parse_db();
		void 	parse_input(char *filename);
	
} ;