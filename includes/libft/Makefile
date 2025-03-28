
NAME = libft.a

FILES = ft_bzero \
		ft_memset \
		ft_memcpy \
		ft_memcmp \
		ft_memchr \
		ft_memmove \
		ft_strlen \
		ft_tablen \
		ft_strlcpy \
		ft_strlcat \
		ft_strcpy \
		ft_strcat \
		ft_strchr \
		ft_strrchr \
		ft_strnstr \
		ft_strncmp \
		ft_strcmp \
		ft_atoi \
		ft_itoa \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_calloc \
		ft_realloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_strmapi \
		ft_striteri \

FILES_B = ft_lstnew_bonus \
			ft_lstadd_front_bonus \
			ft_lstsize_bonus \
			ft_lstlast_bonus \
			ft_lstadd_back_bonus \
			ft_lstdelone_bonus \
			ft_lstclear_bonus \
			ft_lstiter_bonus \
			ft_lstmap_bonus

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_B)))

OBJS_DIR = ../../.objets/libft/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))


CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar rcs
RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS_DIR)%.o: %.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS) $(OBJS_B)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
