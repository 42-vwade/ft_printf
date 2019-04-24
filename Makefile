
####	CONTROL PANEL	########################################################

NAME		=	libfillit.a
BUILDDIR	=	#	build/
OBJDIR		=	#	obj/
CFILES		=	$(wildcard source/*.c)
LIBFT		=	libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror

####	AUTO SET		########################################################
OBJDIR		:=	$(addprefix $(BUILDDIR), $(OBJDIR))
LIB			:=	$(addprefix $(BUILDDIR), $(LIB))
OBJECTS		:=	$(addprefix $(OBJDIR), $(notdir $(CFILES:.c=.o)))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS) #| $(BUILDDIR)
	@cp $(LIBFT) ./$@
	@ar rcu $@ $(OBJECTS)
	@ranlib $@

$(OBJECTS): $(CFILES) #| $(OBJDIR)
	@make all -C $(<D)

$(LIBFT):
	@make all -C $(@D)

#$(BUILDDIR):
#	@mkdir -p $@
#$(OBJDIR):
#	@mkdir -p $@

clean:
	@rm $(OBJECTS)
	@make clean -C $(dir $(LIBFT))
	@rm -rf *.o

fclean: clean
	@make fclean -C $(dir $(LIBFT))
	@rm -rf $(BUILDDIR) $(NAME)

re: fclean all

.PHONY: clean fclean all re