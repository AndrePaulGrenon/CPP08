NAME = Mutant

SRCS =  main.cpp 

CLANG = c++

OBJS =  $(SRCS:.cpp=.o)

FLAGS= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME): $(OBJS)
			$(CLANG) $(FLAGS) -o $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
			rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re

%.o: %.cpp
	$(CLANG) $(FLAGS) -c $<  -o $(<:.cpp=.o)