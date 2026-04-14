# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaygin <rsaygin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 20:08:38 by rsaygin           #+#    #+#              #
#    Updated: 2023/09/20 20:15:37 by rsaygin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	bsq

CC			=	gcc
RM			= 	rm -rf

CFLAGS	=	-Wall -Werror -Wextra

SRCSPATH =	./srcs/
OBJSPATH =	./objs/
INC =		./includes/

SRCS =		$(wildcard $(SRCSPATH)*.c) $(wildcard $(SRCSPATH)**/*.c)
SRCSNAME =	$(subst $(SRCSPATH), , $(SRCS))

OBJSNAME =	$(SRCSNAME:.c=.o)
OBJS =		$(addprefix $(OBJSPATH), $(OBJSNAME))

define	progress_bar
	@i=0
	@while [[ $$i -le $(words $(SRCS)) ]] ; do \
		((i = i + 1)) ; \
	done
endef

all:		launch $(NAME)
	@printf "$(NAME) compiled$(D)\n"

launch:
	$(call progress_bar)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJSPATH)%.o: $(SRCSPATH)%.c
	@mkdir -p $(dir $@) # 2> /dev/null || true
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

debug:
	@make CFLAGS+=-DDEBUG=1 NAME=$(NAME_DEBUG)

clean:
	@$(RM) $(OBJSPATH)
	@echo "$(B)Cleared$(D)"


fclean:		clean
	@$(RM) $(OBJSPATH)
	@$(RM) $(NAME) $(NAME_DEBUG)

re:			fclean all

.PHONY: all clean fclean re launch debug test