#include <stdio.h>
#include <argent/core.h>


    /* this is an example showing how you would used use the ag_compiler() macro
     * to determine the compiler being used */
int
main(void)
{
#if AG_COMPILER_GNUC == ag_compiler ()
    printf ("GNU C compiler detected.\n");

#elif AG_COMPILER_CLANG == ag_compiler ()
    printf ("LLVM Clang compiler detected.\n");
#endif
    return 0;
}

