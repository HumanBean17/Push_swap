/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_elem2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 18:31:14 by lcrawn            #+#    #+#             */
/*   Updated: 2019/08/30 18:31:23 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_case5(t_ar **a)
{
	rotate_print(a, NULL, ra);
	swap_print(a, NULL, sa);
}

void	sort_case6(t_ar **a)
{
	reverse_rotate_print(a, NULL, rra);
	swap_print(a, NULL, sa);
}
