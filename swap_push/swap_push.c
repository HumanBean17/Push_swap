/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 20:53:23 by lcrawn            #+#    #+#             */
/*   Updated: 2019/08/30 20:53:32 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		print_exit(69);
	else if (argc == 2 && argv[1][0] != '0' && ft_atoi(argv[1]) == 0)
		print_exit(0);
	sort(argc, argv);
	print_exit(69);
}
