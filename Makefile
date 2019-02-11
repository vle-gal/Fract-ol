# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 15:16:47 by vle-gal           #+#    #+#              #
#    Updated: 2018/01/17 16:12:19 by vle-gal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = Fract\'ol #Makefile simple
#les Path finding
vpath %.c basic #les .c
vpath_h = -Idoth -Ilibft/doth -Iminilibx_macos #les .h
LIB = -Llibft -lft -Lminilibx_macos -lmlx
framework = -framework OpenGl -framework AppKit

#les couleurs et autre
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

#les pré règles
OBJDIR := objdiro
OBJS := $(addprefix $(OBJDIR)/,main.o sec.o)

$(OBJDIR)/%.o : %.c
	@gcc $(CPPFLAGS) $(CFLAGS) $(vpath_h) -Wall -Wextra -Werror -c \
	$(OUTPUT_OPTION) $<

#les règles
all: $(OBJS)
	@make -C minilibx_macos/
	@make -C libft/
	@gcc $(LIB) $(frameworks) -o Fract\'ol $(OBJS)
	@echo $(R)Hail to the King Baby!
	@echo --------------$(X)
	@./Fract\'ol
	@echo $(R)--------------


$(OBJS): | $(OBJDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

#les outils
clean :
	@rm -rf $(OBJDIR)
	@echo $(R)Hmm... so there is life after death..

fclean : clean
	@rm Fract\'ol

re : fclean
	@make

clib :
	@make -C libft/ clean
