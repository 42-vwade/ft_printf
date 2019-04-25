
########################################################	MAIN MAKEFILE	####
####	CONTROL PANEL	########################################################

NAME		=	libftprintf.a
BUILDDIR	=	#	build/
OBJDIR		=	obj/
CFILES		=	$(shell find ./source ! -name "._*" -regex ".*\\.[c]")
LIBFT		=	libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror

####	AUTO SETTING	########################################################

OBJDIR		:=	$(addprefix $(BUILDDIR), $(OBJDIR))
LIB			:=	$(addprefix $(BUILDDIR), $(dir $(LIBFT)))
OBJECTS		:=	$(addprefix $(OBJDIR), $(notdir $(CFILES:.c=.o)))

####	UNDER THE HOOD	########################################################

all: $(NAME)

build: $(CFILES) $(LIBFT) main.c
	gcc -g $^

$(NAME): $(LIBFT) $(OBJECTS) #| $(BUILDDIR)
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
	@make clean -C $(dir $(LIBFT))
	@rm -rf *.o
	@rm -rf $(OBJDIR)


fclean: clean
	@make fclean -C $(dir $(LIBFT))
	@rm -rf $(BUILDDIR) $(NAME)

re: fclean all

.PHONY: clean fclean all re