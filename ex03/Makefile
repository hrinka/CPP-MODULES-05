CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = bureaucrat
SRCS = main.cpp Intern.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp \
		Bureaucrat.cpp Form.cpp 
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *_shrubbery

re: fclean all
