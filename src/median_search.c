#include "push_swap.h"

int     go_back(t_ar *a, int median)
{
	while (a && a->pos == 0)
		a = a->next;
	while (a)
	{
		if (a->num < median)
			return (1);
		a = a->next;
	}
	return (0);
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
	//printf("%ld\n", max1);
	while (a && a->pos == 0)
	{
		if (a->num > max1)
		{
			max3 = max2;
			max2 = max1;
			max1 = a->num;
			//printf("max1 %ld max2 %ld max3 %ld\n", max1, max2, max3);
		}
		else if (a->num < max1 && a->num > max2)
		{
			max3 = max2;
			max2 = a->num;
			//printf("max1 %ld max2 %ld max3 %ld\n", max1, max2, max3);
		}
		else if (a->num < max2 && a->num > max3) {
			max3 = a->num;
			//printf("max1 %ld max2 %ld max3 %ld\n", max1, max2, max3);
		}
		a = a->next;
		i++;
	}
	if (i > 3)
		return (max3);
	else if (i == 2)
		return (max2);
	return (max1);
}


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

int     is_lower_med(t_ar *a, int med)
{
	while (a && a->pos == 0)
	{
		if (a->num < med)
			return (1);
		a = a->next;
	}
	return (0);
}

int     *list_cpy(t_ar *a)
{
	int *m;
	int i;

	m = (int *)malloc(sizeof(int) * stack_len(a));
	i = 0;
	while (a)
	{
		m[i] = a->num;
		a = a->next;
		i++;
	}
	return (m);
}

int     median_search_alt_2(t_ar *a)
{
	int *ar;
	int len;
	int i;
	int j;
	int c;

	len = partition_len(a);
	ar = list_cpy(a);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (ar[i] > ar[j])
			{
				c = ar[i];
				ar[i] = ar[j];
				ar[j] = c;
			}
			j++;
		}
		i++;
	}
	i = ar[len / 2];
	free(ar);
	return (i);
}

int     median_search_alt(t_ar *a)
{
	int *ar;
	int len;
	int i;
	int j;
	int c;

	len = stack_len(a);
	ar = list_cpy(a);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (ar[i] > ar[j])
			{
				c = ar[i];
				ar[i] = ar[j];
				ar[j] = c;
			}
			j++;
		}
		i++;
	}
	i = ar[len / 2];
	free(ar);
	return (i);
}