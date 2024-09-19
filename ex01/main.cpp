#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie;

	zombie = zombieHorde(5, "ZombieHeap");
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Zombie " << i + 1 << ": ";
		zombie[i].announce();
	}
	delete[] zombie;
	return (0);
}