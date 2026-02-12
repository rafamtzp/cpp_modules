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

int main(int argc, char **argv)
{
	if (argc != 4)
		return 1;
	std::string filename(argv[1]);
	std::ifstream file(filename);
	std::ofstream file_copy(filename.append(".replace"));
	std::string strread;
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	while (file >> strread)
	{
		if (strread ==  s1)
			file_copy << 
		std::cout << strread << std::endl;
	}
}