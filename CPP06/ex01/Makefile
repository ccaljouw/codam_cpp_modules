# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ccaljouw <ccaljouw@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2023/08/30 10:48:44 by ccaljouw      #+#    #+#                  #
#    Updated: 2024/08/08 15:06:41 by cariencaljo   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD	:= \033[1m
GREEN	:= \033[32;1m
BLUE	:= \033[34;1m
RESET	:= \033[0m

#//= Variables = //#
NAME		= serialize
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -Wpedantic -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wzero-as-null-pointer-constant \
				-Wunused -Woverloaded-virtual -Wconversion -Wsign-conversion -Wfloat-conversion -Wformat=2 -Werror=vla \
				-Wnull-dereference -std=c++11
INCLUDE		= -I include/
OBJ_FILES	= $(addprefix obj/, main.o   Serializer.o Data.o)


all: $(NAME)
	
$(NAME): $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) -o $(NAME) $(CFLAGS) $(INCLUDE)
	
$(OBJ_FILES): obj/%.o: src/%.cpp 
	@mkdir -p $(dir $@)
	@echo "$(GREEN)$(BOLD)Compiling $(NAME):$(RESET) $(notdir $<)"
	@$(CC) -c $(CFLAGS) $(INCLUDE) -o $@ $<

clean:
	@echo "$(BLUE)Cleaning $(NAME) $(RESET)"
	@rm -rf obj/

fclean: clean
	@rm -rf $(NAME)

debug: CFLAGS = -Wall -Wextra 
debug: all

re: fclean all

.PHONY:	all bonus clean fclean re debug