#include "push_swap.h"

int     sort_check(t_ar *a)
{
	int n;

	n = a->num;
	a = a->next;
	while (a)
	{
		if (a->num < n)
			return (0);
		n = a->num;
		a = a->next;
	}
	return (1);
}

int     three_elem_sorted(t_ar **a)
{
	t_ar    *tmp;
	int     c;
	int     n;

	if (!(*a)->next)
		return (0);
	c = 0;
	tmp = *a;
	n = tmp->num;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->num > n)
			c++;
		n = tmp->num;
		tmp = tmp->next;
	}
	if (c == stack_len(*a) - 1)
		return (0);
	return (1);
}

int sorted_part(t_ar *a, int flag)
{
	t_ar    *tmp;
	int     c;
	int     n;

	if (!a->next)
		return (1);
	c = 0;
	tmp = a;
	n = tmp->num;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->num > n)
			c++;
		n = tmp->num;
		tmp = tmp->next;
	}
	if (c == partition_len(a) - flag)
		return (1);
	return (0);
}