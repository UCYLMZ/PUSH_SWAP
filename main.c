#include "push_swap.h"

int	main(int ac, char **av)
{
	char	*data;

	if (ac == 1)
	{
		printf("Wrong Argument Count!");
		return (1);
	}
	data = all_in_one(ac - 1, av + 1);
	printf("%s\n", data);
	char_check(data);
}
