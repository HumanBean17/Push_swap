/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 18:31:41 by lcrawn            #+#    #+#             */
/*   Updated: 2019/08/30 18:31:44 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	less_three(t_ar *tmp, t_ar **a, t_ar **b)
{
	if (tmp && tmp->next && tmp->num > tmp->next->num)
		swap_print(a, b, sa);
	(*a)->pos = 1;
}

void	sort_case1(t_ar **a, t_ar **b)
{
	swap_print(a, b, sa);
	rotate_print(a, b, ra);
	rotate_print(a, b, ra);
	push_print(a, b, pb);
	reverse_rotate_print(a, b, rra);
	reverse_rotate_print(a, b, rra);
	push_print(a, b, pa);
}

void	sort_case2(t_ar **a, t_ar **b)
{
	rotate_print(a, b, ra);
	rotate_print(a, b, ra);
	push_print(a, b, pb);
	reverse_rotate_print(a, b, rra);
	reverse_rotate_print(a, b, rra);
	push_print(a, b, pa);
}

void	sort_case3(t_ar **a, t_ar **b)
{
	rotate_print(a, b, ra);
	swap_print(a, b, sa);
	reverse_rotate_print(a, b, rra);
}

void	sort_case4(t_ar **a, t_ar **b)
{
	push_print(a, b, pb);
	rotate_print(a, b, ra);
	rotate_print(a, b, ra);
	push_print(a, b, pa);
	reverse_rotate_print(a, b, rra);
	reverse_rotate_print(a, b, rra);
}
