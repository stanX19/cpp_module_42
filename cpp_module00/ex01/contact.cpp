#include "phonebook.hpp"

static void* copy_promptval(prompt_val *dst, prompt_val *src, size_t n)
{
	for (size_t i = 0; i < n; i++) {
		dst[i].prompt = src[i].prompt;
		dst[i].ptr = src[i].ptr;
	}
	return dst;
}

Contact::Contact() {
	copy_promptval(this->prompts, (prompt_val[11])
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
	11);
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

