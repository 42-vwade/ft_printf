
####	CONTROL PANEL	########################################################

NAME		=	libft.a
SRCDIR		=	
HDRDIR		=	
OBJDIR		=	
LIBDIR		=	
TMPDIR		=	.tmp/
CFILES		=	./ft_bzero.c ./ft_memccpy.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c ./ft_memset.c ./ft_strlen.c ./ft_strdup.c ./ft_strcpy.c ./ft_strncpy.c ./ft_strcat.c ./ft_strncat.c ./ft_strlcat.c./ft_strchr.c ./ft_strrchr.c ./ft_strstr.c ./ft_strnstr.c ./ft_strcmp.c ./ft_strncmp.c ./ft_atoi.c ./ft_isalpha.c ./ft_isdigit.c ./ft_isalnum.c ./ft_isascii.c ./ft_isprint.c ./ft_toupper.c ./ft_tolower.c ./ft_memalloc.c ./ft_memdel.c ./ft_strnew.c ./ft_strdel.c ./ft_strclr.c ./ft_striter.c ./ft_striteri.c ./ft_strmap.c ./ft_strmapi.c ./ft_strequ.c ./ft_strnequ.c ./ft_strsub.c ./ft_strjoin.c ./ft_strtrim.c ./ft_strsplit.c ./ft_itoa.c ./ft_putchar.c ./ft_putstr.c ./ft_putendl.c ./ft_putnbr.c ./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_lstnew.c \./ft_lstdelone.c ./ft_lstdel.c ./ft_lstadd.c ./ft_lstiter.c ./ft_lstmap.c
CFILES		=	$(filter-out ._*, $(notdir $(wildcard *.c)))
ACFILES		+=	$(shell find added_functions -name '*.c')
#CFILES		:=	$(notdir $(CFILES))
HFILES		=	libft.h
CFLAGS		:=	-c -Wall -Werror -Wextra
CC			:=	gcc 
AR			=	ar rc
LIB			=	$(addprefix $(LIBDIR), libft.a)
SOURCES		=	$(addprefix $(SRCDIR), $(CFILES))
OBJECTS		=	$(addprefix $(OBJDIR), $(notdir $(CFILES:%.c=%.o)))
AOBJECTS	=	$(addprefix $(OBJDIR), $(notdir $(ACFILES:%.c=%.o)))
HEADERS		= 	$(addprefix $(HDRDIR), $(HFILES))
DEBUG		=	0;

####	FONT FORMAT		########################################################

FM0 = \033[0m#		NO FORMAT
FMB = \033[1m#		BOLD FONT
FMR = \033[31m#		RED COLOR
FMM = \e[35m#		MAGENTA COLOR

####	UNDER THE HOOD	########################################################

all: $(NAME)

$(NAME): $(OBJECTS) $(AOBJECTS) | $(TMPDIR)
	@ar rc $@ $^
	@ranlib $@
#	@mv $^ $(TMPDIR)

$(OBJECTS): $(CFILES)
	@gcc $(CFLAGS) $^
$(AOBJECTS): $(ACFILES)
	@cd added_functions && make all

$(TMPDIR):
	@mkdir -p $@

clean:
	@cd added_functions && make clean
	@rm -rf $(TMPDIR)
	@rm -rf *.o

fclean: clean
	@cd added_functions && make fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
