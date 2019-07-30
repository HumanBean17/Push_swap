#include "push_swap.h"

t_ar    *store_list(int argc, char **argv)
{
	t_ar    *head;
	int     num;
	int     i;

	i = 1;
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

t_ar    *new_elem(int data)
{
	t_ar *tmp;

	tmp = (t_ar *)malloc(sizeof(t_ar));
	tmp->num = data;
	tmp->next = NULL;
	tmp->pos = 0;
	return (tmp);
}