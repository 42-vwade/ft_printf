
CFILES		=	$(filter-out ._*, $(notdir $(wildcard *.c)))
OBJECTS		=	$(notdir $(CFILES:%.c=%.o))


all: $(OBJECTS)
	@mv $^ ../

$(OBJECTS): $(CFILES)
	@gcc -c -Wall -Wextra -Werror $^

clean:
	@rm -rf $(OBJECTS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re