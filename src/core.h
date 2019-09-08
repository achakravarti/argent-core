#if !defined ARGENT_CORE
#define ARGENT_CORE


/**************************************************************************//**
 * @defgroup hint Argent Core Hint Module
 * Compiler hints for optimisation.
 *
 * Compilers such as GCC have always focused aggressively on optimisation. Many
 * such optimisations have been introduced as compiler-specific extensions that
 * are @b not part of the C standards.
 *
 * The Hint Module abstracts such optimisations as conditional macros so that
 * they they can be taken advantage of in GCC and GCC-compatible compilers such
 * as Clang, but at the same time degrade safely on other compilers.
 * @{
 */


/**
 * Hints that a function is pure.
 *
 * The @c arc_pure macro is used to decorate the declaration of a pure function.
 * A pure function is one that always returns the same value for the same
 * arguments without any side effects. This hint follows the GCC attribute
 * syntax, and is recommended to be placed in the function declaration just
 * before the function return type.
 *
 * @warning This hint is available only on GCC and GCC-compatible compilers such
 * as Clang; on other compilers, this macro degrades with a warning that it has
 * no effect.
 */
#if (defined __GNUC__ || defined __clang__)
#   define arc_pure __attribute__((pure))
#else
#   define arc_pure
#   warning arc_pure has no effect on non GCC-compatible compilers
#endif


/**
 * Hints that a function is called frequently.
 *
 * The @c arc_hot macro is used to decorate a function declaration in order to
 * indicate that it is called frequently. This hint follows the GCC attribute
 * syntax, and is recommended to be placed in the function declaration just
 * before the function return type.
 *
 * @warning This hint is available only on GCC and GCC-compatible compilers such
 * as Clang; on other compilers, this macro degrades with a warning that it has
 * no effect.
 *
 * @see arc_cold
 */
#if (defined __GNUC__ || defined __clang__)
#   define arc_hot __attribute__((hot))
#else
#   define arc_hot
#   warning arc_hot has no effect on non GCC-compatible compilers
#endif


/**
 * Hints that a function is called infrequently.
 *
 * The @c arc_cold macro is used to decorate a function declaration in order to
 * indicate that is called infrequently. This hint follows the GCC attribute
 * syntax, and is recommended to be placed in the function declaration just
 * before the function return type.
 *
 * @warning This hint is available only on GCC and GCC-compatible compilers such
 * as Clang; on other compilers, this macro degrades with a warning that it has
 * no effect.
 *
 * @see arc_hot
 */
#if (defined __GNUC__ || defined __clang__)
#   define arc_cold __attribute__((cold))
#else
#   define arc_cold
#   warning arc_cold has no effect on non GCC-compatible compilers
#endif


/**
 * Hints that a predicate is likely to be true.
 *
 * The @c arc_likely() macro indicates that a predicate expression @p p is @b
 * likely to evaluate to @c true. This hint has been modelled after the @c
 * likely() macro used in the Linux kernel source.
 *
 * @param p predicate expected to be true.
 *
 * @warning This hint is available only on GCC and GCC-compatible compilers such
 * as Clang; on other compilers, this macro degrades with a warning that it has
 * no effect.
 *
 * @see arc_unlikely()
 */
#if (defined __GNUC__ || defined __clang__)
#   define arc_likely(p) (__builtin_expect(!!(p), 1))
#else
#   define arc_likely
#   warning arc_likely has no effect on non GCC-compatible compilers
#endif


/**
 * Hints that a predicate is likely to be false.
 *
 * The @c arc_unlikely() macro indicates that a predicate expression @p p is @b
 * unlikely to evaluate to @c false. This hint has been modelled after the @c
 * unlikely() macro used in the Linux kernel source.
 *
 * @param p predicate expected to be false.
 *
 * @warning This hint is available only on GCC and GCC-compatible compilers such
 * as Clang; on other compilers, this macro degrades with a warning that it has
 * no effect.
 *
 * @see arc_likely()
 */
#if (defined __GNUC__ || defined __clang__)
#   define arc_unlikely(p) (__builtin_expect(!!(p), 0))
#else
#   define arc_unlikely
#   warning arc_unlikely has no effect on non GCC-compatible compilers
#endif


/**
 * @example hint.h
 * This is an example showing how to code against the Argent Core Hint Module
 * interface.
 * @}
 */


typedef int arc_erno;


#endif /* !defined ARGENT_CORE */

