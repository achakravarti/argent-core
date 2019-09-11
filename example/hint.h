#include <argent/core.h>


/* This is how you would declare a hot function. */
extern agc_hot void
foo_hot(int x);


/* This is how you would declare a cold function. */
static agc_cold void
bar_cold(int y);


/* This is how you would declare a pure function. Note that foo_hot() and
 * bar_cold() could also have been declared as pure. */
extern agc_pure int
foobar_pure(int x, int y);


/* The hot function shows how you would indicate a likely predicate. */
void
foo_hot(int x)
{
    if (agc_likely (x != 0))
        printf("x = %d\n", x);
}


/* The cold function shows how you would indicate an unlikely predicate. */
void
bar_cold(int y)
{
    if (agc_unlikely (y > 1))
        printf("y = %d\n", y);
}


/* foobar_pure() shows how it qualifies for being declared pure by returning the
 * same value for the same arguments without any side effects. */
int
foobar_pure(int x, int y)
{
    return x + y;
}

