#include <iostream>
#include <fstream>

char upper(char c)
{
	if ('a' <= c && c <= 'z')
		c -= 32;
	return c;
}

char* capitalize(char*str)
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = upper(str[i]);
	}
	return str;
}

int main(int argc, char**argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else {
		for (int i = 1; i < argc; i++)
			std::cout << capitalize(argv[i]);
		std::cout << "\n";
	}
}