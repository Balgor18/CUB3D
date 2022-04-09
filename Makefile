NAME = cub3D

OBJ_DIR		=	objs
INC_DIR		=	includes
SRC_DIR		=	$(shell find srcs -type d)
LIB_DIR		=	-Llibrairie/minilibx-linux -lm -lmlx -lXext -lX11

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

# --  Redirection in OBJS  -- #
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

SRCS =	tab_utils.c                 	\
		string_utils3.c             	\
		string_utils2.c             	\
		string_utils.c              	\
		print.c                     	\
		parsing.c                   	\
		main.c                      	\
		lst_utils.c                 	\
		init_player.c               	\
		fill_textures.c             	\
		check_closed_map.c             	\
		ft_split.c                  	\
		free2.c                     	\
		free.c                      	\
		free_mlx.c                  	\
		fill_list.c                 	\
		fill_data.c                 	\
		file_utils.c                	\
		data_utils.c                	\
		get_texture_pixel.c         	\
		create_texture.c            	\
		atoi_base.c                 	\
		ft_ternary.c                	\
		vertical_check.c            	\
		horizontal_check.c          	\
		utils_mlx.c                 	\
		start_mlx.c                 	\
		print_3d.c                  	\
		hook_mlx.c                  	\
		check_textures.c            	\
		check_syntax.c              	\
		check_duplicates.c          	\


# --   Compilation flags  -- #
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror


# -- Nominette -- #
NORME = norminette srcs includes

# --    Add DEBUG flags   -- #
DEBUG = $(shell env | grep DEBUG= | tr '=' ' ' | awk '{print $$2}')

ifeq ($(DEBUG), 1)
	CFLAGS += -g3
endif

.PHONY: all
ifeq ($(DEBUG), 1)
all : librairie/minilibx-linux/libmlx.a $(NAME)
# ./cub3D
# valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./cub3D
# norminette srcs | grep Error

else
all : librairie/minilibx-linux/libmlx.a $(NAME)
endif

# **************************************************************************** #


$(NAME): $(OBJS) $(INC_DIR)/cub3D.h
	@echo "\n"
	@echo "$(shell tput setaf 198) ██████╗██╗   ██╗██████╗     ██████╗ ██████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 197)██╔════╝██║   ██║██╔══██╗    ╚════██╗██╔══██╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 196)██║     ██║   ██║██████╔╝     █████╔╝██║  ██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 202)██║     ██║   ██║██╔══██╗     ╚═══██╗██║  ██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 208)╚██████╗╚██████╔╝██████╔╝    ██████╔╝██████╔╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 214) ╚═════╝ ╚═════╝ ╚═════╝     ╚═════╝ ╚═════╝$(shell tput sgr0)"
	@echo "\n"
	$(CC) $(CFLAGS) $(OBJS) -I $(INC_DIR) -o $(NAME) $(LIB_DIR)

$(OBJ_DIR)/%.o: %.c $(INC_DIR)/cub3D.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) -I librairie/minilibx-linux

$(OBJ_DIR) :
	mkdir -p $@

# **************************************************************************** #

librairie/minilibx-linux/libmlx.a :
	make -C librairie/minilibx-linux

# **************************************************************************** #

.PHONY: norme
norme:
	@echo "\n"
	@echo "$(shell tput setaf 201)███╗   ██╗ ██████╗ ██████╗ ███╗   ███╗██╗███╗   ██╗███████╗████████╗████████╗███████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 200)████╗  ██║██╔═══██╗██╔══██╗████╗ ████║██║████╗  ██║██╔════╝╚══██╔══╝╚══██╔══╝██╔════╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 199)██╔██╗ ██║██║   ██║██████╔╝██╔████╔██║██║██╔██╗ ██║█████╗     ██║      ██║   █████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 198)██║╚██╗██║██║   ██║██╔══██╗██║╚██╔╝██║██║██║╚██╗██║██╔══╝     ██║      ██║   ██╔══$(shell tput sgr0)"
	@echo "$(shell tput setaf 197)██║ ╚████║╚██████╔╝██║  ██║██║ ╚═╝ ██║██║██║ ╚████║███████╗   ██║      ██║   ███████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 196)╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝   ╚═╝      ╚═╝   ╚══════╝$(shell tput sgr0)"
	@echo "\n"
	@$(NORME)

.PHONY: clean
clean:
	make -C librairie/minilibx-linux clean
	rm -rf $(OBJ_DIR)
	@echo "\n"
	@echo "$(shell tput setaf 51) ██████╗██╗     ███████╗ █████╗ ███╗   ██╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 50)██╔════╝██║     ██╔════╝██╔══██╗████╗  ██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 49)██║     ██║     █████╗  ███████║██╔██╗ ██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 48)██║     ██║     ██╔══╝  ██╔══██║██║╚██╗██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 47)╚██████╗███████╗███████╗██║  ██║██║ ╚████║$(shell tput sgr0)"
	@echo "$(shell tput setaf 46) ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝$(shell tput sgr0)"
	@echo "\n"

.PHONY: fclean
fclean: clean
	@echo "\n"
	@echo "$(shell tput setaf 45)███████╗ ██████╗██╗     ███████╗ █████╗ ███╗   ██╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 44)██╔════╝██╔════╝██║     ██╔════╝██╔══██╗████╗  ██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 43)█████╗  ██║     ██║     █████╗  ███████║██╔██╗ ██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 42)██╔══╝  ██║     ██║     ██╔══╝  ██╔══██║██║╚██╗██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 41)██║     ╚██████╗███████╗███████╗██║  ██║██║ ╚████║$(shell tput sgr0)"
	@echo "$(shell tput setaf 40)╚═╝      ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝$(shell tput sgr0)"
	@echo "\n"
	rm -f $(NAME) $(NAME_BONUS)

