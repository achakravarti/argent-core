#include <stdio.h>
#include <argent/core.h>


    /* this function gives an example of how to use the ag_bool type */
static void
bool_example(void)
{
    ag_bool b = AGC_BOOL_TRUE;
    printf ("The value of b is %d\n", b);
}


    /* this function gives examples of how to use the ag_word types */
static void
word_example(void)
{
    ag_word w = 0;
    printf ("The value of w is %lu\n", w);

    ag_word_8 w8 = 1;
    printf ("The value of w8 is %u\n", w8);

    ag_word_16 w16 = 5;
    printf ("The value of w16 is %u\n", w16);

    ag_word_32 w32 = 105;
    printf ("The value of w32 is %u\n", w32);

    ag_word_64 w64 = 100005;
    printf ("The value of w64 is %u\n", w64);
}


    /* this function gives examples of how to use the ag_size and ag_index
     * types */
static void
size_example(void)
{
    ag_size s = sizeof (ag_int);
    printf ("The value of s is %lu\n", s);

    ag_index i = 5;
    printf ("The value of i is %lu\n", i);
}


    /* this function gives examples of how to use the ag_uint types */
static void
uint_example(void)
{
    ag_uint u = 0;
    printf ("The value of u is %lu\n", u);

    ag_uint_8 u8 = 1;
    printf ("The value of u8 is %u\n", u8);

    ag_uint_16 u16 = 5;
    printf ("The value of u16 is %u\n", u16);

    ag_uint_32 u32 = 105;
    printf ("The value of u32 is %u\n", u32);

    ag_uint_64 u64 = 100005;
    printf ("The value of u64 is %u\n", u64);
}


    /* this function gives examples of how to use the ag_int types */
static void
int_example(void)
{

    ag_int i = 0;
    printf ("The value of i is %lu\n", i);

    ag_int_8 i8 = 1;
    printf ("The value of i8 is %u\n", i8);

    ag_int_16 i16 = 5;
    printf ("The value of i16 is %u\n", i16);

    ag_int_32 i32 = -105;
    printf ("The value of i32 is %u\n", i32);

    ag_int_64 i64 = 100005;
    printf ("The value of i64 is %lu\n", i64);
}


    /* this function gives examples of how to use the ag_float types */
static void
float_example(void)
{
    ag_float f = 3.14;
    printf ("The value of f is %lf\n", f);

    ag_float_32 f32 = 3.14;
    printf ("The value of f32 is %f\n", f32);

    ag_float_64 f64 = 3.14;
    printf ("The value of f64 is %f\n", f64);
}


    /* this function gives an example of how to use the ag_string type; see the
     * Argent Abstractions Library for more examples */
static void
string_example(void)
{
    const ag_string *s = "Hello, world!";
    printf ("%s\n", s);
}


