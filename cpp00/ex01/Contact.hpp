

class Contact
{
	public:
		char *firstname;
		char *lastname;
		char *nickname;
		char *number;
		Contact(char *firstname, char *lastname, char *nickname, char *number);
		~Contact(void);
};