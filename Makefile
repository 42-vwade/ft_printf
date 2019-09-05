
########################################################	MAIN MAKEFILE	####
####	CONTROL PANEL	########################################################

NAME		=	libftprintf.a
BUILDDIR	=	#	build/
OBJDIR		=	obj/
SOURCEDIR	=	source/
CFILES		=	$(shell find ./source ! -name "._*" -regex ".*\\.[c]")
LIBFT		=	libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror

####	AUTO SETTING	########################################################

OBJDIR		:=	$(addprefix $(BUILDDIR), $(OBJDIR))
LIB			:=	$(addprefix $(BUILDDIR), $(dir $(LIBFT)))
OBJECTS		:=	$(addprefix $(OBJDIR), $(notdir $(CFILES:.c=.o)))
OBJECTS		=	$(shell find ./obj ! -name "._*" -regex ".*\\.[o]")

####	UNDER THE HOOD	########################################################

all: $(NAME)

#	BUILD PROJECT FOR TESTING PURPOSES ONLY
#	WE DO NOT NEED OBJECT FILES TO TEST THE PROJECT
build: $(CFILES) $(shell find ./libft ! -name ".*" -regex ".*\\.[c]") main.c
	@echo "Build initiated ..."
	@gcc -g $(CFLAGS) $^
#	./a.out

#	MAKE THE PROJECT FILE
$(NAME): $(LIBFT) $(OBJECTS) #| $(BUILDDIR)
	@ar rcu $@ $(OBJDIR)/*.o
	@ranlib $@

#	GET OBJECT FILES FROM PROJECT SOURCE DIRECTORY
$(OBJECTS): $(CFILES) | $(OBJDIR)
	@make all -C $(SOURCEDIR)

#	MAKE LIBFT // WE DO NOT NEED IT FOR PROJECT LIB. ONLY .O FILES
#	MOVE CREATED .O FILES INTO OBJECT DIRECTORY
$(LIBFT): | $(OBJDIR)
	@make all -C $(@D)
	@mv $(@D)/obj/*.o $(OBJDIR)/

#$(BUILDDIR):
#	@mkdir -p $@

#	IF NOT EXIST - OBJECT DIRECTORY - THEN CREATE IT
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