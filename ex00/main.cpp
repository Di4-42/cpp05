#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat boss("Boss", 0);
	} 
	catch (std::exception& e) //hérite de std::exception
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat apayot("Apayot", 151);
		std::cout << apayot << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat namee("Namee", 47);
		std::cout << namee << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}