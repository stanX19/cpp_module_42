#include <iostream>
#include <iomanip>
#include <string>

typedef struct {
	std::string prompt;
	std::string *ptr;
} prompt_val;

std::string to_column(std::string src, int width)
{
	std::string ret;

	if ((int)src.length() <= width)
	{
		ret = src;
		for (int i = src.length(); i < width; i++)
			ret += ' ';
	}
	else
		ret = src.substr(0, width) + '.';
	return ret;
}

class Contact {
	public:
		std::string	phone_number;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	login;
		std::string	postal_address;
		std::string	email_address;
		std::string	birthday_date;
		std::string	favorite_meal;
		std::string	underwear_color;
		std::string	darkest_secret;
		prompt_val prompts[11];
		 
		Contact()
		{
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
				(this->prompts)[i].ptr    = _prompts[i].ptr;
			}
		};

		void record(void) {
			for (int i = 0; i < 11; i++) {
				std::cout << prompts[i].prompt;
				std::getline(std::cin, *(prompts[i].ptr));
			} 
		}

		void display(void) {
			for (int i = 0; i < 11; i++) {
				std::cout << prompts[i].prompt << *(prompts[i].ptr) << '\n';
			}
		}

		void basic(int width) {
			for (int i = 0; i < 3; i++) {
				std::cout << to_column(*(prompts[i].ptr), width) << '|';
			}
		}
};




int main(void) {
	Contact human1;
	Contact human2;

	std::cout << "Human 1\n";
	//human1.nickname = "human1";
	human1.record();

	std::cout << "Human 2\n";
	//human2.nickname = "human2";
	human2.record();

	std::cout << "Human 1\n";
	human1.basic(10);

	std::cout << "Human 2\n";
	human2.basic(10);
}
