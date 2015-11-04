all: basic_repl polish

basic_repl:
	mkdir -p bin
	clang linenoise.c basic_repl.c -o bin/basic_repl

polish:
	mkdir -p bin
	clang linenoise.c mpc.c polish.c -lm -o bin/polish

clean:
	rm bin/*


