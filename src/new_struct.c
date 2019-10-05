/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 18:39:12 by lcrawn            #+#    #+#             */
/*   Updated: 2019/10/05 16:19:49 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_del(t_ar **head)
{
	t_ar *cur;
	t_ar *tmp;

	tmp = (*head);
	while (tmp)
	{
		cur = tmp;
		tmp = tmp->next;
		free(cur);
	}
}

t_ar 	*store_list(int argc, char **argv)
{
	t_ar	*head;
	int		num;
	int		i;

	i = g_printshift;
	head = NULL;
	while (i < argc)
	{
		num = num_check(argv[i]);
		push_back(&head, num);
		i++;
	}
	no_repeat(head);
	return (head);
}

t_ar	*new_elem(int data)
{
	t_ar *tmp;

	tmp = (t_ar *)malloc(sizeof(t_ar));
	tmp->num = data;
	tmp->next = NULL;
	tmp->pos = 0;
	return (tmp);
}
