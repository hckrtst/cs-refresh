all: basic_repl polish polish2 polish_eval binary_tree

basic_repl:
	mkdir -p bin
	clang linenoise.c basic_repl.c -o bin/basic_repl

polish:
	mkdir -p bin
	clang linenoise.c mpc.c polish.c -lm -o bin/polish

polish2:
	mkdir -p bin
	clang linenoise.c mpc.c polish2.c -lm -o bin/polish2

polish_eval:
	mkdir -p bin
	clang linenoise.c mpc.c polish_eval.c -lm -g -o bin/polish_eval

btree:
	mkdir -p bin
	clang linenoise.c mpc.c btree.c -lm -g -o bin/btree

binary_tree:
	mkdir -p bin
	clang binary_tree.c -lm -lncurses -g -Wall -o bin/binary_tree

ncurses1:
	mkdir -p bin
	clang ncurses1.c -g -Wall -lncurses -o bin/ncurses1

ncurses2:
	mkdir -p bin
	clang ncurses2.c -g -Wall -lncurses -lm -o bin/ncurses2

clean:
	rm bin/*


