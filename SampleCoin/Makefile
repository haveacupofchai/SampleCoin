CC = g++
CFLAGS = -Wall -g -std=c++11 -pthread

INC_DIR = include/
INCLUDES = -I$(INC_DIR)
# LFLAGS = -L/blah/blah/lib  -L../lib
# LIBS = -lrt -lm

SRCS = src/Node/NodeCore.cpp src/Client/ClientNode.cpp src/Client/Client.cpp src/Client/CaptureClient.cpp src/main.cpp \
       src/utils/utils.cpp
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
