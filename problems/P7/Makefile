CC = clang
CFLAGS = -g
SRC = p7.c
EXEC = p7
DEBUGGER = lldb

all:
	make build
	make run

ifndef V
.SILENT:
endif

build:
	mkdir -p bin
	$(CC) $(CFLAGS) -o bin/$(EXEC) $(SRC) -I.

run:
	bin/$(EXEC)

dbg:
	$(DEBUGGER) -f bin/$(EXEC)