NAME		:= push_swap
BONUS_NAME	:= checker

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

INCLUDES    := -Iincludes/ -I$(LIBFT_DIR)

SRCS		:= \
			   src/main.c \
			   src/parsing/parse_args.c \
			   src/parsing/parse_one_int.c \
			   src/stack/stack_init.c \
			   src/stack/stack_utils.c \
			   src/algo/compress.c \
			   src/algo/lis.c \
			   src/algo/simple_sort.c \
			   src/algo/push_swap_algo.c \
			   src/algo/cost.c \
			   src/algo/operations.c \
			   src/moves/swap.c \
			   src/moves/push.c \
			   src/moves/rotate.c \
			   src/moves/reverse_rotate.c

OBJS        := $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
