TARGET		:= ex01

CC			:= g++
CFLAGS		:= -Wall -Wextra -Werror -g -std=c++20

SRC_DIR		:= .
SRCS		:= $(patsubst %, $(SRC_DIR)/%, main.cpp)

OBJ_DIR		:= obj
OBJS		:= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

DEP_DIR		:= dep
DEPS		:= $(SRC:$(SRC_DIR)/%.cpp=$(DEP_DIR)/%.d)

all: $(TARGET)

$(TARGET): $(OBJS)
			$(CC) $(CFLAGS) -o $@ $^

-include $(DEPS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR) $(DEP_DIR)
			$(CC) $(CFLAGS) -o $@ -MMD -MF $(DEP_DIR)/$*.d -c $<

clean:
			$(RM) $(OBJS)

fclean:	clean
			$(RM) $(TARGET)

re:	fclean
			$(MAKE) --no-print-directory all

.PHONY:	all clean fclean re