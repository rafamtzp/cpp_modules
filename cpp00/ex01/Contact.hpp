#include <iostream>

class Contact
{
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string number;
		std::string secret;
	public:
		Contact(void);
		Contact(char *firstname, char *lastname, char *nickname, char *number, char *secret);
		~Contact(void);
		bool has_data(void) const;
		void clear(void);
		int	setField(std::string field, std::string input);
		int	setNumber(std::string input);
		std::string	getField(std::string field);
};