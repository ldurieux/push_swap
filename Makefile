NAME		= 

SRCS 		= \
			  srcs/ft_stacks/delete.c \
			  srcs/ft_stacks/is_sorted.c \
			  srcs/ft_stacks/new.c \
			  srcs/ft_stacks/print.c \
			  srcs/ft_stacks/push.c \
			  srcs/ft_stacks/reverse_rotate.c \
			  srcs/ft_stacks/rotate.c \
			  srcs/ft_stacks/swap.c \
			  srcs/ft_parse_numbers.c \
			  srcs/ft_sort_merge.c \
			  srcs/ft_put_instruction_fd.c \
			  
CHECKERSRCS	= \
			  checker_main.c \
			  srcs/checker/checker.c \
			  srcs/checker/checker_interactive.c \
			  srcs/checker/ft_get_instructions.c \
			  srcs/checker/ft_get_next_line.c \
			  srcs/checker/ft_get_options.c \
			  srcs/checker/ft_str_to_instruction.c \
			  srcs/ft_stacks/checker_execute.c \

PUSHSWAPSRCS	= \
			  push_swap_main.c \
			  srcs/push_swap/push_swap.c \
			  srcs/push_swap/ft_is_sorted.c \
			  srcs/ft_stacks/push_swap_execute.c \
			  srcs/push_swap/ft_insert_next.c \
			  srcs/push_swap/ft_rotate_by.c \
			  srcs/push_swap/ft_find_lowest.c \
			  srcs/push_swap/ft_rotate_sort.c \
			  srcs/push_swap/ft_is_roughly_sorted.c \

ASMSRCS		= \

LIB_NAMES 	= \
			  libft \
			  libftcont \
			  
HEADERS		= \
			  includes \

LIBS		= $(subst lib,-l,$(notdir $(LIB_NAMES)))
LIB_LD		= $(foreach lib,$(LIB_NAMES),-L$(lib))
LIB_PATHS	= $(foreach lib,$(LIB_NAMES),$(lib)/$(notdir $(lib)).a)
LIB_HEADERS	= $(foreach lib,$(LIB_NAMES),-I$(lib)/includes/)

CHECKEROBJS		= ${CHECKERSRCS:.c=.o}
CHECKERDEPS		= ${CHECKERSRCS:.c=.d}
PUSHSWAPDEPS	= ${PUSHSWAPSRCS:.c=.d}
PUSHSWAPOBJS	= ${PUSHSWAPSRCS:.c=.o}
OBJS			= ${SRCS:.c=.o} $(ASMSRCS:.s=.o)
DEPS			= ${SRCS:.c=.d}
CC				= gcc -no-pie
CCWFLGS			= -Wall -Wextra
CCDBGFLGS		= -fsanitize=address -g
CCO1FLGS		= -O1 -march=native
CCO2FLGS		= -O2 -march=native
CCO3FLGS		= -O3 -march=native
DEPSFLAGS		= -MMD -MP
RM				= rm -f
MAKE			= make -C
AR				= ar
ARFLAGS			= rc
NASM			= nasm
NASMFLAGS		= -felf64

.PHONY: all clean fclean re

all : checker push_swap

checker : $(LIB_PATHS) $(OBJS) $(CHECKEROBJS)
		$(CC) $(CCWFLAGS) $(CCDBGFLGS) -I$(HEADERS) $(LIB_HEADERS) -o $@ $(CHECKEROBJS) $(OBJS) $(LIB_LD) $(LIBS)

push_swap : $(LIB_PATHS) $(OBJS) $(PUSHSWAPOBJS)
		$(CC) $(CCWFLAGS) $(CCDBGFLGS) -I$(HEADERS) $(LIB_HEADERS) -o $@ $(PUSHSWAPOBJS) $(OBJS) $(LIB_LD) $(LIBS)

$(LIB_PATHS) :
		$(MAKE) $(dir $@)

clean :
		-$(RM) $(OBJS) $(DEPS) $(CHECKEROBJS) $(CHECKERDEPS) $(PUSHSWAPOBJS) $(PUSHSWAPDEPS)

fclean : clean
		$(foreach lib, $(LIB_NAMES), \
			$(MAKE) $(lib) fclean; \
		)
		-$(RM) $(NAME) checker push_swap

re : fclean all

%.o : %.asm Makefile
		$(NASM) $(NASMFLAGS) -o $@ $<

-include $(DEPS)

%.o : %.c Makefile
		$(CC) $(CCWFLAGS) $(CCDBGFLGS) $(DEPSFLAGS) -I$(HEADERS) $(LIB_HEADERS) -c $< -o $@ $(LIB_LD) $(LIBS)
