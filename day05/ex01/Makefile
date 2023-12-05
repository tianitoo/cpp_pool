NAME = Form
CPP = c++
FLAGS = -Wall -Wextra -Werror
C98 = -std=c++98
HEADER = Bureaucrat.hpp Form.hpp

FORM = main.cpp Bureaucrat.cpp Form.cpp

OBJ = $(FORM:.cpp=.o)

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