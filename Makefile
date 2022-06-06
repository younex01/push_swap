NAME = push_swap
BONUS_NAME = checker
SRC = push_swap.c push_swap_utils.c push_swap_prep.c ps_operations.c ps_operations_2.c stack_structure.c sort_stacks_for_three.c sort_stack_for_five.c sort_stack_ultimate.c sort_stack_ultimateX2.c
BNS_SRC = checker.c checker_utils.c push_swap_utils.c ft_strncmp.c get_next_line.c get_next_line_utils.c push_swap_prep.c ps_operations_Bonus.c ps_operations_2_Bonus.c stack_structure.c
OBJS = ${SRC:.c=.o}
BOBJ = ${BNS_SRC:.c=.o}
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "Compiling Successfull"

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(BOBJ)
	@$(CC) $(CFLAGS) $(BNS_SRC) -o $(BONUS_NAME)
	@echo "Compiling Successfull"

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(BOBJ)
	@echo "Object Files Removed Successfully"

fclean:clean
	@$(RM) all
	@echo "Clear"

re: fclean all

.PHONY: all, clean, fclean, re, bonus