CC = g++
CFLAGS = -Wall -g

INC_DIR = include/
INCLUDES = -I$(INC_DIR)
# LFLAGS = -L/blah/blah/lib  -L../lib
# LIBS = -lrt -lm

SRCS = src/BlockChain/Blockchain.cpp src/Block/Block.cpp src/main.cpp \
       src/StateTree/StateTree.cpp src/utils/utils.cpp src/CoreManager/CoreManager.cpp
OBJS = $(SRCS:.c=.o)
MAIN = run
.PHONY: clean

all:    $(MAIN)

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

# .c.o:
#      $(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	rm -rf *.o *~ $(MAIN)
