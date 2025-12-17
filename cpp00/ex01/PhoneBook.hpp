#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int index;
		Contact contacts[8];
	
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void add_contact(Contact contacts[], int index);
		void search_contact(Contact contacts[]);
};