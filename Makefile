NAME = newClass

CC = clang++

CFLAGS = -Wall -Werror -Wextra -std=c++11 -stdlib=libc++

SRCS = ./src/main.cpp \
		./src/Attribute.cpp \
		./src/utils.cpp \
		./src/checkErrors.cpp \
		./src/writeCPP.cpp \
		./src/writeHPP.cpp

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean : 
	$(RM) $(NAME)

re : clean all
