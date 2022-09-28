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
LIB_DIR				=	./libft/

LDFLAGS				=	-L${HOME}/.brew/opt/readline/lib
CPPFLAGS			=	-I${HOME}/.brew/opt/readline/include

SRCS_BUILTIN		=	$(addprefix builtin/, cd_utils.c ft_cd.c ft_env.c \
						ft_export.c ft_export_no_arg_utils.c ft_pwd.c env_utils.c \
						ft_echo.c ft_exit.c ft_export_check_valid.c ft_getenv.c ft_unset.c)
SRCS_EXECUTOR		=	$(addprefix executor/, check_valid_syntax.c close_unused_fd.c \
						executor.c executor_utils.c heredoc.c init_clear_cmd.c io_file_open.c \
						path.c redirection.c tmp_file.c wait_child.c)
SRCS_PARSER			=	$(addprefix parser/, argc_checker.c ft_split_argc.c ft_strjoin_char.c parse.c \
						parse_quotes.c replace.c replace_utils.c)
SRCS_UTILS			=	$(addprefix utils/, exit_with_error.c ft_system_call.c ft_system_call2.c is_exist_file.c signal.c)
SRCS_STRUCT			=	$(addprefix struct/, cmd.c)

SRCS_NOSRCDIR		=	main.c $(SRCS_BUILTIN) $(SRCS_EXECUTOR) $(SRCS_PARSER) $(SRCS_UTILS) $(SRCS_STRUCT)

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NOSRCDIR))
OBJS = $(SRCS:.c=.o) $(SRCS_BONUS:.c=.o)

all: subsystem $(NAME)

subsystem:
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCS_DIR) $^ -lreadline $(LDFLAGS) $(CPPFLAGS) $(LIB_DIR)libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCS_DIR) $(CPPFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
