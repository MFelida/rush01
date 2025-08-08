CC = clang
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -xc

NAME = rush01

SRCFILES = main.c check_utils.c ft_split.c get_rules.c solve.c str_utils.c utils.c 

OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCFILES:.c=.o))

.PHONY: all clean fclean re debug

all: CFLAGS += -O3
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(OBJDIR):
	@mkdir -p $@

clean:
	@rm -rfv $(OBJDIR)

fclean: clean
	@rm -rfv $(NAME)

re: fclean all

debug: CFLAGS += -O0 -gdwarf-2
debug: $(NAME)
