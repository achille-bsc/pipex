CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c\
	ft_isdigit.c ft_isprint.c ft_strchr.c ft_putchar_fd.c\
	ft_strlen.c ft_strrchr.c ft_atoi.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c\
	ft_strnstr.c ft_memchr.c ft_memset.c ft_memcmp.c ft_memmove.c ft_memcpy.c\
	ft_bzero.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c\
	ft_split.c ft_itoa.c ft_lstadd_back_bonus.c ft_putstr_fd.c\
	ft_lstadd_front_bonus.c ft_lstclear_bonus.c\
	ft_lstlast_bonus.c ft_lstnew_bonus.c ft_putnbr_fd.c\
	ft_lstsize_bonus.c ft_printf.c ft_print_hex.c ft_print_numbers.c\
	ft_print_pointers.c ft_print_unsigned.c ft_printstr.c ft_printf.c\
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c\
	get_next_line.c get_next_line_utils.c read_file.c\
	ft_strmapi.c ft_tolower.c ft_toupper.c ft_putendl_fd.c ft_striteri.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)


$(NAME): $(OBJ_DIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS) ${OBJS_BONUS} ${NAME}

re: fclean all

.PHONY: all clean fclean re
