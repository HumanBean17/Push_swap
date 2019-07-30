#include "push_swap.h"

void    till_sort(t_ar **a, t_ar **b, int pushed, int *left)
{
	int flag;
	int median;
	int count;
	int max3;

	flag = 0;
	count = 0;
	max3 = max_search(*a);
	median = median_search_alt_2(*a);
	while ((pushed - *left > 3 && (*a)->pos == 0) || ((*a)->pos == 0 && flag == 0))
	{
		//printf("pushed %d left %d flag %d count %d\n", pushed, *left, flag, count);
		//printf("median = %d\n", median);
		//printf("max %d b_len %d a_len %d\n", max3, partition_len(*b), partition_len(*a));
		//print_parts(*a, *b);
		if (partition_len(*b) < 3 && partition_len(*a) == 1 &&
				(*a)->num < max3)
		{
			push_print(a, b, pb);
			(*left)++;
		}
		else if (go_back(*a, median) && (*a)->num >= median && count > 0)
		{
			count--;
			reverse_rotate_print(a, b, rra);
		}
		else if (is_lower_med(*a, median) && (*a)->num >= median)
		{
			(count)++;
			rotate_print(a, b, ra);
		}
		else if ((*a)->num < median)
		{
			(*left)++;
			(*a)->pos = 0;
			push_print(a, b, pb);
		}
		else if (partition_len(*a) > 3)
		{
			(*b)->pos = 1;
			flag = 1;
			median = median_search_alt_2(*a);
		}
		else
			break;
		//print_parts(*a, *b);
	}
	//printf("gonna reverse rotate\n");
	while (count--)
	{
		reverse_rotate_print(a, b, rra);
	}
	if (*b)
		(*b)->pos = 0;
}

void    push_it_to_the_limit(t_ar **a, t_ar **b)
{
	int pushed;
	int left;

	left = 0;
	pushed = 0;
	while ((*b) && (*b)->pos == 0)
	{
		pushed++;
		push_print(a, b, pa);
	}
	if (sorted_part(*a))
		return ;
	if (pushed < 4)
		sort_push(a, b);
	else
	{
		while (partition_len(*a) > 3 && !sorted_part(*a))
		{
			till_sort(a, b, pushed, &left);
			//print_parts(*a, *b);
		}
		//printf("fuck this shit im out\n");
		sort_push(a, b);
	};
	if (*b)
		(*b)->pos = 0;
	//print_parts(*a, *b);
}

void    push_till_3(t_ar **a, t_ar **b)
{
	int     len;
	int     pushed;
	int     median;

	len = stack_len(*a);
	pushed = 0;
	median = median_search_alt(*a);
	while (len - pushed > 3)
	{
		//printf("median = %d\n", median);
		if (is_lower_med(*a, median) && (*a)->num >= median)
			rotate_print(a, b, ra);
		else if ((*a)->num < median)
		{
			push_print(a, b, pb);
			pushed++;
		}
		else
		{
			(*b)->pos = 1;
			median = median_search_alt(*a);
		}
		//print_parts(*a, *b);
	}
	sort_part_a(a);
	(*a)->pos = 1;
	//print_parts(*a, *b);
}

int     stack_len(t_ar *a)
{
	int len;

	len = 0;
	while (a)
	{
		a = a->next;
		len++;
	}
	return (len);
}

int     sorted_part(t_ar *a)
{
	t_ar    *tmp;
	int     c;
	int     n;

	if (!a->next)
		return (0);
	c = 0;
	tmp = a;
	n = tmp->num;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->num > n)
			c++;
		n = tmp->num;
		tmp = tmp->next;
	}
	if (c == partition_len(a))
		return (1);
	return (0);
}


int     three_elem_sorted(t_ar **a)
{
	t_ar    *tmp;
	int     c;
	int     n;

	if (!(*a)->next)
		return (0);
	c = 0;
	tmp = *a;
	n = tmp->num;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->num > n)
			c++;
		n = tmp->num;
		tmp = tmp->next;
	}
	if (c == stack_len(*a) - 1)
		return (0);
	return (1);
}

void    sort_push(t_ar **a, t_ar **b)
{
	t_ar *tmp;

	tmp = *a;
	if (partition_len(tmp) < 3)
	{
		if (tmp && tmp->next && tmp->num > tmp->next->num)
			swap_print(a, b, sa);
		(*a)->pos = 1;
		return ;
	}
	if (tmp->num < tmp->next->num && tmp->next->num < tmp->next->next->num)
	{
		(*a)->pos = 1;
		return ;
	}
	else if (tmp->num > tmp->next->num && tmp->next->num > tmp->next->next->num)
	{
		swap_print(a, b, sa);
		rotate_print(a, b, ra);
		rotate_print(a, b, ra);
		push_print(a, b, pb);
		reverse_rotate_print(a, b, rra);
		reverse_rotate_print(a, b, rra);
		push_print(a, b, pa);
	}
	else if (tmp->num > tmp->next->num && tmp->next->num < tmp->next->next->num &&
	tmp->num < tmp->next->next->num)
		swap_print(a, b, sa);
	else if (tmp->num < tmp->next->num && tmp->next->num > tmp->next->next->num &&
	tmp->num > tmp->next->next->num)
	{
		rotate_print(a, b, ra);
		rotate_print(a, b, ra);
		push_print(a, b, pb);
		reverse_rotate_print(a, b, rra);
		reverse_rotate_print(a, b, rra);
		push_print(a, b, pa);
	}
	else if (tmp->num < tmp->next->num && tmp->next->num > tmp->next->next->num)
	{
		rotate_print(a, b, ra);
		swap_print(a, b, sa);
		reverse_rotate_print(a, b, rra);
	}
	else if (tmp->num > tmp->next->num && tmp->next->num < tmp->next->next->num)
	{
		push_print(a, b, pb);
		rotate_print(a, b, ra);
		rotate_print(a, b, ra);
		push_print(a, b, pa);
		reverse_rotate_print(a, b, rra);
		reverse_rotate_print(a, b, rra);
	}
	(*a)->pos = 1;
}

void    sort_part_a(t_ar **a)
{
	t_ar    *tmp;

	if (!three_elem_sorted(a))
		return ;
	tmp = *a;
	if (stack_len(tmp) == 2 && !sort_check(*a))
		swap_print(a, NULL, sa);
	else if (tmp->num > tmp->next->num &&
	tmp->next->num < tmp->next->next->num)
		rotate_print(a, NULL, ra);
	else if (tmp->num > tmp->next->num &&
	tmp->next->num < tmp->next->next->num)
		swap_print(a, NULL, sa);
	else if (tmp->num < tmp->next->num &&
	tmp->next->num > tmp->next->next->num && tmp->num > tmp->next->next->num)
		reverse_rotate_print(a, NULL, rra);
	else if (tmp->num > tmp->next->num &&
	tmp->next->num > tmp->next->next->num)
	{
		rotate_print(a, NULL, ra);
		swap_print(a, NULL, sa);
	}
	else
	{
		reverse_rotate_print(a, NULL, rra);
		swap_print(a, NULL, sa);
	}
	(*a)->pos = 1;
}