target = netthread
OBJS = main.o thread.o
HEADERS =
CC = gcc
CFLAG = -lpthread
all:${target}
${target}:${OBJS}
	${CC}  -o $@ $^ ${CFLAG}#cao ,为什么这个${CFLAG}要放在最后才可以啊
#${OBJS}:%.o:%.c
..c.o:
	${CC} -c  $<
.PHONY:clean
clean:
	rm ${target} ${OBJS}
fuck:
	gcc main.c thread.c -lpthread -o netthread