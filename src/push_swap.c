#include "push_swap.h"

void    sort(int argc, char **argv)
{
	t_ar    *a;
	t_ar    *b;
	int     len;

	b = NULL;
	a = store_list(argc, argv);
	if (sort_check(a))
		print_exit(69);
	len = stack_len(a);
	push_till_3(&a, &b);
	sort_part_a(&a);
	while (stack_len(a) != len)
		push_it_to_the_limit(&a, &b);
}