#include <stdio.h>
#include <argent/core.h>


    /* this is how you would declare a hot function */
extern ag_hot void
foo_hot(int x);


    /* this is how you would declare a cold function */
static ag_cold void
bar_cold(int y);


    /* this is how you would declare a pure function; note that foo_hot() and
     * bar_cold() could also have been declared as pure */
extern ag_pure int
foobar_pure(int x, int y);


    /* this hot function shows how you would indicate a likely predicate */
void
foo_hot(int x)
{
    if (ag_likely (x != 0))
        printf("x = %d\n", x);
}


    /* this cold function shows how you would indicate an unlikely predicate */
void
bar_cold(int y)
{
    if (ag_unlikely (y > 1))
        printf("y = %d\n", y);
}


    /* foobar_pure() shows how it qualifies for being declared pure by returning
     * the same value for the same arguments without any side effects */
int
foobar_pure(int x, int y)
{
    return x + y;
}

