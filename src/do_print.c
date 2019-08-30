/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 20:55:19 by lcrawn            #+#    #+#             */
/*   Updated: 2019/08/30 20:55:24 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_print(t_ar **a, t_ar **b, char *line)
{
	if (!ft_strcmp(line, rra) && (*a))
	{
		ft_putstr("rra\n");
		shift_down(a);
	}
	else if (!ft_strcmp(line, rrb) && (*b))
	{
		ft_putstr("rrb\n");
		shift_down(b);
	}
	else if (!ft_strcmp(line, rrr))
	{
		ft_putstr("rrr\n");
		shift_down(a);
		shift_down(b);
	}
}

void	rotate_print(t_ar **a, t_ar **b, char *line)
{
	if (!ft_strcmp(line, ra) && (*a))
	{
		ft_putstr("ra\n");
		shift_up(a);
	}
	else if (!ft_strcmp(line, rb) && (*b))
	{
		ft_putstr("rb\n");
		shift_up(b);
	}
	else if (!ft_strcmp(line, rr))
	{
		ft_putstr("rr");
		shift_up(a);
		shift_up(b);
	}
}

void	push_print(t_ar **a, t_ar **b, char *line)
{
	if (!ft_strcmp(line, pa) && (*b))
	{
		ft_putstr("pa\n");
		push_front(a, (*b)->num);
		delone(b, (*b));
	}
	else if (!ft_strcmp(line, pb) && (*a))
	{
		ft_putstr("pb\n");
		push_front(b, (*a)->num);
		delone(a, (*a));
	}
}

void	swap_print(t_ar **a, t_ar **b, char *line)
{
	if (!ft_strcmp(line, sa) && (*a))
	{
		ft_putstr("sa\n");
		do_swap(a);
	}
	else if (!ft_strcmp(line, sb) && (*b))
	{
		ft_putstr("sb\n");
		do_swap(b);
	}
	else if (!ft_strcmp(line, ss))
	{
		ft_putstr("ss\n");
		do_swap(a);
		do_swap(b);
	}
}
