
CC= gcc
CPPFLAGS= -MMD 
CFLAGS= -Wall -Wextra -Werror -std=c99 -O2
LDFLAGS=
LDLIBS=

SRC= 1-10.c main.c
OBJ= ${SRC:.c=.o}
DEP= ${SRC:.c=.d}

all: main

main: ${OBJ}

-include ${DEP}

clean:
	rm -f ${OBJ}	${DEP}
	rm -f main

