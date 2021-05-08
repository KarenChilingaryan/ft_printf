SRCS = ft_printf.c \
		ft_char.c \
		ft_str.c \
		ft_int.c \
		ft_unsigint.c \
		ft_pointer.c \
		ft_putnbrx.c \
		ft_unsiglong.c \
		ft_stugumner.c \
		ft_allfunc.c \
		ft_percent.c \
		ft_simbols.c \
		ft_strflag.c \
		ft_libft1.c \
		ft_itoa.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)