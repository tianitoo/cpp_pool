NAME = Harl
CPP = C++
FLAGS = -Wall -Wextra -Werror
C98 = -std=c++98

HARL = main.cpp Harl.cpp

OBJ = $(HARL:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(C98) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(FLAGS) $(C98) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re