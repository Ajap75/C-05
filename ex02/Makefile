# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 12:53:29 by anastruc          #+#    #+#              #
#    Updated: 2025/03/21 11:05:17 by anastruc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AForm
COMPIL = c++
FLAGS =  -Wall -Werror -Wextra -std=c++98 -g3 -fPIC

PINK = \033[1;35m
BLUE = \033[1;36m
NC = \033[0m

HEADER = Bureaucrat.hpp \
 AForm.hpp \
 OutputFormat.hpp \
 ShrubberryCreationForm.hpp \
 RobotomyRequestForm.hpp \
 PresidentialPardonForm.hpp \


SRCS = Bureaucrat.cpp \
 AForm.cpp \
 main.cpp \
 Bureaucrat_GradeTooHighException.cpp \
 Bureaucrat_GradeTooLowException.cpp \
 Form_GradeTooHighException.cpp \
 Form_GradeTooLowException.cpp \
 Form_NotSignedException.cpp \
 ShrubberryCreationForm.cpp \
 RobotomyRequestForm.cpp \
 PresidentialPardonForm.cpp

 
PSRCS = $(addprefix srcs/, $(SRCS))

PHEADERS = $(addprefix headers/, $(HEADER))


OBJS = $(PSRCS:srcs/%.cpp=objs/%.o);

all : $(NAME)

objs/%.o: srcs/%.cpp $(PHEADERS)
		@mkdir -p objs
		@$(COMPIL) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
		@$(COMPIL) $(FLAGS) -o $@ $(OBJS)
		@echo "$(BLUE)\n  AForm COMPILED \n$(NC) "


clean :
	@rm -rf objs
	@echo  "$(BLUE)\n  AForm CLEANED \n$(NC)"

fclean : clean
	@rm -rf $(NAME)
	@echo  "$(BLUE)\n  AForm FULLY CLEANED \n$(NC)"

leak :
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME)

re : fclean all

.PHONY : all clean fclean re bonus