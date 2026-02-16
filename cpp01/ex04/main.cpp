// Create a program that takes three parameters in the following order: a filename and
// two strings, s1 and s2.
// It must open the file <filename> and copy its content into a new file
// <filename>.replace, replacing every occurrence of s1 with s2.
// Using C file manipulation functions is forbidden and will be considered cheating. All
// the member functions of the class std::string are allowed, except replace. Use them
// wisely!
// Of course, handle unexpected inputs and errors. You must create and turn in your
// own tests to ensure that your program works as expected.
#include <iostream>
#include <fstream>

std::string	line_replaceAll(std::string line, std::string s1, std::string s2)
{
	int pos = line.find(s1);
	while (pos != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos = line.find(s1, pos);
	}
	return (line);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./main <file name> <string to find> <replacement>"
		<< std::endl;
		return 1;
	}

	std::string filename(argv[1]);
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "Could not open file (does not exist or no permission)" << std::endl;
		return (1);
	}

	std::ofstream file_copy(filename.append(".replace"));
	std::string line;
	while (std::getline(file, line))
	{
		file_copy << line_replaceAll(line, argv[2], argv[3]) << std::endl;
	}
}