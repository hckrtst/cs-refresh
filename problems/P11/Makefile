CC = clang
CFLAGS = -g
SRC = p11.c
EXEC = p11
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
