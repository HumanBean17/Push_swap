#include "push_swap.h"

int    num_check(char *line)
{
	long int num;

	if (line[0] == '-' && line[1] != '0' && (num = ft_atoi(line)) == 0)
			print_exit(0);
	else if (line[0] != '0' && (num = ft_atoi(line)) == 0)
			print_exit(0);
	num = ft_atoi(line);
	return ((int)num);
}

int     rule_check(char *line)
{
	if (!ft_strcmp(line, sa) || !ft_strcmp(line, sb) ||
	!ft_strcmp(line, ss) || !ft_strcmp(line, pa) ||
	!ft_strcmp(line, pb) || !ft_strcmp(line, ra) ||
	!ft_strcmp(line, rb) || !ft_strcmp(line, rb) ||
	!ft_strcmp(line, rr) || !ft_strcmp(line, rra) ||
	!ft_strcmp(line, rrb) || !ft_strcmp(line, rrr))
		return (1);
	print_exit(0);
	return (0);
}