
########################################################	MAIN MAKEFILE	####
####	CONTROL PANEL	########################################################

NAME		=	libftprintf.a
BUILDDIR	=	#	build/
OBJDIR		=	obj/
SOURCEDIR	=	source/
MAINFILE	=	.main
MAINLINK	=	../ft_printf_maintest_edit.c
MAINOBJ		=	main.o
CFILES		=	$(shell find ./source ! -name "._*" -regex ".*\\.[c]")
LFILES		=	$(shell find ./libft ! -name "._*" -regex ".*\\.[c]")
LIBFT		=	libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror

####	AUTO SETTING	########################################################

OBJDIR		:=	$(addprefix $(BUILDDIR), $(OBJDIR))
LIB			:=	$(addprefix $(BUILDDIR), $(dir $(LIBFT)))
OBJECTS		:=	$(addprefix $(OBJDIR), $(notdir $(CFILES:.c=.o)))
OBJECTS		:=	$(OBJECTS) $(addprefix $(OBJDIR), $(notdir $(LFILES:.c=.o)))
SUBMODULE	:=	$(dir $(LIBFT))/.sub
####	UNDER THE HOOD	########################################################

all: $(NAME)

#	BUILD PROJECT FOR TESTING PURPOSES ONLY
#	WE DO NOT NEED OBJECT FILES TO TEST THE PROJECT
build: $(CFILES) $(LFILES) $(MAINLINK)
#build: $(NAME) $(MAINOBJ)
	@echo "Build initiated ..."
	@cp -rf $(MAINLINK) ./
	@gcc -o "a.test" -g $(CFLAGS) $(CFILES) $(LFILES) ./$(notdir $(MAINLINK))
	@rm -rf ./$(notdir $(MAINLINK))
# 	-fsanitize=address
#	@gcc -g -L. -lftprintf -fsanitize=address $(CFLAGS) $^
#	./a.out

#	REAL BUILD & TEST OF ACTUAL FINISHED WORK
test: $(NAME) $(MAINOBJ)
	@gcc -o "a.test" -g $(CFLAGS) $< "main.o"
#	./a.test

#	MAKE THE PROJECT FILE
$(NAME): $(LIBFT) $(OBJECTS) #| $(BUILDDIR)
	@ar rcu $@ $(OBJDIR)/*.o
	@ranlib $@

#	GET OBJECT FILES FROM PROJECT SOURCE DIRECTORY
$(OBJECTS): $(CFILES) | $(OBJDIR)
	@make all -C $(SOURCEDIR)

#	MAKE LIBFT // WE DO NOT NEED IT FOR PROJECT LIB. ONLY .O FILES
#	MOVE CREATED .O FILES INTO OBJECT DIRECTORY
$(LIBFT): $(SUBMODULE) | $(OBJDIR)
	@make all -C $(@D)
	@mv $(@D)/obj/*.o $(OBJDIR)/

$(MAINOBJ): $(MAINFILE) | $(MAINLINK)
	@mv $(MAINFILE) "main.c"; gcc -c main.c; mv "main.c" $(MAINFILE)

$(MAINLINK): $(MAINFILE)
	@if [ -e $@ ] ; then rm $@; fi
	@ln $< $@

#$(BUILDDIR):
#	@mkdir -p $@

#	IF NOT EXIST - OBJECT DIRECTORY - THEN CREATE IT
$(OBJDIR):
	@mkdir -p $@

$(SUBMODULE):
#	@if git submodule status | egrep -q '^[-]|^[+]' ; then \
            echo "INFO: Need to reinitialize git submodules"; \
            git submodule update --init --recursive; \
    fi
#	CREDIT: https://bit.ly/2lxmAEO
	@if git submodule status | egrep -q '^[-]|^[+]' ; then \
		git submodule update --init --recursive; \
		touch $@; \
	fi
#	@git submodule update --init --recursive

clean:
	@make clean -C $(dir $(LIBFT))
	@rm -rf $(OBJDIR) *.o

fclean: clean
	@make fclean -C $(dir $(LIBFT))
	@rm -rf $(BUILDDIR) $(NAME)

re: fclean all

.PHONY: clean fclean all re