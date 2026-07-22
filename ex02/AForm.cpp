#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	
	std::cout << "AForm parameter constructor called" << std::endl;
	
}

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned),
       	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm assignment operator called" << std::endl;
	
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& AForm)
{
	if (AForm.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if(!_isSigned)
		throw FormNotSignedException();
	if(executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade is too low";
}
const char* AForm::FormNotSignedException::what() const throw()
{
	return "AForm is not signed";
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
	out << "AForm " << AForm.getName()
		<< ", signed: " << (AForm.getIsSigned() ? "yes" : "no")
		<< ", grade to sign: " << AForm.getGradeToSign()
		<< " grade to execute: " << AForm.getGradeToExecute() << ".";
	return out;
}
