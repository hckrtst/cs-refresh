all: basic_repl polish polish2

basic_repl:
	mkdir -p bin
	clang linenoise.c basic_repl.c -o bin/basic_repl

polish:
	mkdir -p bin
	clang linenoise.c mpc.c polish.c -lm -o bin/polish

polish2:
	mkdir -p bin
	clang linenoise.c mpc.c polish2.c -lm -o bin/polish2

clean:
	rm bin/*


