#include "push_swap.h"

static void    max_case_1(t_ar *a, long int *max1, long int *max2,
		long int *max3)
{
	*max3 = *max2;
	*max2 = *max1;
	*max1 = a->num;
}

static void    max_case_2(t_ar *a, long int *max2,
		long int *max3)
{
	*max3 = *max2;
	*max2 = a->num;
}

int     max_search(t_ar *a)
{
	int         i;
	long int    max1;
	long int    max2;
	long int    max3;

	i = 0;
	max1 = (long int)(INT_MIN) - 2;
	max2 = max1;
	max3 = max1;
	while (a && a->pos == 0)
	{
		if (a->num > max1)
			max_case_1(a, &max1, &max2, &max3);
		else if (a->num < max1 && a->num > max2)
			max_case_2(a, &max2, &max3);
		else if (a->num < max2 && a->num > max3)
			max3 = a->num;
		a = a->next;
		i++;
	}
	if (i >= 3)
		return (max3);
	else if (i == 2)
		return (max2);
	return (max1);
}