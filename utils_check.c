#include "push_swap.h"

int	char_check(char *data)
{
	while (*data)
	{
		if ((*data < '0' || *data > '9') && *data != ' '
			&& (*data != '+' && *data != '-'))
			printf("%c", *data);
		data++;
	}
}
