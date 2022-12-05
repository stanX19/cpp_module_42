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

Contact::Contact() {
	prompt_val _prompts[11] = {
		{"First Name      : ", &first_name},
		{"Last Name       : ", &last_name},
		{"Nickname        : ", &nickname},
		{"Phone number    : ", &phone_number},
		{"Login           : ", &login},
		{"Postal address  : ", &postal_address},
		{"Email address   : ", &email_address},
		{"Birthday daye   : ", &birthday_date},
		{"Favroite meal   : ", &favorite_meal},
		{"Underwear color : ", &underwear_color},
		{"Darkest secret  : ", &darkest_secret}
	};
	for (int i = 0; i < 11; i++) {
		(this->prompts)[i].prompt = _prompts[i].prompt;
		(this->prompts)[i].ptr = _prompts[i].ptr;
	}
};

void Contact::record(void) {
	for (int i = 0; i < 11; i++) {
		std::cout << prompts[i].prompt;
		std::getline(std::cin, *(prompts[i].ptr));
	}
}

void Contact::display(void) {
	for (int i = 0; i < 11; i++) {
		std::cout << prompts[i].prompt << *(prompts[i].ptr) << '\n';
	}
}

void Contact::basic(int width) {
	for (int i = 0; i < 3; i++) {
		std::cout << format_column(*(prompts[i].ptr), width) << '|';
	}
}