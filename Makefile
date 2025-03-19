# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 15:00:45 by crizapat          #+#    #+#              #
#    Updated: 2025/02/04 16:44:05 by crizapat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	FLAGS _____________________________
CC			=	cc
FLAGS		=	-Wall -Werror -Wextra -g3 -fsanitize=address
RM			=	rm -f

#	CONFS _____________________________
SERVER_EXE	=	server 
CLIENT_EXE	=	client

#	SRCS ______________________________
SERVER_SRC	=	./src/server.c	
CLIENT_SRC	=	./src/client.c
BANNERS_SRC =	./utils/misc/banners.c
LIBFT_DIR	=	./utils/libft
PRINTF_DIR	=	./utils/ft_printf
LIBFT		=	$(LIBFT_DIR)/libft.a
PRINTF		=	$(PRINTF_DIR)/libftprintf.a

#	OBJS ______________________________
SERVER_OBJ	=	$(SERVER_SRC:.c=.o)
CLIENT_OBJ	=	$(CLIENT_SRC:.c=.o)
BANNER_OBJ	=	$(BANNERS_SRC:.c=.o)

all: $(SERVER_EXE) $(CLIENT_EXE) $(BANNER_OBJ)

$(BANNER_OBJ): $(BANNERS_SRC)
	@$(CC) $(FLAGS) -c $(BANNERS_SRC) -o $(BANNER_OBJ)

$(SERVER_EXE): $(SERVER_OBJ) $(BANNER_OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(FLAGS) $(SERVER_OBJ) $(BANNER_OBJ) $(LIBFT) $(PRINTF) -o $(SERVER_EXE)
	@echo "✅ $(SERVER_EXE) compiled success."

$(CLIENT_EXE): $(CLIENT_OBJ) $(BANNER_OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(FLAGS) $(CLIENT_OBJ) $(BANNER_OBJ) $(LIBFT) $(PRINTF) -o $(CLIENT_EXE)
	@echo "✅ $(CLIENT_EXE) compiled success."

$(LIBFT): 
	@make -sC $(LIBFT_DIR) 

$(PRINTF):
	@make -sC $(PRINTF_DIR)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ 

clean:
	@$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(BANNER_OBJ)
	@make -sC $(LIBFT_DIR) clean
	@make -sC $(PRINTF_DIR) clean
	@echo "All objects files cleaned"

fclean: clean
	@$(RM) $(SERVER_EXE) $(CLIENT_EXE) $(LIBFT)
	@make -sC $(LIBFT_DIR) fclean
	@make -sC $(PRINTF_DIR) fclean
	@echo "All executables and libraries cleaned"

re: fclean all

.PHONY: all clean fclean re
