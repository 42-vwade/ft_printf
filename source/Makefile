
CFILES		=	$(filter %.c, $(filter-out ._%, $(notdir $(wildcard *))))
OBJECTS		=	$(notdir $(CFILES:%.c=%.o))


all: $(OBJECTS)
	@yes | mv -f $^ ../

$(OBJECTS): $(CFILES)
	@gcc -c -Wall -Wextra -Werror $^

clean:
	@rm -rf $(OBJECTS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re