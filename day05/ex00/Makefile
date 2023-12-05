NAME = Bureaucrat
CPP = c++
FLAGS = -Wall -Wextra -Werror
C98 = -std=c++98
HEADER = Bureaucrat.hpp

BUREAUCRAT = main.cpp Bureaucrat.cpp

OBJ = $(BUREAUCRAT:.cpp=.o)

all: $(NAME) 

$(NAME): $(OBJ) $(HEADER)
	$(CPP) $(FLAGS) $(C98) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CPP) $(FLAGS) $(C98) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re