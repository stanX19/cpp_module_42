#include "phonebook.hpp"


int main(void) {
	std::string			command;
	std::stringstream	buffer;
	int					len;
	Contact				contacts[20];

	len = 0;
	while (true) {
		std::cout << "Command: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			return 0;
		else if (command == "ADD")
			contacts[len++].record();
		else if (command == "SEARCH") {
			for (int i = 0; i < len; i++) {
				buffer << i + 1;
				for (int j = 0; j < 10 - (int)buffer.str().length(); j++)
					buffer << ' ';
				std::cout << buffer << '|';
				contacts[i].basic(10);
				std::cout << "\n";
			}
		}
	}
}
