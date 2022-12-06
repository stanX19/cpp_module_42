#include "phonebook.hpp"

Contact::Contact() {
	memcpy(this->prompts, (prompt_val[11])
	{
		{"First Name      : ", &first_name},
		{"Last Name       : ", &last_name},
		{"Nickname        : ", &nickname},
		{"Phone number    : ", &phone_number},
		{"Login           : ", &login},
		{"Postal address  : ", &postal_address},
		{"Email address   : ", &email_address},
		{"Birthday date   : ", &birthday_date},
		{"Favroite meal   : ", &favorite_meal},
		{"Underwear color : ", &underwear_color},
		{"Darkest secret  : ", &darkest_secret}
	},
	sizeof(this->prompts));
};

void Contact::record(void) {
	for (int i = 0; i < 11; i++) {
		std::cout << prompts[i].prompt;
		std::getline(std::cin, *(prompts[i].ptr));
	}
}

void Contact::initialize(std::string *argv, int size)
{
	for (int i = 0; i < size; i++) {
		*(prompts[i].ptr) = argv[i];
	}
}

void Contact::display(void) {
	for (int i = 0; i < 11; i++) {
		std::cout << prompts[i].prompt << *(prompts[i].ptr) << '\n';
	}
}

