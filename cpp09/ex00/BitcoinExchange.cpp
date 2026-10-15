#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() {}

Bitcoin::Bitcoin(const Bitcoin &cpyfrom)
{
	_db = cpyfrom._db;
	// std::cout << "copy constructor has been called\n";
}

Bitcoin &Bitcoin::operator=(const Bitcoin &cpyfrom)
{
	if (this != &cpyfrom)
	{
		_db = cpyfrom._db;
	}
	// std::cout << "assignment operator has been called\n";
	return (*this);
}

Bitcoin::~Bitcoin() {}

void	Bitcoin::anti_whitespace(std::string &strip)
{
	std::string targets = " \t";
	std::string::size_type first = strip.find_first_not_of(targets);
	std::string::size_type last = strip.find_last_not_of(targets);

	if (first == std::string::npos)
		strip.clear();
	else
		strip = strip.substr(first, last - first + 1);
}

void	Bitcoin::lookup_print(double valid_val, const std::string &date, const std::string &raw_val)
{
	if (_db.empty())
		throw std::runtime_error("database is empty");

	std::map<std::string, double>::const_iterator it = _db.lower_bound(date); //exact or closest higher, upperbound would only do higher

    //end if date later than anything in db || date not in db
	if (it == _db.end() || it->first != date) //end part first, it->first leads to undef behaviour cuz end is marker for "one past last element"
	{
		//it first entry, covered by btc creation but safety net
		if (it == _db.begin())
			throw std::invalid_argument("no earlier date in database => " + date);
		--it; //compensate for lower_bound closest higher
	}

	std::cout << date << " => " << raw_val << " = " << valid_val * it->second << std::endl;
}

void	Bitcoin::parse_input(char *filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
		throw(std::runtime_error("couldn't open input file"));

	std::string line;
	std::string date;
	std::string value;
	if(!getline(file, line) || line != "date | value")
		throw(std::invalid_argument("missing headerline: date | value"));
	while(getline(file, line))
	{
		try
		{
			if (std::count(line.begin(), line.end(), '|') != 1)
				throw(std::invalid_argument("bad input => " + line));
			std::stringstream ss(line); //turn line into stream to then extract easier
			std::getline(ss, date, '|');
			std::getline(ss, value);
			// pipe stripped alone and no longer relevant
			anti_whitespace(date);
			anti_whitespace(value);
			if (!date_valid(date))
				throw std::invalid_argument("bad input => " + date);
			double valid_val = value_valid(value, 1); 
			lookup_print(valid_val, date, value);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}

void	Bitcoin::parse_db()
{

	std::ifstream	db("data.csv");
	if (!db.is_open())
		throw(std::runtime_error("couldn't open csv file"));

	std::string		db_date;
	std::string		db_value;
	std::string		line;
	if (!getline(db, line) || line != "date,exchange_rate")
		throw(std::logic_error("data.csv contains issues on the first line"));
	while (getline(db, line))
	{
		std::stringstream ss(line);
		std::getline(ss, db_date, ',');
		std::getline(ss, db_value);
		//maybe whitespace check
		if (db_date.empty() || db_value.empty())
			throw(std::invalid_argument("data.csv contains empty fields"));
		if (std::count(line.begin(), line.end(), ',') != 1)
			throw(std::logic_error("data.csv contains malformed line"));
		if (!date_valid(db_date))
			throw (std::logic_error("data.csv contains malformed date"));
		double valid_val = value_valid(db_value, 0);
		_db[db_date] = valid_val;
	}
	//db.close(); not needed
}

int 	Bitcoin::month_leap_check(int month, int year)
{
	bool leap = false;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		leap = true;
	
	int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,};

	if (month == 2 && leap == true)
		days[2] = 29;

	return days[month];
}

bool	Bitcoin::date_valid(const std::string &date) //stuck to	bool cuz same error msg unlike value
{
	int year = 0;
	int month = 0;
	int day = 0;

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.size(); i++) //int i was signed vs unsigned
	{
		if ((i != 4 && i != 7) && (date[i] < '0' || date[i] > '9'))
			return false;
	}
	std::stringstream(date.substr(0, 4)) >> year;
	std::stringstream(date.substr(5, 2)) >> month;
	std::stringstream(date.substr(8, 2)) >> day;
	if (year < 2009 || month <= 0 || day <= 0 || month > 12 || day > 31)
		return false;
	if (year == 2009)
		if (month == 1 && day <= 1)
			return false;
	
	if (day > month_leap_check(month, year))
		return false;
	return true;
}

double	Bitcoin::value_valid(std::string value, int which)
{
	char* endp;

	if (value.empty())
		throw(std::invalid_argument("empty value"));
	if (value[0] == '-')
		throw(std::invalid_argument("not a positive number"));

	if (which == 1)
	{
		if (value[value.size() - 1] == 'f')
		{
			if (value.size() == 1)
				throw(std::invalid_argument("bad value: " + value));
			value = value.substr(0, value.size() - 1);
		}
	}

	if (value.find_first_not_of("0123456789.") != std::string::npos)
		throw(std::invalid_argument("bad value => " + value));
	if (std::count(value.begin(), value.end(), '.') > 1 || value[0] == '.' || value[value.size() - 1] == '.')
		throw(std::invalid_argument("bad value => " + value));	
	double res = std::strtod(value.c_str(), &endp);

	if (endp == value.c_str() || *endp != '\0') //no conversion || trailing garbage. kept as safety net
		throw(std::invalid_argument("value contains invalid characters"));

	if (which == 1) //0 for csv, 1 input. 1000 check only for input needed
	{
		if (res > 1000)
			throw(std::invalid_argument("too large a number"));
	}
	return res;
}