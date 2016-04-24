all:
	make build 
	make run

build: c-string-manip
	clang -g c_string_manipulation.c -I.

build: buffer-test
	clang -g getchar_test.c -I.

run:
	./a.out

dbg:
	lldb -f a.out