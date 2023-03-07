NAME = push_swap

NAME_BONUS = checker

SRCS =	main.c push_swap.c utils_check.c	\
		low_size_handler.c utils_index_b.c	\
		utils_free.c utils_list.c utils.c	\
		utils_swap_push.c utils_split.c		\
		utils_rotate.c utils_r_rotate.c		\

SRCS_BONUS =	./SRC/get_next_line.c 		\
				./SRC/get_next_line_utils.c	\
				main_bonus.c utils_bonus.c	\
				utils_check_bonus.c			\
				utils_list_bonus.c			\
				utils_r_rotate_bonus.c		\
				utils_rotate_bonus.c		\
				utils_split_bonus.c			\
				utils_swap_push_bonus.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(SRCS_BONUS)
	$(CC) $(FLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME_BONUS)
	rm -rf $(NAME)

re: clean all

.PHONY : all re clean fclean bonus