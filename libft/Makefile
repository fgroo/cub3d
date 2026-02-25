# config
NAME		:= libft.a
SRC_DIR		:= .
OBJ_DIR		:= obj
CC			:= cc

# flags
CFLAGS		:=
CFLAGS		+= -O2
CFLAGS		+= -Wall
CFLAGS		+= -Wextra
CFLAGS		+= -Werror
CFLAGS		+= -pedantic
CFLAGS		+= -Wconversion
CFLAGS		+= -Wunreachable-code
CFLAGS		+= -Wshadow

CPPFLAGS	:=
CPPFLAGS	+= -I$(SRC_DIR)


ifeq ($(DEBUG), 1)
	CFLAGS	+= -ggdb3 -O0
endif

# sources
SRC			:=

# string
vpath %.c string/
SRC			+= ft_atoi.c
SRC			+= ft_atol.c
SRC			+= ft_atoll.c
SRC			+= ft_isalnum.c
SRC			+= ft_isalpha.c
SRC			+= ft_isascii.c
SRC			+= ft_isdigit.c
SRC			+= ft_islower.c
SRC			+= ft_isprint.c
SRC			+= ft_isspace.c
SRC			+= ft_isupper.c
SRC			+= ft_strchr.c
SRC			+= ft_strcmp.c
SRC			+= ft_strlcat.c
SRC			+= ft_strlcpy.c
SRC			+= ft_strlen.c
SRC			+= ft_strncmp.c
SRC			+= ft_strnstr.c
SRC			+= ft_strrchr.c
SRC			+= ft_strtol.c
SRC			+= ft_tolower.c
SRC			+= ft_toupper.c

# strings
vpath %.c strings/
SRC			+= ft_itoa.c
SRC			+= ft_strdup.c
SRC			+= ft_split.c
SRC			+= ft_substr.c
SRC			+= ft_strjoin.c
SRC			+= ft_strtrim.c
SRC			+= ft_strmapi.c
SRC			+= ft_striteri.c

# memory
vpath %.c memory/
SRC			+= ft_bzero.c
SRC			+= ft_calloc.c
SRC			+= ft_memchr.c
SRC			+= ft_memcmp.c
SRC			+= ft_memcpy.c
SRC			+= ft_memmove.c
SRC			+= ft_memset.c
SRC			+= ft_realloc.c

# io
vpath %.c io/
SRC			+= ft_putchar_fd.c
SRC			+= ft_putendl_fd.c
SRC			+= ft_putnbr_fd.c
SRC			+= ft_putstr_fd.c
SRC			+= ft_printf.c

# list
vpath %.c list/
SRC			+= ft_lstnew.c
SRC			+= ft_lstadd_front.c
SRC			+= ft_lstadd_back.c
SRC			+= ft_lstclear.c
SRC			+= ft_lstdelone.c
SRC			+= ft_lstiter.c
SRC			+= ft_lstlast.c
SRC			+= ft_lstmap.c
SRC			+= ft_lstsize.c

OBJ			:= $(SRC:.c=.o)
OBJ			:= $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)


$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean flcean re
