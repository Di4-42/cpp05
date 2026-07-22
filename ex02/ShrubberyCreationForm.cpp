#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream outfile((_target + "_shrubbery"),c_str());

	if (!outfile.is_open())
		throw std::runtime_error("could not create shrubbery file");

	outfile <<
	"                         .-^^^^^^^^^^^^^-.\n"
	"                    .---'                 '---.\n"
	"                 .-'                         '-.\n"
	"                /       )           )           \\\n"
	"               /       ( )         ( )           \\\n"
	"              |       (   )       (   )           |\n"
	"              |      (_____)     (_____)          |\n"
	"              |                                  |\n"
	"              |           )             )         |\n"
	"              |          ( )           ( )        |\n"
	"              |         (   )         (   )       |\n"
	"               \\      (_____)       (_____)      /\n"
	"                '.                             .'\n"
	"                  '---._________________.---'\n"
	"                            ||||||\n"
	"                            ||||||\n"
	"                            ||||||\n"
	"                         ___||||||___\n"
	"                        /____________\\\n";

	outfile.close();

	std::cout <<"Shrubbery file successfully created as " << _target << "_shrubbery" << std::endl;
}

