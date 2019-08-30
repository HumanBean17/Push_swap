/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_conditions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 18:27:14 by lcrawn            #+#    #+#             */
/*   Updated: 2019/08/30 18:28:11 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_condition(t_ar *tmp, int flag)
{
	if (flag == 1 && tmp->num > tmp->next->num &&
		tmp->next->num > tmp->next->next->num)
		return (1);
	else if (flag == 2 && tmp->num > tmp->next->num &&
		tmp->next->num < tmp->next->next->num &&
		tmp->num < tmp->next->next->num)
		return (1);
	else if (flag == 3 && tmp->num < tmp->next->num &&
		tmp->next->num > tmp->next->next->num &&
		tmp->num > tmp->next->next->num)
		return (1);
	else if (flag == 4 && tmp->num < tmp->next->num &&
		tmp->next->num > tmp->next->next->num)
		return (1);
	else if (flag == 5 && tmp->num > tmp->next->num &&
		tmp->next->num < tmp->next->next->num)
		return (1);
	return (0);
}
