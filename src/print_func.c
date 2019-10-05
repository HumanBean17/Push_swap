/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 18:38:24 by lcrawn            #+#    #+#             */
/*   Updated: 2019/10/05 15:50:10 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_exit(int flag)
{
	if (flag == 0)
		ft_putstr("\x1b[31mError\x1b[0m\n");
	else if (flag == 1)
		ft_putstr("\x1b[32mOK\x1b[0m\n");
	else if (flag == 2)
		ft_putstr("\x1b[31mKO\x1b[0m\n");
	exit(0);
}

void	print_parts(t_ar *a, t_ar *b)
{
	ft_putstr("-------------------------\n");
	while (b)
	{
		if (b->pos == 0)
			ft_printf("%d ", b->num);
		else
			ft_printf("|| %d ", b->num);
		b = b->next;
	}
	ft_putstr("\n++++++++++++++++++++++++++\n");
	while (a)
	{
		if (a->pos == 0)
			ft_printf("%d ", a->num);
		else
			ft_printf("|| %d ", a->num);
		a = a->next;
	}
	write(1, "\n", 1);
}

int		part_check(t_ar *a)
{
	int index;
	int i;

	i = 0;
	index = 0;
	while (a)
	{
		if (a->pos == 1)
			index = i;
		a = a->next;
		i++;
	}
	return (index);
}

void print_list(t_ar *a, t_ar *b)
{
	if (g_printshift != 2)
		return ;
	ft_printf("%s-------------------------%s\n", YELLOW, ESCAPE);
	while (a || b)
	{
		if (a)
			ft_printf("%s%-5d%s", GREEN, a->num, ESCAPE);
		else
			ft_putstr("     ");
		if (b)
			ft_printf("%s%d%s\n", RED, b->num, ESCAPE);
		else
			write(1, "\n", 1);
		if (b)
			b = b->next;
		if (a)
			a = a->next;
	}
	write(1, "\n", 1);
}
