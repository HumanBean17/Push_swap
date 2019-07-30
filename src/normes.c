#include "push_swap.h"

void    till_sort_case1(t_ar **a, t_ar **b, int *left)
{
	push_print(a, b, pb);
	(*left)++;
}

void    till_sort_case2(t_ar **a, t_ar **b, int *count)
{
	(*count)--;
	reverse_rotate_print(a, b, rra);
}

void    till_sort_case3(t_ar **a, t_ar **b, int *count)
{
	(*count)++;
	rotate_print(a, b, ra);
}

void    till_sort_case4(t_ar **a, t_ar **b, int *left)
{
	(*left)++;
	(*a)->pos = 0;
	push_print(a, b, pb);
}

int    till_sort_case5(t_ar **a, t_ar **b, int *flag)
{
	(*b)->pos = 1;
	(*flag) = 1;
	return (median_search2(*a));
}