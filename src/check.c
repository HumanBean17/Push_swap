#include "push_swap.h"

void    no_repeat(t_ar *a)
{
	t_ar *tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->num == a->num)
				print_exit(0);
			tmp = tmp->next;
		}
		a = a->next;
	}
}

void    check(int argc, char **argv)
{
	char *line;
	t_ar *a = NULL;
	t_ar *b = NULL;

	a = store_list(argc, argv);
	while (get_next_line(0, &line))
	{
		rule_check(line);
		operation_choose(&a, &b, line);
		ft_strdel(&line);
	}
	if (b == NULL && sort_check(a) == 1)
		print_exit(1);
	else
		print_exit(2);
}

void    operation_choose(t_ar **a, t_ar **b, char *line)
{
	if (find_letter(line, 's'))
		swap(a, b, line);
	else if (find_letter(line, 'p'))
		push(a, b, line);
	else if (!ft_strcmp(line, ra) || !ft_strcmp(line, rb) ||
	!ft_strcmp(line, rr))
		rotate(a, b, line);
	else if (!ft_strcmp(line, rra) || !ft_strcmp(line, rrb) ||
	!ft_strcmp(line, rrr))
		reverse_rotate(a, b, line);
}

int     find_letter(const char *line, char c)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			return (1);
		i++;
	}
	return (0);
}