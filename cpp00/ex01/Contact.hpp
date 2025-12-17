#include <iostream>

class Contact
{
	
	public:
		char *firstname;
		char *lastname;
		char *nickname;
		char *number;
		char *secret;
		Contact(void);
		Contact(char *firstname, char *lastname, char *nickname, char *number, char *secret);
		~Contact(void);
};