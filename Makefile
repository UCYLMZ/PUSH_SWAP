NAME = push_swap
SRCS =	main.c push_swap.c utils_check.c	\
		low_size_handler.c utils_index_b.c	\
		utils_free.c utils_list.c utils.c	\
		utils_swap_push.c utils_split.c		\
		utils_rotate.c utils_r_rotate.c		\

CC = @gcc

FLAGS = -Wall -Wextra - Werror

OBJS = $(SRCS: .c=.o)


all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY : all re clean fclean