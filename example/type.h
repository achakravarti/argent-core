#include <stdio.h>
#include <argent/core.h>


    /* this function gives an example of how to use the arc_bool type */
static void
bool_example(void)
{
    arc_bool b = ARC_BOOL_TRUE;
    printf ("The value of b is %d\n", b);
}


    /* this function gives examples of how to use the arc_word types */
static void
word_example(void)
{
    arc_word w = 0;
    printf ("The value of w is %lu\n", w);

    arc_word_8 w8 = 1;
    printf ("The value of w8 is %u\n", w8);

    arc_word_16 w16 = 5;
    printf ("The value of w16 is %u\n", w16);

    arc_word_32 w32 = 105;
    printf ("The value of w32 is %u\n", w32);

    arc_word_64 w64 = 100005;
    printf ("The value of w64 is %u\n", w64);
}


    /* this function gives examples of how to use the arc_size and arc_index
     * types */
static void
size_example(void)
{
    arc_size s = sizeof (arc_int);
    printf ("The value of s is %lu\n", s);

    arc_index i = 5;
    printf ("The value of i is %lu\n", i);
}


    /* this function gives examples of how to use the arc_uint types */
static void
uint_example(void)
{
    arc_uint u = 0;
    printf ("The value of u is %lu\n", u);

    arc_uint_8 u8 = 1;
    printf ("The value of u8 is %u\n", u8);

    arc_uint_16 u16 = 5;
    printf ("The value of u16 is %u\n", u16);

    arc_uint_32 u32 = 105;
    printf ("The value of u32 is %u\n", u32);

    arc_uint_64 u64 = 100005;
    printf ("The value of u64 is %u\n", u64);
}


    /* this function gives examples of how to use the arc_int types */
static void
int_example(void)
{

    arc_int i = 0;
    printf ("The value of i is %lu\n", i);

    arc_int_8 i8 = 1;
    printf ("The value of i8 is %u\n", i8);

    arc_int_16 i16 = 5;
    printf ("The value of i16 is %u\n", i16);

    arc_int_32 i32 = -105;
    printf ("The value of i32 is %u\n", i32);

    arc_int_64 i64 = 100005;
    printf ("The value of i64 is %lu\n", i64);
}


    /* this function gives examples of how to use the arc_float types */
static void
float_example(void)
{
    arc_float f = 3.14;
    printf ("The value of f is %lf\n", f);

    arc_float_32 f32 = 3.14;
    printf ("The value of f32 is %f\n", f32);

    arc_float_64 f64 = 3.14;
    printf ("The value of f64 is %f\n", f64);
}

