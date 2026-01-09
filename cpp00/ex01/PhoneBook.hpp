#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int index;
		Contact contacts[8];
		bool is_nonempty(int i);
		void display_table(void);
		void display_contact_info(std::string index);
	
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void add_contact(void);
		void search_contact(void);
};