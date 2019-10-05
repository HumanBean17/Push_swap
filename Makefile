COMMON_SRC = src/check.c \
			src/get_next_line.c \
			src/len_search.c \
			src/max_search.c \
			src/new_struct.c  \
			src/print_func.c   \
			src/sort_3_elem.c   \
			src/sort_check.c     \
			src/sort_funcs.c      \
			src/store_list.c \
            src/do_print.c   \
            src/is_valid.c    \
            src/list_del.c     \
            src/median_search.c \
            src/normes.c         \
            src/push_swap.c       \
            src/sort_3_elem2.c     \
            src/sort_conditions.c   \
            src/spr.c \
            src/argv_func.c

CHECKER_SRC = check/main.c

COMMON_OBJ = ./check.o \
               do_print.o \
               get_next_line.o \
               is_valid.o \
               len_search.o \
               list_del.o \
               max_search.o \
               median_search.o \
               new_struct.o \
               normes.o \
               print_func.o \
               push_swap.o \
               sort_3_elem.o \
               sort_3_elem2.o \
               sort_check.o \
               sort_conditions.o \
               sort_funcs.o \
               spr.o \
               store_list.o \
               argv_func.o


CHECKER_OBJ = ./main.o

PUSH_SWAP_OBJ = ./swap_push.o

CHECKER_NAME = checker

CHECKER_OBJ = ./main.o

PUSH_SWAP_SRC = swap_push/swap_push.c

PUSH_SWAP_NAME = push_swap

HDR = includes/

PRINTF = libftprintf/

PRINTF_A = libftprintf/libftprintf.a

LIBFT = libft/

LIBFT_A = libft/libft.a

CC = gcc -Wall -Wextra -Werror

all: lib $(CHECKER_OBJ) $(PUSH_SWAP_OBJ) $(COMMON_OBJ) $(CHECKER_NAME) $(PUSH_SWAP_NAME)

lib:
	make -C $(PRINTF)
	make -C $(LIBFT)

$(PUSH_SWAP_OBJ): $(PUSH_SWAP_SRC)
	$(CC) -c $(PUSH_SWAP_SRC) -I $(HDR)

$(CHECKER_OBJ): $(CHECKER_SRC)
	$(CC) -c $(CHECKER_SRC) -I $(HDR)

$(COMMON_OBJ): $(COMMON_SRC)
	$(CC) -c $(COMMON_SRC) -I $(HDR)

$(CHECKER_NAME): $(CHECKER_OBJ)
	$(CC) $(CHECKER_SRC) $(COMMON_OBJ) -I $(HDR) -o $(CHECKER_NAME) -L. $(LIBFT_A) $(PRINTF_A)

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJ)
	$(CC) $(PUSH_SWAP_SRC) $(COMMON_OBJ) -I $(HDR) -o $(PUSH_SWAP_NAME) -L. $(LIBFT_A) $(PRINTF_A)

clean:
	rm -f $(COMMON_OBJ)
	rm -f $(PUSH_SWAP_OBJ)
	rm -f $(CHECKER_OBJ)
	make -C $(PRINTF) clean
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(CHECKER_NAME)
	rm -f $(PUSH_SWAP_NAME)
	make -C $(PRINTF) fclean
	make -C $(LIBFT) fclean

re: fclean all
