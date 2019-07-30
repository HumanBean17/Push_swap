#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define sa "sa"
#define sb "sb"
#define ss "ss"
#define pa "pa"
#define pb "pb"
#define ra "ra"
#define rb "rb"
#define rr "rr"
#define rra "rra"
#define rrb "rrb"
#define rrr "rrr"

#include "get_next_line.h"
#include <limits.h>

typedef struct  s_ar
{
	int         num;
	int         pos;
	struct s_ar *next;
}               t_ar;

void    print_clr_lst(t_ar *a, t_ar *b);
int     go_back(t_ar *a, int median);
int     sorted_part(t_ar *a);
void    sort_push(t_ar **a, t_ar **b);
int     median_search_alt_2(t_ar *a);
void    sort_part_b(t_ar **a, t_ar **b);
int     partition_len(t_ar *a);
int     is_lower_med(t_ar *a, int med);
void    sort_two(t_ar **a);
int     max_search(t_ar *a);
void    divide_and_rule(t_ar **a, t_ar **b);
void    push_it_to_the_limit(t_ar **a, t_ar **b);
void    push_till_3(t_ar **a, t_ar **b);
int     sort_check(t_ar *a);
void    reverse_rotate_print(t_ar **a, t_ar **b, char *line);
void    rotate_print(t_ar **a, t_ar **b, char *line);
void    push_print(t_ar **a, t_ar **b, char *line);
void    swap_print(t_ar **a, t_ar **b, char *line);
int     stack_len(t_ar *a);
int     median_search_alt(t_ar *a);
int     median_search(t_ar *a);
void sort_part_a(t_ar **a);
void    sort(int argc, char **argv);
void    reverse_rotate(t_ar **a, t_ar **b, char *line);
void    rotate(t_ar **a, t_ar **b, char *line);
void	delone(t_ar **begin, t_ar *to_del);
void    push_back(t_ar **alst, int data);
void    push_front(t_ar **alst, int data);
t_ar    *new_elem(int data);
void    shift_down(t_ar **a);
void    shift_up(t_ar **a);
void    push(t_ar **a, t_ar **b, char *line);
int find_letter(const char *line, char c);
void            check(int argc, char **argv);
void    swap(t_ar **a, t_ar **b, char *line);
void            do_swap(t_ar **alst);
void operation_choose(t_ar **a, t_ar **b, char *line);
int             num_check(char *line);
int             rule_check(char *line);
void print_list(t_ar *a, t_ar *b);
void            print_exit(int flag);
void    print_parts(t_ar *a, t_ar *b);
t_ar            *store_list(int argc, char **argv);

#endif