.PHONY: re
re: fclean all
	@echo "\n"
	@echo "$(shell tput setaf 201)███╗   ███╗ █████╗ ██╗  ██╗███████╗    ██████╗ ███████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 200)████╗ ████║██╔══██╗██║ ██╔╝██╔════╝    ██╔══██╗██╔════╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 199)██╔████╔██║███████║█████╔╝ █████╗      ██████╔╝█████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 198)██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝      ██╔══██╗██╔══╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 197)██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗    ██║  ██║███████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 196)╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝    ╚═╝  ╚═╝╚══════╝$(shell tput sgr0)"
	@echo "\n"

.PHONY: bonus
bonus: $(OBJS_BONUS)
	@echo "\n"
	@echo "$(shell tput setaf 226)██████╗  ██████╗ ███╗   ██╗██╗   ██╗███████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 220)██╔══██╗██╔═══██╗████╗  ██║██║   ██║██╔════╝$(shell tput sgr0)"
	@echo "$(shell tput setaf 214)██████╔╝██║   ██║██╔██╗ ██║██║   ██║███████╗$(shell tput sgr0)"
	@echo "$(shell tput setaf 208)██╔══██╗██║   ██║██║╚██╗██║██║   ██║╚════██║$(shell tput sgr0)"
	@echo "$(shell tput setaf 202)██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝███████║$(shell tput sgr0)"
	@echo "$(shell tput setaf 196)╚═════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝$(shell tput sgr0)"
	@echo "\n"
	$(CC) $(OBJS_BONUS) $(CFLAGS) -o $(NAME_BONUS)

.PHONY: fox
fox:
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)        $(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)        $(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0) $(shell tput setaf 94)∂∂∂∂$(shell tput setaf 202)ΩΩΩ$(tput sgr0)     $(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)      $(shell tput setaf 202)ΩΩ$(shell tput setaf 94)∂∂∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0) $(shell tput setaf 94)∂∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩ$(tput sgr0)     $(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)     $(shell tput setaf 202)ΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 94)∂$(shell tput setaf 0)≈≈≈≈≈≈$(shell tput setaf 94)∂∂∂∂∂∂∂∂∂∂∂∂∂$(shell tput setaf 0)≈≈≈≈≈$(shell tput setaf 94)∂$(shell tput sgr0)   $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)ππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩ  $(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)  $(shell tput setaf 202)ΩΩ$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)πππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 202)ΩΩΩΩ$(shell tput sgr0)  $(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)πππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)πππππππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)πππππππππππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)πππππππππππππππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)ππππππππππππππππππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)ππππππππππππππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 208)ππππππππππππππππππππππ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput setaf 208)ππππππππππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput setaf 208)ππππππππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 208)ππππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@$(shell tput setaf 40)@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩ$(shell tput setaf 94)∂$(shell tput setaf 208)ππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@@$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@@$(shell tput setaf 40)@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 208)ππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@$(shell tput setaf 40)@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈$(sh    ell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 208)πππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 208)πππππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 208)πππππππππππππ$(shell tput setaf 94)∂$(shell tput setaf 202)ΩΩ$(shell tput sgr0) $(shell tput setaf 40)@@@$(shell tput sgr0) $(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈$(shell tput setaf 94)∂∂∂∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 208)ππππππππππππππ$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ∂∂$(shell tput setaf 0)≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂$(shell tput setaf 208)ππππππππππ$(shell tput setaf 94)∂∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂$(shell tput setaf 208)ππππππππ$(shell tput setaf 94)∂∂∂$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ∂∂$(shell tput setaf 0)≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 94)∂$(shell tput sgr0)ΩΩ$(shell tput setaf 94)∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂$(shell tput sgr0)ΩΩΩΩΩΩ:::$(shell tput sgr0)ΩΩΩΩΩΩΩ$(shell tput setaf 202)ΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)ΩΩΩΩΩΩ:::$(shell tput sgr0)ΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂$(shell tput sgr0)ΩΩ$(shell tput setaf 94)∂$(shell tput sgr0)"
	@echo "$(shell tput setaf 94)∂∂$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩ$(shell tput sgr0)     :::::$(shell tput sgr0)     $(shell tput sgr0)ΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)             $(shell tput sgr0)ΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 0)≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)           $(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 0)≈≈∂∂$(shell tput setaf 0)≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈$(shell tput setaf 94)∂∂∂∂$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ:ΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput sgr0)         ΩΩΩΩΩΩΩΩΩΩ:ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂∂$(shell tput setaf 0)≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂∂∂∂∂$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂∂∂$(shell tput sgr0)ΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩΩΩ:$(shell tput sgr0)ΩΩΩΩ$(shell tput setaf 94)∂∂∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂∂$(shell tput sgr0)ΩΩΩΩΩΩΩΩΩΩ::$(shell tput sgr0)$(shell tput setaf 196)ΩΩΩ$(shell tput sgr0)::ΩΩΩΩΩΩΩΩ$(shell tput setaf 94)∂∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput sgr0):::$(shell tput sgr0)ΩΩΩΩ$(shell tput setaf 196)ΩΩΩ$(shell tput sgr0)ΩΩΩΩ:::$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂$(shell tput sgr0)ΩΩΩ$(shell tput setaf 196)Ω$(shell tput sgr0)ΩΩΩΩ$(shell tput setaf 94)∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
	@echo "$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput setaf 94)∂∂∂∂∂∂$(shell tput setaf 0)≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈$(shell tput sgr0)"
