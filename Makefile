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
			   src/algo/compress.c

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
