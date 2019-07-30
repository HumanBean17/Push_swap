#include "push_swap.h"

void    print_exit(int flag)
{
	if (flag == 0)
		ft_putstr("Error\n");
	else if (flag == 1)
		ft_putstr("OK\n");
	else if (flag == 2)
		ft_putstr("KO\n");
	exit(0);
}

void    print_parts(t_ar *a, t_ar *b)
{
	printf("-------------------------\n");
	while (b)
	{
		if (b->pos == 0)
			printf("%d ", b->num);
		else
			printf("|| %d ", b->num);
		b = b->next;
	}
	printf("\n++++++++++++++++++++++++++\n");
	while (a)
	{
		if (a->pos == 0)
			printf("%d ", a->num);
		else
			printf("|| %d ", a->num);
		a = a->next;
	}
	printf("\n");
	printf("-------------------------\n");
}

void print_list(t_ar *a, t_ar *b)
{
	printf("-------------------------\n");
	while (a || b)
	{
		if (a)
			printf("%-5d", a->num);
		else
			printf("     ");
		if (b)
			printf("%d\n", b->num);
		else
			printf("\n");
		if (b)
			b = b->next;
		if (a)
			a = a->next;
	}
	printf("-------------------------\n");
}