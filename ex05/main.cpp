#include "Harl.hpp"

int main()
{
	Harl debugger;

	std::cout << "DEBUG" << std::endl;
	debugger.complain("DEBUG");
	std::cout << "INFO" << std::endl;
	debugger.complain("INFO");
	std::cout << "WARNING" << std::endl;
	debugger.complain("WARNING");
	std::cout << "ERROR" << std::endl;
	debugger.complain("ERROR");
}