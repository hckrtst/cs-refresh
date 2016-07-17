#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char *s1 = "This cannot be modified";

    /* 
    
    if we accidentally use %s for printing char then we get a nasty runtime error
    
    (lldb) r
    Process 1594 launched: '/Users/sanket/Workspace/cs-refresh/pie/C-gotchas/a.out' (x86_64)
    Process 1594 stopped
    * thread #1: tid = 0x137d5, 0x00007fff9c0cdd32 libsystem_c.dylib`strlen + 18, queue = 'com.apple.main-thread', stop reason = EXC_BAD_ACCESS (code=1, address=0x50)
        frame #0: 0x00007fff9c0cdd32 libsystem_c.dylib`strlen + 18
    libsystem_c.dylib`strlen:
    ->  0x7fff9c0cdd32 <+18>: pcmpeqb (%rdi), %xmm0
        0x7fff9c0cdd36 <+22>: pmovmskb %xmm0, %esi
        0x7fff9c0cdd3a <+26>: andq   $0xf, %rcx
        0x7fff9c0cdd3e <+30>: orq    $-0x1, %rax

    */
    for (int i = 0; i < strlen(s1); i++) {
        printf("%c" ,s1[i]);
    }


    printf("\n");

    /*

    Trying to modify the string s1 causes bad access

        (lldb) r
        Process 1608 launched: '/Users/sanket/Workspace/cs-refresh/pie/C-gotchas/a.out' (x86_64)
        Process 1608 stopped
        * thread #1: tid = 0x13a5e, 0x0000000100000eaf a.out`main(argc=1, argv=0x00007fff5fbffb00) + 111 at c_string_manipulation.c:26, queue = 'com.apple.main-thread', stop reason = EXC_BAD_ACCESS (code=2, address=0x100000f72)
            frame #0: 0x0000000100000eaf a.out`main(argc=1, argv=0x00007fff5fbffb00) + 111 at c_string_manipulation.c:26
           23           printf("%c" ,s1[i]);
           24       }
           25
        -> 26       s1[2] = 'Z';
           27
           28       char s2[] = "This can be modified";
    */
    
    // s1[2] = 'Z';

    char s2[] = "This can be modified";
    s2[3] = 'Z';

    for (int i = 0; i < strlen(s2); i++) {
        printf("%c", s2[i]);
    }

    printf("\n");    

    return 0;	
}