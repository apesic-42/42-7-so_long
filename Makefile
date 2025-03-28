
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
INCLUDES = -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/libft -I$(INCLUDE_DIR)/ft_printf -I$(INCLUDE_DIR)/get_next_line -I$(INCLUDE_DIR)/minilibx-linux

LIBFT = $(INCLUDE_DIR)libft/libft.a
PRINTF = $(INCLUDE_DIR)ft_printf/libftprintf.a
GET_NEXT_LINE = $(INCLUDE_DIR)get_next_line/get_next_line.a
MLX = $(INCLUDE_DIR)minilibx-linux/libmlx.a

LIBS = $(LIBFT) $(PRINTF) $(GET_NEXT_LINE) $(MLX)
MLX_FLAGS = -L$(INCLUDE_DIR)minilibx-linux -lmlx -lm -lXext -lX11

DIR_DUP = mkdir -p $(@D)

all : $(OBJS_DIR) $(LIBFT) $(PRINTF) $(GET_NEXT_LINE) $(MLX) $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(LIBS):
	@$(MAKE) -C $(INCLUDE_DIR)libft
	@$(MAKE) -C $(INCLUDE_DIR)ft_printf
	@$(MAKE) -C $(INCLUDE_DIR)get_next_line
	@$(MAKE) -C $(INCLUDE_DIR)minilibx-linux

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ $(INCLUDES) -L$(INCLUDE_DIR)libft -lft -L$(INCLUDE_DIR)ft_printf -lftprintf -L$(INCLUDE_DIR)get_next_line -l:get_next_line.a -lft $(MLX_FLAGS) -o $@

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

clean:
	@$(MAKE) -C $(INCLUDE_DIR)libft clean
	@$(MAKE) -C $(INCLUDE_DIR)ft_printf clean
	@$(MAKE) -C $(INCLUDE_DIR)get_next_line clean
	@$(MAKE) -C $(INCLUDE_DIR)minilibx-linux clean
	$(RM) $(OBJS)

fclean : clean
	@$(MAKE) -C $(INCLUDE_DIR)libft fclean
	@$(MAKE) -C $(INCLUDE_DIR)ft_printf fclean
	@$(MAKE) -C $(INCLUDE_DIR)get_next_line fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
