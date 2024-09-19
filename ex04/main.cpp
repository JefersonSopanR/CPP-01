#include <iostream>
#include <fstream>
#include <string>

std::string replace(std::string str, std::string to_find, std::string replace)
{
	std::string result;
	size_t pos = 0;
	while ((pos = str.find(to_find)) != std::string::npos)
	{
		result += str.substr(0, pos);
		result += replace;
		str.erase(0, pos + to_find.length());
	}
	result += str;
	return result;
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./replace <filename> <to_find> <replace>." << std::endl;
		return 1;
	}
	std::string filename = av[1];
	std::string to_find = av[2];
	std::string replace_str = av[3];
	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "Error: could not open '" << filename << "' file"<< std::endl;
		return 1;
	}
	if (infile.peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << "Error: file is empty." << std::endl;
		infile.close();
		return 1;
	}
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "Error: could not create output file." << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(infile, line))
	{
		outfile << replace(line, to_find, replace_str) << std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
}
