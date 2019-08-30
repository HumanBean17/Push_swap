/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 18:39:44 by lcrawn            #+#    #+#             */
/*   Updated: 2019/08/30 18:39:49 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		go_back(t_ar *a, int median)
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

int		is_lower_med(t_ar *a, int med)
{
	while (a && a->pos == 0)
	{
		if (a->num < med)
			return (1);
		a = a->next;
	}
	return (0);
}

int		*list_cpy(t_ar *a)
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

int		median_search2(t_ar *a)
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
	return (iminlovewithnormes(ar, len));
}

int		median_search(t_ar *a)
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
	return (iminlovewithnormes(ar, len));
}
