#wildcard把 指定目录 ./下的所有后缀是c的文件全部展开。
SRCS = $(wildcard *.c)
#OBJS将$(SRCS)下的.c文件转化为.o文件
OBJS = $(SRCS:.c = .o)
#代表所使用的编译器
CC = gcc
#CC = arm-linux-gnueabihf-gcc
#头文件查找路径
INCLUDES = -I .
#链接库查找地址
LIBS = ../lib/c-algorithms/scr, ../lib/pt-1.4
#附加参数
CCFLAGS = -g -Wall -O0
#输出程序名称
OUTPUT = serial.out
all:$(OUTPUT)
$(OUTPUT) : $(OBJS)
	$(CC) $^ -o $@ $(INCLUDES) $(LIBS)
%.o : %.c
	$(CC) -c $< $(CCFLAGS)
#清除中间文件及生成文件
.PHONY:clean
clean:
	rm -rf *.out *.o



