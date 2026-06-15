#include <iostream>
#include <string>
#include <fstream>

//npos == null position; what gets returned if string in line not found

void	replacing(std::ifstream &input, std::ofstream &output, std::string &victim, std::string &replacer)
{
	std::string	line;
	int i = 0;

	while (std::getline(input, line))
	{
		size_t pos = 0;
		while ((pos = line.find(victim, pos)) != std::string::npos)
		{
			line.erase(pos, victim.size());
			line.insert(pos, replacer);
			pos += replacer.size();
		}
		output << line << "\n"; //appends
		i++;
	}
	if (i == 0)
		std::cout << "empty file or directory found\n";
}

int	main(int argc, char **argv) //ifstream reading and ofstream writing into file
{
	if (argc == 4)
	{
		std::string	file = argv[1]; 
		std::string	victim = argv[2];
		std::string	replacer = argv[3];
		std::ifstream input(file.c_str()); //can open even directory->will create empty file!!!user error //opens file so closing needed // .c_str makes str appear like ptr (ptr gets autodeleted afterwards)
		if (!input.is_open())
		{
			std::cout << "couldn't open file\n";
			return (1);
		}

		std::string	output_scam = file + ".replace"; //ifstream and ofstream need ptr (cant make ptr scam bcs of + so this needed in 2lines)
		std::ofstream output(output_scam.c_str()); //ofstream creates file //scam ptr
		if (!output.is_open())
		{
			input.close();
			std::cout << "can't create file\n";
			return (1);
		}
		replacing(input, output, victim, replacer);
		input.close();
		output.close();
	}
	else
		std::cout << "wrong amount of arguments\n";
	return (0);
}
