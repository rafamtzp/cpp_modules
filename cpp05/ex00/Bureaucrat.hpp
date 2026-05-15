#ifndef	BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat();
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		const std::string&	getName() const;
		int	getGrade() const;
		void	incrementGrade();
		void	decrementGrade();
};

std::ostream&	operator<<(std::ostream& ofs, const Bureaucrat& obj);

#endif