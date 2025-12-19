#include <iostream>

class Contact
{
	public:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string number;
		std::string secret;
		Contact(void);
		Contact(char *firstname, char *lastname, char *nickname, char *number, char *secret);
		~Contact(void);
		bool has_data(void) const;
		void clear(void);
};