/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 18:39:12 by lcrawn            #+#    #+#             */
/*   Updated: 2019/10/05 15:48:57 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	ArgvLen(char **argv)
{
	int len;

	len = 0;
	while (argv[len])
		len++;
	return (len);
}

void	ArgvDel(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		ft_strdel(&argv[i]);
		i++;
	}
	free(argv);
}

char **AddFilename(char *filename, char **argv)
{
	char	 **newArgv;
	int 	i;
	int 	c;
	int 	len;

	i = g_printshift;
	c = 0;
	len = ArgvLen(argv);
	newArgv = (char **)ft_memalloc(sizeof(char *) * (len + 3));
	newArgv[0] = ft_strdup(filename);
	newArgv[1] = i == 2 ? ft_strdup("-c") : NULL;
	while (c < len)
	{
		newArgv[i] = ft_strdup(argv[c]);
		i++;
		c++;
	}
	ArgvDel(argv);
	return (newArgv);
}

char **ArgvSplit(int *argc, char **argv)
{
	char **newArgv;
	char **argvWithFilename;

	if ((*argc) < 4)
	{
		newArgv = ft_strsplit(argv[g_printshift], ' ');
		argvWithFilename = AddFilename(argv[0], newArgv);
		(*argc) = ArgvLen(argvWithFilename);
		return (argvWithFilename);
	}
	return (argv);
}

t_ar *store_list(int argc, char **argv)
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
