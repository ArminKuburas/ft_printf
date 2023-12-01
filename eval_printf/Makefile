NAME = libftprintf.a

SRCDIR = source_files
INCDIR = header_files
OBJDIR = object_files

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

all: $(NAME)

$(NAME): $(SRC_OBJS) 
	$(AR) $(NAME) $(SRC_OBJS)
	$(LIB) $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)
clean:
	rm -rf $(OBJDIR)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re