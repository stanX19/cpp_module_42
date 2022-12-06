#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

typedef struct {
	std::string prompt;
	std::string* ptr;
} prompt_val;

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

	Contact();
	void record(void);
	void display(void);
	void initialize(std::string *argv, int size);
};