NAME = span
CPP = c++
FLAGS = -Wall -Wextra -Werror
C98 = -std=c++98
HEADER = Span.hpp

FORM = main.cpp Span.cpp

OBJ = $(FORM:.cpp=.o)

all: $(NAME) 

$(NAME): $(OBJ) $(HEADER)
	$(CPP) $(FLAGS)  $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CPP) $(FLAGS)  -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re