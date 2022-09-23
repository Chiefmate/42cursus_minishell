# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 16:08:42 by hyunhole          #+#    #+#              #
#    Updated: 2022/09/02 17:57:23 by hyunhole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	minishell

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror
AR					=	ar
ARFLAGS				=	crs
RM					=	rm -f

INCS_DIR			=	./include/
SRCS_DIR			=	./src/

SRCS_NODIR			=	main.c \
						init.c \
						parser/parse.c \
						parser/parse_quotes.c \
						parser/replace.c \
						parser/replace_utils.c \
						parser/ft_split_argc.c \
						parser/ft_strjoin_char.c \
						executor/check_valid_syntax.c \
						executor/executor_utils.c \
						executor/io_file_open.c \
						executor/tmp_file.c \
						executor/close_unused_fd.c \
						executor/heredoc.c \
						executor/path.c \
						executor/wait_child.c \
						executor/executor.c \
						executor/init_clear_cmd.c \
						executor/redirection.c \
						utils/exit_with_error.c \
						utils/ft_system_call.c \
						utils/ft_system_calls2.c \
						utils/is_exist_file.c \
						utils/signal.c \

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NODIR))
OBJS = $(SRCS:.c=.o) $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCS_DIR) $^ -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
