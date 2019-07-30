#include "push_swap.h"

int main(int argc, char **argv)
{
	if (argc == 1)
		print_exit(69);
	else if (argc == 2)
		print_exit(1);
	sort(argc, argv);
}