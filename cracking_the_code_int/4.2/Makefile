C = clang++
CFLAGS = -g
SRC = Graph.cpp main.cpp
EXEC = example
DEBUGGER = lldb
WARN = -Wall
LIBS = -lstdc++

all:
	make build
	make run

ifndef V
.SILENT:
endif

build:
	mkdir -p bin
	$(CC) $(CFLAGS) $(WARN) $(LIBS) -o bin/$(EXEC) $(SRC)

run:
	bin/$(EXEC)

dbg:
	$(DEBUGGER) -f bin/$(EXEC)
