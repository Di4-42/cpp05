#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a;
	Bureaucrat b("Bob", 42);
	Bureaucrat c(b);
	return(0);
}
