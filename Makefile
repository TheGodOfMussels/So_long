# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 18:01:48 by dimolin2          #+#    #+#              #
#    Updated: 2023/02/28 18:01:49 by dimolin2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####### NAME #########

NAME = so_long
PRNAME = so_long

BNUS = bonus

INCLUDE = include
MLX_PATH = ../minilibx-linux

###### VARIABLE ######

DIRSRCS =
DIROBJS = 

FLSRCS = src/main.c src/map.c src/charcheck.c src/exit.c src/checksolution.c src/sprites.c \
		src/utils.c src/key_hook.c

FLBNS = src_bonus/main_bonus.c src_bonus/map_bonus.c src_bonus/charcheck_bonus.c \
		src_bonus/exit_bonus.c src_bonus/checksolution_bonus.c \
		src_bonus/sprites_bonus.c src_bonus/utils_bonus.c src_bonus/key_hook_bonus.c \
		src_bonus/enemy_bonus.c 

FLOBJS = ${FLSRCS:.c=.o}

OBJS = $(FLOBJS)

FLOBJS_BNS = ${FLBNS:.c=.o}

OBJS_BNS = $(FLOBJS_BNS)

ARUSD = libft.a libmlx.a
ARUSDDIR = archive/

ARINC = $(addprefix $(ARUSDDIR),$(ARUSD))

CC = cc
AR = ar
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -lm -lX11 -lXext -lmlx

###### COLORS ########

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

######## EXT #########

# make a .o file using a .c file
# $< for the .c file
# $@ for the .o file

# .inextention.outextention:

#.c.o:
$(DIROBJS)%.o: $(DIRSRCS)%.c
	@echo "$(GREEN)Compiling:$(BLUE) $< $(DEF_COLOR)"
	@${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o $@

####### RULES ########

all: libft ${NAME}

${NAME}: ${OBJS}
	@echo "$(YELLOW)- Program Name: $(WHITE)${PRNAME}$(DEF_COLOR)"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}$(DEF_COLOR)"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}$(DEF_COLOR)"
	@${CC} ${CFLAGS} -L $(ARUSDDIR) -I $(INCLUDE) -o $(PRNAME) $(OBJS) $(ARINC) $(MLXFLAGS) 
	
bonus: $(OBJS_BNS)
	@echo "$(YELLOW)- Program Name: $(WHITE)${PRNAME}$(DEF_COLOR)"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}$(DEF_COLOR)"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}$(DEF_COLOR)"
	@${CC} ${CFLAGS} -L $(ARUSDDIR) -I $(INCLUDE) -o $(PRNAME) $(OBJS_BNS) $(ARINC) $(MLXFLAGS)

clean:
	@make -sC libft clean
	@${RM} ${OBJS} ${OBJS_BNS}
	@echo "$(RED)All $(CYAN)$(PRNAME)$(RED)'s objects removed with $(WHITE)${RM}$(DEF_COLOR) 🧹" 

fclean: clean
	@make -sC libft fclean
	@${RM} ${PRNAME} 
	@echo "$(RED)..and $(CYAN)${PRNAME} $(RED)as been removed$(DEF_COLOR) 🚮"

libft:
	@make -sC libft

libftclean:
	@make -sC libft clean

libftfclean:
	@make -sC libft fclean

re: fclean all 

minilibx:
	@make -C $(MLX_PATH)
	@cp $(MLX_PATH)/mlx.h $(INCLUDE)/mlx.h
	@cp $(MLX_PATH)/libmlx_Linux.a $(ARUSDDIR)/libmlx.a

.PHONY: all clean fclean re starting .c.o libft libftclean libftfclean minilibx
.SUFFIXES: .c .o 
