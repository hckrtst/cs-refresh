all:
	make build 
	make run

build: palindrome.c myitoa.c
	clang -g palindrome.c myitoa.c -I.

run:
	./a.out

dbg:
	lldb -f a.out


