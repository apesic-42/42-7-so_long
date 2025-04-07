
NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fPIE
AR = ar rcs
RM = rm -f

SRCS_DIR = srcs/
OBJS_DIR = .objets/srcs/

PARSING = $(addprefix parsing/, parser parser_utils)
GAME = $(addprefix game/, initialize moves)

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, main $(PARSING) $(GAME)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, main $(PARSING) $(GAME)))

INCLUDE_DIR = includes/
INCLUDES = -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/libft -I$(INCLUDE_DIR)/minilibx-linux

LIBFT_DIR = $(INCLUDE_DIR)libft/
PRINTF = $(LIBFT_DIR)libftprintf.a
MLX = $(INCLUDE_DIR)minilibx-linux/libmlx.a

LIBS = $(PRINTF) $(MLX)
MLX_FLAGS = -L$(INCLUDE_DIR)minilibx-linux -lmlx -lm -lXext -lX11

DIR_DUP = mkdir -p $(@D)

all : $(OBJS_DIR) $(PRINTF) $(MLX) $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(PRINTF):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(INCLUDE_DIR)minilibx-linux

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ $(INCLUDES) -L$(LIBFT_DIR) -lftprintf $(MLX_FLAGS) -o $@

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(INCLUDE_DIR)minilibx-linux clean
	$(RM) $(OBJS)

fclean : clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
