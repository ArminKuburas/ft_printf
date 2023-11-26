NAME = libftprintf.a

SRCDIR = source_files
HLPDIR = source_files/printf_helper_functions
INCDIR = include
OBJDIR = object_files

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = $(SRCDIR)/ft_printf.c
HLP_FILES = $(HLPDIR)/ft_put_ptrhex.c \ 
			$(HLPDIR)/ft_put_unsigned_nbr.c \
			$(HLPDIR)/ft_putchar.c \
			$(HLPDIR)/ft_puthex.c \
			$(HLPDIR)/ft_putnbr.c \
			$(HLPDIR)/ft_putstr.c

SRC_OBJS = $(addprefix $(OBJDIR)/,$(notdir $(SRC_FILES:.c=.o)))
HLP_OBJS = $(addprefix $(OBJDIR)/,$(notdir $(HLP_FILES:.c=.o)))

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/%.o: $(HLPDIR)/%.c | $(OBJDIR)
    $(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR):
    mkdir -p $(OBJDIR)
clean:
	rm -rf $(OBJDIR)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re