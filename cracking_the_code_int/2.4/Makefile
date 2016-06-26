C = clang++
CFLAGS = -g
SRC = main.cpp
EXEC = example
DEBUGGER = lldb
WARN = -Wall
LIBS = -lstdc++ -lm

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
