NAME = push_swap.a
SRC = push_swap.c push_swap_utils.c push_swap_prep.c ps_operations.c ps_operations_2.c stack_structure.c sort_stacks_for_three.c sort_stack_for_five.c sort_stack_ultimate.c
OBJS = $(SRC:.c=.o)
CC = cc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror

all:$(NAME)

%.o = %.c push_swap.h
		$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)
fclean: clean
		$(RM) $(NAME)
re: fclean $(NAME)

.PHONY = all clean fclean re