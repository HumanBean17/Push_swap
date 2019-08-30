/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 18:28:17 by lcrawn            #+#    #+#             */
/*   Updated: 2019/08/30 18:28:57 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_ar **a, t_ar **b, char *line)
{
	if (!ft_strcmp(line, rra) && (*a))
		shift_down(a);
	else if (!ft_strcmp(line, rrb) && (*b))
		shift_down(b);
	else if (!ft_strcmp(line, rrr))
	{
		shift_down(a);
		shift_down(b);
	}
}

void	rotate(t_ar **a, t_ar **b, char *line)
{
	if (!ft_strcmp(line, ra) && (*a))
		shift_up(a);
	else if (!ft_strcmp(line, rb) && (*b))
		shift_up(b);
	else if (!ft_strcmp(line, rr))
	{
		shift_up(a);
		shift_up(b);
	}
}

void	push(t_ar **a, t_ar **b, char *line)
{
	if (!ft_strcmp(line, pa) && (*b))
	{
		push_front(a, (*b)->num);
		delone(b, (*b));
	}
	else if (!ft_strcmp(line, pb) && (*a))
	{
		push_front(b, (*a)->num);
		delone(a, (*a));
	}
}

void	swap(t_ar **a, t_ar **b, char *line)
{
	if (!ft_strcmp(line, sa) && (*a))
		do_swap(a);
	else if (!ft_strcmp(line, sb) && (*b))
		do_swap(b);
	else if (!ft_strcmp(line, ss))
	{
		do_swap(a);
		do_swap(b);
	}
}
