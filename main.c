#include "push_swap.h"

int	main(int ac, char **av)
{
	char	*data_str;
	int		*data_arr;
	int		size;

	if (ac == 1)
	{
		printf("Wrong Argument Count!");
		return (1);
	}
	data_str = all_in_one(ac - 1, av + 1);
	if (char_check(data_str))
		return (1);
	data_arr = to_arr(data_str, &size);
	if (!data_arr)
		return (2);
	if (check_doubles(data_arr, size))
		return (1);
}
