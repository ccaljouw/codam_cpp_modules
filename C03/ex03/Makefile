# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cariencaljouw <cariencaljouw@student.co      +#+                      #
#                                                    +#+                       #
#    Created: 2023/08/28 13:00:44 by cariencaljo   #+#    #+#                  #
#    Updated: 2023/08/30 10:33:26 by ccaljouw      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD	:= \033[1m
GREEN	:= \033[32;1m
BLUE	:= \033[34;1m
RESET	:= \033[0m

#//= Variables = //#
NAME		= diamondtrap
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -Wpedantic -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wzero-as-null-pointer-constant \
				-Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wfloat-conversion -Wformat=2 -Werror=vla \
				-Wnull-dereference -std=c++98
INCLUDE		= -I include/
OBJ_FILES	= $(addprefix obj/, main.o ClapTrap.o ScavTrap.o FragTrap.o DiamondTrap.o)


all: $(NAME)
	
$(NAME): $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) -o $(NAME) $(CFLAGS)
	
$(OBJ_FILES): obj/%.o: src/%.cpp 
	@mkdir -p $(dir $@)
	@echo "$(GREEN)$(BOLD)Compiling $(NAME):$(RESET) $(notdir $<)"
	@$(CC) -c $(CFLAGS) $(INCLUDE) -o $@ $<

clean:
	@echo "$(BLUE)Cleaning $(NAME) $(RESET)"
	@rm -rf obj/
	@rm -rf obj_builtin/

fclean: clean
	@rm -rf $(NAME)

debug: CFLAGS = -Wall -Wextra 
debug: all

re: fclean all

.PHONY:	all bonus clean fclean re debug