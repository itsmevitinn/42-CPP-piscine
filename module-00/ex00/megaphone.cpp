#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int word = 1; argv[word]; word++)
	{
		for (size_t letter = 0; letter < strlen(argv[word]); letter++)
			std::cout << (char)toupper(argv[word][letter]);
	}
	std::cout << std::endl;
	return (0);
}
