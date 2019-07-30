COMMON_SRC = src/*.c

CHECKER_SRC = check/*.c

CHECKER_NAME = checker

PUSH_SWAP_SRC = swap_push/*.c

PUSH_SWAP_NAME = push_swap

HDR = includes/

LIBFT = libft/

LIBFT_A = libft/libft.a

CC = gcc

all: $(CHECKER_NAME) $(PUSH_SWAP_NAME)

$(CHECKER_NAME):
	make -C $(LIBFT)
	$(CC) $(CHECKER_SRC) $(COMMON_SRC) -I $(HDR) -o $(CHECKER_NAME) -L. $(LIBFT_A)

$(PUSH_SWAP_NAME):
	make -C $(LIBFT)
	$(CC) $(PUSH_SWAP_SRC) $(COMMON_SRC) -I $(HDR) -o $(PUSH_SWAP_NAME) -L. $(LIBFT_A)

clean:
	make -C $(LIBFT) clean

fclean:
	rm -f $(CHECKER_NAME)
	rm -f $(PUSH_SWAP_NAME)
	make -C $(LIBFT)

re: fclean all