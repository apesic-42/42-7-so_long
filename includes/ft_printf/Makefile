
NAME = libftprintf.a

FILES = ft_printf \
		ft_putstr \
		ft_putchar \
		ft_putnbr_base \
		ft_putptr \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ../../.objets/ft_printf/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIE -g3
AR = ar rcs
RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS_DIR)%.o: %.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
