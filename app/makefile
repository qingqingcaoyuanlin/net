target = netthread
OBJS = main.o thread.o
HEADERS =
CC = gcc
CFLAG = -lpthread
all:${target}
${target}:${OBJS}
	${CC} ${CFLAG} -o $@ $^
#${OBJS}:%.o:%.c
..c.o:
	${CC} -c ${CFLAG} $<
.PHONY:clean
clean:
	rm ${all} ${OBJS}
fuck:
	gcc main.c thread.c -lpthread -o netthread