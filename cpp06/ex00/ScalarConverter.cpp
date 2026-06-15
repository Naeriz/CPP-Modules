#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default has been contstructed\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter& cpyfrom)
{
	(void) cpyfrom;
	std::cout << "Copy constructor has been called\n";
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter& cpyfrom)
{
	(void) cpyfrom;
	std::cout << "assignment operator has been called\n";
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter has been destructed\n";
}

int	check_digits(const std::string &str)
{
	size_t i = 0;

	while (i < str.length())
	{
		if (str.length() == 1 && (str[0] == '-' || str[0] == '+'))
        	return (0);
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		else if (isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void print_pseudo(const std::string &str)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	if (str == "nan" || str == "+inf" || str == "-inf") 
	{
		std::cout << "float: " << str << "f\n";
		std::cout << "double: " << str << "\n";
	}
	else
	{
		std::cout << "float: " << str << "\n";
		std::cout << "double: " << str.substr(0, str.length() - 1) << "\n"; //if float remove f at end
	}
}

void print_char(char c)
{
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

void print_int(const std::string &str)
{
	char *end;
    long value = std::strtol(str.c_str(), &end, 10); //10 for decimal base
	if (*end != '\0' || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return;
    }

	int i = static_cast<int>(value);

	std::cout << "char: ";
	if (i < 0 || i > 127)
		std::cout << "impossible\n";
	else if (i < 32 || i > 126)
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(i) << "'\n";
	std::cout << "int: " << i << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(i) << "f\n";
	std::cout << "double: " << static_cast<double>(i) << "\n";
}

bool is_float(const std::string &str)
{
    if (str[str.length() - 1] != 'f')
        return false;
    char *end;
    std::string trimmed = str.substr(0, str.length() - 1);
    std::strtof(trimmed.c_str(), &end);
    return (*end == '\0');  // whole string consumed
}

bool is_double(const std::string &str)
{
    char *end;
    std::strtod(str.c_str(), &end);
    return (*end == '\0');
}

void print_float(const std::string &str)
{
	char *end;
	float f = std::strtof(str.c_str(), &end);
	std::cout << "char: ";
	if (f < 0 || f > 126)
		std::cout << "impossible\n";
	else
		std::cout << "'" << static_cast<char>(f) << "'\n";
	std::cout << "int: ";
	if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(f) << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f\n";
	std::cout << "double: " << static_cast<double>(f) << "\n";
}

void print_double(const std::string &str)
{
	char *end;
	double d = std::strtod(str.c_str(), &end);
	std::cout << "char: ";
	if (d < 0 || d > 126)
		std::cout << "impossible\n";
	else
		std::cout << "'" << static_cast<char>(d) << "'\n";
	std::cout << "int: ";
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(d) << "\n";
	std::cout << std::fixed << std::setprecision(1);
	float f = static_cast<float>(d);
	if (std::isinf(f) && !std::isinf(d))
		std::cout << "float: impossible\n";
	else
		std::cout << "float: " << f << "f\n";
	std::cout << "double: " << d << "\n";
}

void ScalarConverter::convert(const std::string& str)
{
	if (str.empty())
	{
		std::cout << "empty string\n";
		return ;
	}
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (!isprint(str[i]))
		{
			std::cout << "Non displayable character\n";
			return ;
		}
	}
	if (str.find('e') != std::string::npos || str.find('E') != std::string::npos)
	{
		std::cout << "Scientific notion not supported\n";
		return ;
	}
	if (str == "-inff" || str == "+inff" || str == "nanf"
		|| str == "-inf" || str == "+inf" || str == "nan")
		print_pseudo(str);
	else if (str.length() == 1 && isalpha(str[0]))
		print_char(str[0]);
	else if (check_digits(str))
		print_int(str);
	else if (is_float(str))
		print_float(str);
	else if (is_double(str))
		print_double(str);
	else
	{
		std::cout << "char: impossible\n";
    	std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
	}
}