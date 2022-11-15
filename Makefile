NAME_ft		=	ft_containers
NAME_std	=	std_containers

CXX		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g3

SRCDIR	= 	testing/
SRCS	=	pair_test.cpp vector_test.cpp map_test.cpp main.cpp

OBJDIR_FT	= 	objs_ft/
OBJDIR_STD	= 	objs_std/
OBJS_FT		=	$(addprefix $(OBJDIR_FT), ${SRCS:.cpp=.o})
OBJS_STD	=	$(addprefix $(OBJDIR_STD), ${SRCS:.cpp=.o})

DEPENDS = 	$(OBJS:.o=.d)
HEADER 	=	includes

all:		${NAME_ft} $(NAME_std)

$(OBJDIR_STD)%.o:	$(SRCDIR)%.cpp
	@mkdir -p $(OBJDIR_STD)
	${CXX} ${CXXFLAGS} -I${HEADER} -MMD -MP -DNS=std -c $< -o $@

$(OBJDIR_FT)%.o:	$(SRCDIR)%.cpp
	@mkdir -p $(OBJDIR_FT)
	${CXX} ${CXXFLAGS} -I${HEADER} -MMD -MP -o $@ -c $<

${NAME_ft}:	${OBJS_FT}
	${CXX} ${CXXFLAGS} ${OBJS_FT} -o ${NAME_ft}

${NAME_std}: ${OBJS_STD}
	${CXX} ${CXXFLAGS} -DNS=std ${OBJS_STD} -o ${NAME_std}

-include $(DEPENDS)

diff:
	./ft_containers vector > output.ft.txt
	./std_containers vector > output.std.txt
	-diff output.ft.txt output.std.txt --color --report-identical-files

clean:
	rm -rf ${OBJDIR_FT}
	rm -rf ${OBJDIR_STD}
	rm -rf output.ft.txt output.std.txt

fclean: clean
	rm -f ${NAME_ft}
	rm -f ${NAME_std}


re : fclean all

.PHONY: all fclean clean re
