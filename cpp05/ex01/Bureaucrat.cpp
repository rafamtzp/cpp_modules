#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(150){};
Bureaucrat::~Bureaucrat(){};
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade){};


Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		grade = other.grade;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& ofs, const Bureaucrat& obj)
{
	return (ofs <<obj.getName()<<", bureaucrat grade "<<obj.getGrade()<<".");
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error. This grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error. This grade is too low!");
}

const std::string&	Bureaucrat::getName() const {return (name);}

int	Bureaucrat::getGrade() const {return (grade);}

void	Bureaucrat::incrementGrade()
{
	if (grade > 1)
		grade--;
	else
		throw (GradeTooHighException());
}

void	Bureaucrat::decrementGrade()
{
	if (grade < 150)
		grade++;
	else
		throw (GradeTooLowException());
}

//ex01
void	Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << name << " signed " << f.getName() << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << name << " couldn't sign " << f.getName()
		<< " because " << "this grade is too low." << std::endl;
	}
}



