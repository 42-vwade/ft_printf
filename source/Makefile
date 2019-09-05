
########################################################	AUX MAKEFILE	####
####	CONTROL PANEL	########################################################

CFILES		:=	$(shell find . ! -name "._*" -regex ".*\\.[c]")
OBJECTS		:=	$(notdir $(CFILES:%.c=%.o))
OBJDIR		=	../obj/

####	UNDER THE HOOD	########################################################

all: $(OBJECTS) | $(OBJDIR)
	@yes | mv -f $^ $(OBJDIR)

$(OBJECTS): $(CFILES)
	@gcc -c -Wall -Wextra -Werror $^

$(OBJDIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re