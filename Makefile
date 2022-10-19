NAME	=	ft_containers
SRCS	=	pair_test.cpp vector_test.cpp main.cpp
OBJS	=	$(addprefix $(OBJDIR), ${SRCS:.cpp=.o})
DEPENDS = 	$(OBJS:.o=.d)
CXX		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g3
HEADER 	=	includes
SRCDIR	= 	testing/
OBJDIR	= 	objs/

all:		${NAME}

$(OBJDIR)%.o:	$(SRCDIR)%.cpp
	@mkdir -p $(OBJDIR)
	${CXX} ${CXXFLAGS} -I${HEADER} -MMD -MP -c $< -o $@

${NAME}:	${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

-include $(DEPENDS)

clean:
	rm -rf ${OBJDIR}

fclean: clean
	rm -f ${NAME}

re : fclean all

.PHONY: all fclean clean re
