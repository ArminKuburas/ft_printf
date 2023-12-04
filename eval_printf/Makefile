NAME = libftprintf.a

SRCDIR = source_files
INCDIR = header_files
OBJDIR = object_files
LIBFTDIR = libft
LIBFT =  $(LIBFTDIR)/libft.a
AR = ar rcs
LIB = ranlib

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_FILES =	$(SRCDIR)/ft_printf.c \
			$(SRCDIR)/ft_ptrhex.c \
			$(SRCDIR)/ft_put_unsigned_nbr.c \
			$(SRCDIR)/ft_putchar.c \
			$(SRCDIR)/ft_puthex.c \
			$(SRCDIR)/ft_putnbr.c \
			$(SRCDIR)/ft_putstr.c

SRC_OBJS =	$(addprefix $(OBJDIR)/,$(notdir $(SRC_FILES:.c=.o)))

all: $(LIBFT) $(NAME)

$(NAME): $(SRC_OBJS) $(LIBFT) 
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(SRC_OBJS)
	$(LIB) $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR) bonus 

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)
clean:
	make -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)
fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re