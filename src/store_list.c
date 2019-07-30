#include "push_swap.h"

void    shift_down(t_ar **a)
{
	t_ar *tmp;
	t_ar *head;
	t_ar *cur;

	if (!(*a))
		return ;
	tmp = *a;
	head = *a;
	cur = NULL;
	while (tmp->next)
	{
		if (tmp->next->next)
			cur = tmp;
		tmp = tmp->next;
	}
	tmp->next = head;
	(*a) = tmp;
	if (cur)
		cur->next->next = NULL;
	else
		(*a)->next->next = NULL;
}

void    shift_up(t_ar **a)
{
	t_ar *tmp;
	t_ar *head;
	t_ar *cur;

	if (!(*a))
		return ;
	tmp = *a;
	head = (*a)->next;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = (*a);
	(*a)->next = NULL;
	(*a) = head;
}

void    do_swap(t_ar **alst)
{
	t_ar *first;
	t_ar *second;
	t_ar *third;

	if (!(*alst) || !(*alst)->next)
		return ;
	first = *alst;
	second = (*alst)->next;
	third = (*alst)->next->next;
	second->next = (*alst);
	first->next = third;
	(*alst) = second;
}

void    push_front(t_ar **alst, int data)
{
	t_ar *tmp;

	if (!(*alst))
	{
		(*alst) = new_elem(data);
		return ;
	}
	tmp = new_elem(data);
	tmp->next = (*alst);
	(*alst) = tmp;
}

void    push_back(t_ar **alst, int data)
{
	t_ar *tmp;

	if (!(*alst))
	{
		*alst = new_elem(data);
		return ;
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_elem(data);
}

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