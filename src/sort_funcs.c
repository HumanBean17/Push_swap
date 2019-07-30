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
	median = median_search2(*a);
	while ((pushed - *left > 3 && (*a)->pos == 0) || ((*a)->pos == 0 && flag == 0))
		if (partition_len(*b) < 3 && partition_len(*a) == 1 &&
		    (*a)->num < max3)
			till_sort_case1(a, b, left);
		else if (go_back(*a, median) && (*a)->num >= median && count > 0)
			till_sort_case2(a, b, &count);
		else if (is_lower_med(*a, median) && (*a)->num >= median)
			till_sort_case3(a, b, &count);
		else if ((*a)->num < median)
			till_sort_case4(a, b, left);
		else if (partition_len(*a) > 3)
			median = till_sort_case5(a, b, &flag);
		else
			break;
	while (count--)
		reverse_rotate_print(a, b, rra);
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
	if (sorted_part(*a, 0))
		return ;
	if (pushed < 4)
		sort_push(a, b);
	else
	{
		while (partition_len(*a) > 3 && !sorted_part(*a, 0))
			till_sort(a, b, pushed, &left);
		if (*b)
			(*b)->pos = 0;
		sort_push(a, b);
	}
	if (*b)
		(*b)->pos = 0;
}

void    push_till_3(t_ar **a, t_ar **b)
{
	int     len;
	int     pushed;
	int     median;

	len = stack_len(*a);
	pushed = 0;
	median = median_search(*a);
	while (len - pushed > 3)
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
			median = median_search(*a);
		}
	sort_part_a(a);
	(*a)->pos = 1;
}

void    sort_push(t_ar **a, t_ar **b)
{
	t_ar *tmp;

	tmp = *a;
	if (partition_len(tmp) < 3)
	{
		less_three(tmp, a, b);
		return ;
	}
	if (tmp->num < tmp->next->num && tmp->next->num < tmp->next->next->num)
	{
		(*a)->pos = 1;
		return ;
	}
	else if (tmp->num > tmp->next->num && tmp->next->num > tmp->next->next->num)
		sort_case1(a, b);
	else if (tmp->num > tmp->next->num && tmp->next->num < tmp->next->next->num &&
	tmp->num < tmp->next->next->num)
		swap_print(a, b, sa);
	else if (tmp->num < tmp->next->num && tmp->next->num > tmp->next->next->num &&
	tmp->num > tmp->next->next->num)
		sort_case2(a, b);
	else if (tmp->num < tmp->next->num && tmp->next->num > tmp->next->next->num)
		sort_case3(a, b);
	else if (tmp->num > tmp->next->num && tmp->next->num < tmp->next->next->num)
		sort_case4(a, b);
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
		sort_case5(a);
	else
		sort_case6(a);
	(*a)->pos = 1;
}