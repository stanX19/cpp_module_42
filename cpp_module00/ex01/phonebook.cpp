#include "phonebook.hpp"

static std::string	format_column(std::string src, int width)
{
	std::string ret;

	if ((int)src.length() <= width)
	{
		ret = src;
		for (int i = src.length(); i < width; i++)
			ret += ' ';
	}
	else
		ret = src.substr(0, width - 1) + '.';
	return ret;
}

void show_list(Contact *contacts, size_t len)
{
	std::stringstream	buffer;

	std::cout << "\033[4m                                             \n"
			  << "|index     |First Name|Last Name |Nickname  |\n";
	buffer.str("|          ");
	for (size_t idx = 0; idx < len; idx++) {
		buffer.seekp(1);
		buffer << idx + 1;
		std::cout << buffer.str() << '|';
		for (int j = 0; j < 3; j++) {
			std::cout << format_column(*(contacts[idx].prompts[j].ptr), 10) << '|';
		}
		std::cout << "\n";
	}
	std::cout << "\033[0m";
}
void search(Contact *contacts, size_t len)
{
	long double idx;

	show_list(contacts, len);
	std::cout << "Index: ";
	if ((std::cin >> std::get_money(idx)).good()) {
		contacts[(int)idx - 1].display();
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main(void) {
	std::string			command;
	size_t				len;
	Contact				contacts[8];

	len = 0;
	// temp for testing
	// contacts[len++].initialize((std::string[11]){
	// 	"Shan Chien",
	// 	"Tan",
	// 	"Stan",
	// 	"0123456789",
	// 	"-",
	// 	"-",
	// 	"-",
	// 	"-",
	// 	"-",
	// 	"-",
	// 	"in your dreams",
	// }, 11);

	// contacts[len++].initialize((std::string[11]){
	// 	"William",
	// 	"???",
	// 	"like I know",
	// 	"0198765432",
	// 	"-",
	// 	"-",
	// 	"-",
	// 	"-",
	// 	"-",
	// 	"-",
	// 	"???????",
	// }, 11);

	while (true) {
		std::cout << "Command: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			return 0;
		else if (command == "ADD"){
			if (len < 8)
				contacts[len++].record();
			else
				std::cout << "Out of memory\n";
		}
		else if (command == "SEARCH") {
			search(contacts, len);
		}
	}
}
