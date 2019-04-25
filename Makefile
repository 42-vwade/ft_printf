
########################################################	MAIN MAKEFILE	####
####	CONTROL PANEL	########################################################

NAME		=	libfillit.a
BUILDDIR	=	#	build/
OBJDIR		=	obj/
CFILES		=	$(wildcard source/*.c)
LIBFT		=	libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror

####	AUTO SET		########################################################
OBJDIR		:=	$(addprefix $(BUILDDIR), $(OBJDIR))
LIB			:=	$(addprefix $(BUILDDIR), $(LIB))
OBJECTS		:=	$(addprefix $(OBJDIR), $(notdir $(CFILES:.c=.o)))

all: $(NAME)
:wildcard
build: $(CFILES) $(LIBFT) main.c
	gcc -g $^

$(NAME): $(LIBFT) $(OBJECTS) #| $(BUILDDIR)
	#@cp $(LIBFT) ./$@
	@ar rcu $@ $(OBJDIR)/*.o
	@ranlib $@

$(OBJECTS): $(CFILES) | $(OBJDIR)
	@make all -C $(<D)
	@mv ./*.o $(OBJDIR)

$(LIBFT): | $(OBJDIR)
	@make all -C $(@D)
	@mv $(@D)/*.o $(OBJDIR)/

#$(BUILDDIR):
#	@mkdir -p $@
$(OBJDIR):
	@mkdir -p $@

clean:
	@rm -rf *.o
	@rm -rf $(OBJDIR)
	@make clean -C $(dir $(LIBFT))


fclean: clean
	@make fclean -C $(dir $(LIBFT))
	@rm -rf $(BUILDDIR) $(NAME)

re: fclean all

.PHONY: clean fclean all re