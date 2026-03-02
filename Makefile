# config
NAME		:= cub3d
CC			:= cc
SRC_DIR		:= src
OBJ_DIR		:= obj
LIBFT_DIR	:= libft
LIBFT		:= libft.a
MLX42_DIR	:= MLX42
MLX42		:= libmlx42.a

TESTS_DIR	:= tests
UNITY_DIR	:= $(TESTS_DIR)/unity

CFLAGS	:=
CFLAGS	+= -O2
CFLAGS	+= -Wall
CFLAGS	+= -Wextra
CFLAGS	+= -Werror
CFLAGS	+= -Wno-unused-result
CFLAGS	+= -pedantic
CFLAGS	+= -Wconversion
CFLAGS	+= -fPIE
# CFLAGS	+= -no-pie
CFLAGS	+= $(ADDCFLAGS)

CPPFLAGS	:=
CPPFLAGS	+= -I$(LIBFT_DIR)
CPPFLAGS	+= -I$(SRC_DIR)

#********** Add the path to your headers here ***********#
# e.g: CPPFLAGS	+= -I$(SRC_DIR)/module/path

CPPFLAGS	+= -I$(SRC_DIR)/error
CPPFLAGS	+= -I$(SRC_DIR)/gnl
CPPFLAGS	+= -I$(SRC_DIR)/parsing
CPPFLAGS	+= -I$(SRC_DIR)/malloc
CPPFLAGS	+= -I$(SRC_DIR)/cleanup
CPPFLAGS	+= -I$(SRC_DIR)/debug
CPPFLAGS	+= $(ADDCPPFLAGS)

#********************************************************#

LDFLAGS	:=
LDFLAGS += -L$(LIBFT_DIR)
LDFLAGS	+= -L$(MLX42_DIR)/build
# LDFLAGS	+= -L$(MLX42_DIR)/build/_deps/glfw-build/src


LDLIBS	:=
LDLIBS	+= -lft
LDLIBS	+= -lmlx42
LDLIBS	+= -lglfw
LDLIBS	+= -lm
LDLIBS	+= -ldl
LDLIBS	+= -lpthread


ifeq ($(DEBUG), 1)
	CFLAGS	+= -ggdb3 -O0
	LDFLAGS	+= -ggdb3 -O0
endif

ifeq ($(TSAN), 1)
	CFLAGS	+= -fsanitize=thread
	LDFLAGS	+= -fsanitize=thread
endif

ifeq ($(LSAN), 1)
	CFLAGS	+= -fsanitize=leak
	LDFLAGS	+= -fsanitize=leak
endif

ifeq ($(ASAN), 1)
	CFLAGS	+= -fsanitize=address
	LDFLAGS	+= -fsanitize=address
endif

# 1. Check if the first argument passed to make is "utest"
ifeq (utest,$(firstword $(MAKECMDGOALS)))

  # 2. Grab everything after "utest" and store it in CFILES
  # (Note: Make ignores "DEBUG=1" here because it's a variable assignment, which is perfect)
  CFILES := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))

  # 3. Turn the extracted C files into empty "do-nothing" targets
  # This prevents Make from throwing a "No rule to make target" error
  $(eval $(CFILES):;@:)

endif


#******* Add your module and your .c files here ********#
# e.g: vpath %.c $(SRC_DIR)/module/path

# Sources
SRC		:=

vpath %.c $(SRC_DIR)
SRC		+= main.c

vpath %.c $(SRC_DIR)/error
SRC		+= error.c

vpath %.c $(SRC_DIR)/gnl
SRC		+= get_next_line.c

vpath %.c $(SRC_DIR)/parsing
SRC		+= parser01.c
SRC		+= parser02.c
SRC		+= parser03.c

vpath %.c $(SRC_DIR)/malloc
SRC		+= ft_malloc_lite.c

vpath %.c $(SRC_DIR)/cleanup
SRC		+= free_double_array.c
SRC		+= free_mapdata.c

vpath %.c $(SRC_DIR)/debug
SRC		+= print_mapdata.c

#*******************************************************#

OBJ		:= $(SRC:.c=.o)
OBJ		:= $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(LIBFT_DIR)/$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX42_DIR)/$(MLX42):
	@cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build
	@make -C $(MLX42_DIR)/build -j4

$(NAME): $(LIBFT_DIR)/$(LIBFT) $(MLX42_DIR)/$(MLX42) $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@

$(OBJ_DIR)/%.o:%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	rm -rf $(MLX42_DIR)/build

re:
	@make fclean
	@make all

# Example use:
# $ make utest file_to_test1.c file_to_test2.c test_file.c
utest: CFLAGS += -ggdb3 -O0
utest: LDFLAGS += -ggdb3 -O0
utest:
	@echo "Compiling files: " $(CFILES)
	$(CC) $(UNITY_DIR)/unity.c $(CFILES) $(CPPFLAGS) -I$(UNITY_DIR) $(LDFLAGS) $(LDLIBS) -o unit-test

valtest:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME) $(ARGS)

.PHONY: all clean fclean re
.PHONY: valtest
