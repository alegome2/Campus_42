NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

UTILSDIR	= ft_utils
OBJDIR		= obj

SRCS		= main.c \
			  parser.c \
			  parser_utils.c \
			  parser_flags.c \
			  error.c \
			  stack_utils.c \
			  indexing.c \
			  disorder.c \
			  bench.c \
			  router.c \
			  push.c \
			  swap.c \
			  rotate.c \
			  rev_rotate.c \
			  sort_small.c \
			  sort_simple.c \
			  sort_medium.c \
			  sort_complex.c \
			  start_to_zero.c \
			  $(UTILSDIR)/ft_itoa.c \
			  $(UTILSDIR)/ft_split.c \
			  $(UTILSDIR)/ft_putnbr_fd.c \
			  $(UTILSDIR)/ft_putstr_fd.c \
			  $(UTILSDIR)/ft_strdup.c \
			  $(UTILSDIR)/ft_strlen.c \
			  $(UTILSDIR)/ft_substr.c\
			  $(UTILSDIR)/ft_strcmp.c

OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.c push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re