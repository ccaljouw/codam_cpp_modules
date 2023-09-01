# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ccaljouw <ccaljouw@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/07/31 14:38:22 by ccaljouw      #+#    #+#                  #
#    Updated: 2023/09/01 10:10:16 by ccaljouw      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD	:= \033[1m
GREEN	:= \033[32;1m
BLUE	:= \033[34;1m
RESET	:= \033[0m

#//= Variables = //#
NAME		= account
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -Wpedantic -std=c++98
INCLUDE		= -I ./include
OBJ_FILES	= $(addprefix obj/, Account.o tests.o)

#//= Rules = //#
all: $(NAME)
	
$(NAME): $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) -o $(NAME) $(CFLAGS)
	
$(OBJ_FILES): obj/%.o: %.cpp 
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
debug: re

re: fclean all

.PHONY:	all bonus clean fclean re debug
