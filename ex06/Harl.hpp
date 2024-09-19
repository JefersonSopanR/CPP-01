#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl;

typedef struct s_harld
{
	void	(Harl::*f)(void);

}			t_harld;

class Harl 
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		t_harld _harld[4];
	
	public:
		Harl();
		~Harl();
		void	complain(std::string level);

};

#endif