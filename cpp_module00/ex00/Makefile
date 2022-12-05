CC		= clang++
CFLAGS	= -Wall -Wextra -Werror
NAME	= megaphone
SRCS	= megaphone.cpp
RM		= rm -rf
ARGV	= 


run: re
	./$(NAME) $(ARGV)
all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

re: fclean all

fclean: clean
	
clean:
	@$(RM) $(NAME)