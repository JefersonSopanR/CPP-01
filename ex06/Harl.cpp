#include "Harl.hpp"

Harl::Harl()
{
	_harld[0].f = &Harl::debug;
	_harld[1].f = &Harl::info;
	_harld[2].f = &Harl::warning;
	_harld[3].f = &Harl::error;
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable. I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int level_index = -1;
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			level_index = i;
			break;
		}
	}
	switch (level_index)
	{
		case 0:
			(this->*_harld[0].f)();
		case 1:
			(this->*_harld[1].f)();
		case 2:
			(this->*_harld[2].f)();
		case 3:
			(this->*_harld[3].f)();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}