#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int index;
		Contact contacts[8];
		bool is_nonempty(int i);
	
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void add_contact(void);
		void search_contact(void);
};