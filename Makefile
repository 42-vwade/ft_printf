
####	CONTROL PANEL	########################################################

NAME		=	fillit
LIB			=	libfillit.a
BUILDDIR	=	#	build/
OBJDIR		=	#	obj/
CFILES		=	source/fillit.c \
				source/map_func.c \
				source/readfile.c \
				source/tetra_func.c \
				source/validation.c
LIBFT		=	includes/libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror

####	AUTO SET		########################################################
OBJDIR		:=	$(addprefix $(BUILDDIR), $(OBJDIR))
LIB			:=	$(addprefix $(BUILDDIR), $(LIB))
OBJECTS		:=	$(addprefix $(OBJDIR), $(notdir $(CFILES:.c=.o)))

all: $(NAME)

$(NAME): $(LIB) $(LIBFT) #| $(BUILDDIR)
	@gcc -o $@ $(CFLAGS) $^

$(LIB): $(OBJECTS)
	@ar rc $@ $^
	@ranlib $@

$(OBJECTS): $(CFILES) #| $(OBJDIR)
	@cd $(<D) && make re

$(LIBFT):
	@cd $(@D) && make re

#$(BUILDDIR):
#	@mkdir -p $@
#$(OBJDIR):
#	@mkdir -p $@

clean:
	@cd includes/libft/ && make clean
	@rm -rf $(OBJDIR) $(LIBFT)
	@rm -rf *.o

fclean: clean
	@cd includes/libft/ && make fclean
	@rm -rf $(BUILDDIR) $(NAME) $(LIB)

re: fclean all

.PHONY: clean fclean all re