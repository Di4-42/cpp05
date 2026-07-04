NAME = bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = main.o Bureaucrat.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

main.o: main.cpp Bureaucrat.hpp Form.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o


Bureaucrat.o: Bureaucrat.cpp Bureaucrat.hpp Form.hpp
	$(CXX) $(CXXFLAGS) -c Bureaucrat.cpp -o Bureaucrat.o

Form.o: Form.cpp Form.hpp Bureaucrat.hpp
	$(CXX) $(CXXFLAGS) -c Form.cpp -o Form.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
