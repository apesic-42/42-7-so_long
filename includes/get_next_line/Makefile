OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fPIE
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

.PHONY: bonus all clean fclean re
