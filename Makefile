NAME_ft		=	ft_containers
NAME_std	=	std_containers

CXX		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g3

SRCDIR	= 	testing/
SRCS	=	pair_test.cpp vector_test.cpp map_test.cpp main.cpp
OBJS	=	$(addprefix $(OBJDIR), ${SRCS:.cpp=.o})
DEPENDS = 	$(OBJS:.o=.d)
HEADER 	=	includes
OBJDIR	= 	objs/
NS = 0

all:		${NAME_ft} $(NAME_std)

# ./objs/ft_containers.o:	$(SRCDIR)%.cpp
# 	@mkdir -p $(OBJDIR)
# 	${CXX} ${CXXFLAGS} -I${HEADER} -MMD -MP -c $< -D NS=0 -o $@

$(OBJDIR)%.o:	$(SRCDIR)%.cpp
	@mkdir -p $(OBJDIR)
	${CXX} ${CXXFLAGS} -I${HEADER} -MMD -MP -o $@ -c $< -D NS=1

$(OBJDIR)%.o:	$(SRCDIR)%.cpp
	@mkdir -p $(OBJDIR)
	${CXX} ${CXXFLAGS} -I${HEADER} -MMD -MP -c $< -o $@

${NAME_ft}:	${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -D NS=0 -o ${NAME_ft}

${NAME_std}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -D NS=1 -o ${NAME_std}

-include $(DEPENDS)

diff:
	./ft_containers vector > output.ft.txt
	./std_containers vector > output.std.txt
	-diff output.ft.txt output.std.txt --color --report-identical-files
	# rm -rf output.ft.txt output.std.txt
	# $(MAKE) --quiet fclean

clean:
	rm -rf ${OBJDIR}

fclean: clean
	rm -f ${NAME_ft}
	rm -f ${NAME_std}

re : fclean all

.PHONY: all fclean clean re
