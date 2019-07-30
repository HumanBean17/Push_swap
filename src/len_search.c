#include "push_swap.h"

int     partition_len(t_ar *a)
{
	int len;

	len = 0;
	while (a && a->pos == 0)
	{
		len++;
		a = a->next;
	}
	return (len);
}

int     stack_len(t_ar *a)
{
	int len;

	len = 0;
	while (a)
	{
		a = a->next;
		len++;
	}
	return (len);
}