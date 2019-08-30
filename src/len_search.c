/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 18:41:52 by lcrawn            #+#    #+#             */
/*   Updated: 2019/08/30 18:42:07 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition_len(t_ar *a)
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

int	stack_len(t_ar *a)
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
