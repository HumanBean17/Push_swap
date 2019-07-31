# push_swap
swap push isn't natural

In this project I can use only 2 stacks and these commands to operate with them :

Rotating commands
RA - rotate stack A (send top number on stack to bottom)
RB - rotate stack B (send top number on stack to bottom)
RR - rotate both stack A and B at the same time
RRA - counter-rotate stack A (send bottom number of stack to top)
RRB - counter-rotate stack B (send bottom number of stack to top)
RRR - counter-rotate stack A and stack B at the same time

Swapping commands
SA - swap top two numbers at top of stack A
SB - swap top two numbers at top of stack B

Pushing commands
PA - push top element from stack A onto stack B
PB - push stack B

Using only them I need to sort numbers in to sort a stack of numbers using another stack in the least commands possible.

Usage:
1. Make
2. ./push_swap list_of_numbers | ./checker list_of_numbers

I used quicksort algorithm to sort my stack.

1. Find median in stack A and push all numbers lower to stack B. If there're no numbers lower than the median and there'are still more than 3 elems in stack A, find new median and set partition in stack B.
   Repeat (1) untill there will only 3 elems left in stack A, then sort them and set partition which means that all elems are sorted after this partition.
2. Push all elems before partition from stack B to stack A.
   If more than 3 elems were pushed, find median and repeat (1) untill 3 elems left before last A partition.
   Else sort them using swap, push, rotate commands.
3. Repeat (2) untill A is sorted.
