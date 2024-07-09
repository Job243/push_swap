CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC_PATH = src/
OBJ_PATH = obj/
LIBFT = ./libft/libft.a

SRC = push_swap.c \
      input_check.c input_check_utils.c \
      initialization.c \
      list.c \
      swap.c push.c rotate.c reverse_rotate.c \
      sort_three.c sort.c \
      position.c cost.c do_move.c \
      utils.c ft_split.c
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
INCS = -I ./includes/ -Ilibft

# Default target
all: $(OBJ_PATH) $(NAME)

# Rule to create object files
$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH) $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

# Ensure object directory exists
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

# Linking the final executable
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

# Clean object files
clean:
	rm -rf $(OBJ_PATH)/
	make -C libft clean

# Clean object files and the executable
fclean: clean
	rm -f $(NAME)/
	make -C libft fclean

# Rebuild the project
re: fclean all

test2:				$(NAME)
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l


.PHONY: all clean fclean re test2 test3 test5 test100 test500 test1000

