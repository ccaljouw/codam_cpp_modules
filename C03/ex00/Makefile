# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cariencaljouw <cariencaljouw@student.co      +#+                      #
#                                                    +#+                       #
#    Created: 2023/08/28 13:00:44 by cariencaljo   #+#    #+#                  #
#    Updated: 2023/08/28 13:00:58 by cariencaljo   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD	:= \033[1m
GREEN	:= \033[32;1m
BLUE	:= \033[34;1m
RESET	:= \033[0m

#//= Variables = //#
NAME		= claptrap
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
INCLUDE		= ./include
HEADERS		= 
OBJ_FILES	= $(addprefix obj/, main.o ClapTrap.o)


all: $(NAME)
	
$(NAME): $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) $(HEADERS) -o $(NAME) $(CFLAGS)
	
$(OBJ_FILES): obj/%.o: %.cpp 
	@mkdir -p $(dir $@)
	@echo "$(GREEN)$(BOLD)Compiling $(NAME):$(RESET) $(notdir $<)"
	@$(CC) -c $(CFLAGS) $(HEADERS) -o $@ $< 

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