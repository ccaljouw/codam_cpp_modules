# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cariencaljouw <cariencaljouw@student.co      +#+                      #
#                                                    +#+                       #
#    Created: 2023/08/28 13:00:44 by cariencaljo   #+#    #+#                  #
#    Updated: 2023/08/28 15:36:35 by cariencaljo   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD	:= \033[1m
GREEN	:= \033[32;1m
BLUE	:= \033[34;1m
RESET	:= \033[0m

#//= Variables = //#
NAME		= scavtrap
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
INCLUDE		= -I ./include
OBJ_FILES	= $(addprefix obj/, main.o ClapTrap.o ScavTrap.o)


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