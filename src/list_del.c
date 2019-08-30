/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 18:41:22 by lcrawn            #+#    #+#             */
/*   Updated: 2019/08/30 18:41:29 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delone(t_ar **begin, t_ar *to_del)
{
	t_ar	*tmp;
	t_ar	*cp;

	tmp = *begin;
	if (!tmp || !to_del)
		return ;
	if (tmp == to_del)
	{
		*begin = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp->next != to_del)
		tmp = tmp->next;
	cp = tmp->next;
	if (tmp->next != NULL && (tmp->next)->next == NULL)
	{
		tmp->next = NULL;
		free(cp);
	}
	else
	{
		tmp->next = (tmp->next)->next;
		free(cp);
	}
}

int		iminlovewithnormes(int *ar, int len)
{
	int i;

	i = ar[len / 2];
	free(ar);
	return (i);
}
