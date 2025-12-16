#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int index;
	
	public:
		Contact *contacts;
		PhoneBook(void);
		~PhoneBook(void);
	
};