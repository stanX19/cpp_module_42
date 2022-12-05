CC		= clang++
CFLAGS	= -Wall -Wextra -Werror -Wfatal-errors -std=c++98
NAME	= phonebook
SRCS	= phonebook.cpp contact.cpp
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