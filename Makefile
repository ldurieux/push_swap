NAME		= 

CHECKERNANE	= checker

PUSHSWAPNANE	= push_swap

CCDEFS		= \

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
			  srcs/ft_normalize_numbers.c \
			  
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
			  srcs/push_swap/prepare_stacks.c \
			  srcs/push_swap/ft_is_roughly_sorted.c \

ASMSRCS		= \

LIB_NAMES	= \
			  libft \

HEADERS		= \
			  includes \

LIBS		= $(subst lib,-l,$(notdir $(LIB_NAMES)))
LIB_LD		= $(foreach lib,$(LIB_NAMES),-L$(lib))
LIB_PATHS	= $(foreach lib,$(LIB_NAMES),$(lib)/$(notdir $(lib)).a)
LIB_HEADERS	= $(foreach lib,$(LIB_NAMES),-I$(lib)/includes/)

CCDEFSFLGS	= $(foreach def,$(CCDEFS),-D $(def))

BUILDDIR	= build
OBJS		= $(SRCS:%.c=$(BUILDDIR)/%.o) $(ASMSRCS:%.s=$(BUILDDIR)/%.o)
DEPS		= $(SRCS:%.c=$(BUILDDIR)/%.d)
CHECKEROBJS		= ${CHECKERSRCS:%.c=$(BUILDDIR)/%.o}
CHECKERDEPS		= ${CHECKERSRCS:%.c=$(BUILDDIR)/%.d}
PUSHSWAPDEPS	= ${PUSHSWAPSRCS:%.c=$(BUILDDIR)/%.d}
PUSHSWAPOBJS	= ${PUSHSWAPSRCS:%.c=$(BUILDDIR)/%.o}
CC			= cc
CCWFLGS		= -Wall -Wextra -Werror -O2 #-fsanitize=address -g
CCDBGFLGS	= -fsanitize=address -g
CCO1FLGS	= -O1 -march=native
CCO2FLGS	= -O2 -march=native
CCO3FLGS	= -O3 -march=native
DEPSFLAGS	= -MMD -MP
RM			= rm -Rf
MAKE		= make -C
MKDIR		= mkdir
AR			= ar
ARFLAGS		= rcs
NASM		= nasm
NASMFLAGS	= -felf64

all : libs $(CHECKERNANE) $(PUSHSWAPNANE)

$(CHECKERNANE) : $(LIB_PATHS) $(OBJS) $(CHECKEROBJS)
		$(CC) $(CCWFLGS) -o $(CHECKERNANE) $(OBJS) $(CHECKEROBJS) $(LIB_LD) $(LIBS)
		
$(PUSHSWAPNANE) : $(LIB_PATHS) $(OBJS) $(PUSHSWAPOBJS)
		$(CC) $(CCWFLGS) -o $(PUSHSWAPNANE) $(OBJS) $(PUSHSWAPOBJS) $(LIB_LD) $(LIBS)

bonus : $(CHECKERNANE) $(PUSHSWAPNANE)

libs :
		$(foreach lib, $(LIB_NAMES), \
			$(MAKE) $(lib); \
		)

clean :
		-$(RM) $(BUILDDIR)

fclean : clean
		$(foreach lib, $(LIB_NAMES), \
			$(MAKE) $(lib) fclean; \
		)
		-$(RM) $(CHECKERNANE) $(PUSHSWAPNANE)

re : fclean all

$(BUILDDIR)/%.o : %.s Makefile $(LIB_PATHS)
		mkdir -p $(@D)
		$(NASM) $(NASMFLAGS) -o $(BUILDDIR)/$@ $<

-include $(DEPS)

$(BUILDDIR)/%.o : %.c Makefile $(LIB_PATHS)
		mkdir -p $(@D)
		$(CC) $(CCWFLGS) $(DEPSFLAGS) $(CCDEFSFLGS) -I$(HEADERS) $(LIB_HEADERS) -c $< -o $@

.PHONY: all clean fclean re bonus libs

