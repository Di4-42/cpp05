#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a;
	Bureaucrat b("aledos", 42);
	Bureaucrat c(b);
	return(0);

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
		Bureaucrat namee("Namee", 47);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}