#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// canonical form
ShrubberyCreationForm::ShrubberyCreationForm(): 
AForm("", 145, 137), target(""){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
AForm("", 145, 137), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()),
target(other.target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (AForm::canBeExecuted(executor))
	{
		std::ofstream file((target + "_shrubbery").c_str());
	
		file <<"          &&& &&  & &&\n";
		file <<"       && &\\/&\\|& ()|/ @, &&\n";
		file <<"       &\\/(/&/&||/& /_/)_&/_&\n";
		file <<"    &() &\\/&|()|/&\\/ '%\" & ()\n";
		file <<"   &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
		file <<" &&   && & &| &| /& & % ()& /&&\n";
		file <<"  ()&_---()&\\&\\|&&-&&--%---()~\n";
		file <<"      &&     \\|||";
		file <<"              |||";
		file <<"              |||";
		file <<"              |||";
		file <<"        , -=-~  .-^- _\n";
	
		file.close();
		return ;
	}
	throw AForm::GradeTooLowException();
}