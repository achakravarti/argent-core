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


/**************************************************************************//**
 * @defgroup type Argent Core Type Module
 * Primitive data types.
 *
 * One of the objectives of the Argent Core Library is to be backward compatible
 * with the C89 standard, even if in practice standards such as C99 and C11 will
 * be used by client code. Related to this objective, another important one is
 * for the Library to be as portable as possible.
 *
 * In light of these objectives, the primitive data types are abstracted by the
 * types module of the Argent Core Library. For the time being, the abstractions
 * are around the C11 standard, but will soon be backward compatible with the
 * C89 standard.
 * @{
 */


#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>


/**
 * Boolean value.
 *
 * The @c arc_bool type represents a Boolean value that can hold only either @c
 * ARC_BOOL_FALSE or @c ARC_BOOL_TRUE for false and true values respectively.
 *
 * @see ARC_BOOL_FALSE
 * @see ARC_BOOL_TRUE
 */
typedef bool arc_bool;


/**
 * Boolean value False.
 *
 * The @c ARC_BOOL_FALSE symbolic constant represents the Boolean value False,
 * and is one of the values that can be held by the @c arc_bool type.
 *
 * @see arc_bool
 * @see ARC_BOOL_TRUE
 */
#define ARC_BOOL_FALSE (false)


/**
 * Boolean value True.
 *
 * The @c ARC_BOOL_TRUE symbolic constant represents the Boolean value True, and
 * is one of the values that can be held by the @c arc_bool type.
 */
#define ARC_BOOL_TRUE (true)


/**
 * Native word value.
 *
 * The @c arc_word type represents an unsigned integer word native to the host
 * processor.
 */
typedef uint_fast64_t arc_word;


/**
 * 8-bit word value.
 *
 * The @c arc_word_8 type represents an unsigned integer word that is guaranteed
 * to be at least 8 bits wide across all machine architectures supported by the
 * Argent Core Library.
 */
typedef uint8_t arc_word_8;


/**
 * 16-bit word value.
 *
 * The @c arc_word_16 type represents an unsigned integer word that is
 * guaranteed to be at least 16 bits wide across all machine architectures
 * supported by the Argent Core Library.
 */
typedef uint16_t arc_word_16;


/**
 * 32-bit word value.
 *
 * The @c arc_word_32 type represents an unsigned integer word that is
 * guaranteed to be at least 32 bits wide across all machine architectures
 * supported by the Argent Core Library.
 */
typedef uint32_t arc_word_32;


/**
 * 64-bit word value.
 *
 * The @c arc_word_64 type represents an unsigned integer word that is
 * guaranteed to be at least 64 bits wide across all machine architectures
 * supported by the Argent Core Library.
 */
typedef uint64_t arc_word_64;


/**
 * Size value.
 *
 * The @c arc_size type represents a native unsigned size value. This type
 * expands to either 32 or 64 bits depending on the machine architecture.
 */
typedef size_t arc_size;


/**
 * Index value.
 *
 * The @c arc_index type represents a native unsigned index value. This type
 * expands to either 32 or 64 bits depending on the machine architecture.
 */
typedef size_t arc_index;


/**
 * Native integer value.
 *
 * The @c arc_int type represents a signed integer native to the host processor.
 * This type expands to a width of either 32 or 64 bits depending on the machine
 * architecture.
 */
typedef int_fast64_t arc_int;


/**
 * 8-bit integer.
 *
 * The @c arc_int_8 type represents a signed integer that is guaranteed to be at
 * least 8 bits wide across all machine architectures supported by the Argent
 * Core Library.
 */
typedef int8_t arc_int_8;


/**
 * 16-bit integer.
 *
 * The @c arc_int_16 type represents a signed integer that is guaranteed to be
 * least 16 bits wide across all machine architectures supported by the Argent
 * Core Library.
 */
typedef int16_t arc_int_16;


/**
 * 32-bit integer.
 *
 * The @c arc_int_32 type represents a signed integer that is guaranteed to be
 * least 32 bits wide across all machine architectures supported by the Argent
 * Core Library.
 */
typedef int32_t arc_int_32;


/**
 * 64-bit integer.
 *
 * The @c arc_int_64 type represents a signed integer that is guaranteed to be
 * least 64 bits wide across all machine architectures supported by the Argent
 * Core Library.
 */
typedef int64_t arc_int_64;


/**
 * Native unsigned integer value.
 *
 * The @c arc_uint type represents an unsigned integer native to the host
 * processor. This type expands to a width of either 32 or 64 bits depending on
 * the machine architecture.
 */
typedef uint_fast64_t arc_uint;


/**
 * 8-bit unsigned integer.
 *
 * The @c arc_uint_8 type represents an unsigned integer that is guaranteed to
 * be at least 8 bits wide across all machine architectures supported by the
 * Argent Core Library.
 */
typedef uint8_t arc_uint_8;


/**
 * 16-bit unsigned integer.
 *
 * The @c arc_uint_16 type represents an unsigned integer that is guaranteed to
 * be at least 16 bits wide across all machine architectures supported by the
 * Argent Core Library.
 */
typedef uint16_t arc_uint_16;


/**
 * 32-bit unsigned integer.
 *
 * The @c arc_uint_32 type represents an unsigned integer that is guaranteed to
 * be at least 32 bits wide across all machine architectures supported by the
 * Argent Core Library.
 */
typedef uint32_t arc_uint_32;


/**
 * 64-bit unsigned integer.
 *
 * The @c arc_uint_64 type represents an unsigned integer that is guaranteed to
 * be at least 64 bits wide across all machine architectures supported by the
 * Argent Core Library.
 */
typedef uint64_t arc_uint_64;


/**
 * Native floating point value.
 *
 * The @c arc_float type represents a floating point value that is native to the
 * host processor. This type expands to either 32 or 64 bits depending on the
 * machine architecture.
 */
typedef double arc_float;


/**
 * 32-bit floating point value.
 *
 * The @c arc_float_32 type represents a floating point value that is guaranteed
 * to be at least 32 bits wide across all machine architectures supported by the
 * Argent Core Library.
 */
typedef float arc_float_32;


/**
 * 64-bit floating point value.
 *
 * The @c arc_float_32 type represents a floating point value that is guaranteed
 * to be at least 64 bits wide across all machine architectures supported by the
 * Argent Core Library.
 */
typedef double arc_float_64;


/**
 * @example type.h
 * This is an example showing how to code against the Argent Core Type Module
 * interface.
 * @}
 */


/**************************************************************************//**
 * @defgroup error Argent Core Error Handling Module
 * Simplified error handling mechanism.
 *
 * Error handling is an essential part of any reliable code. The traditional
 * approach to handling exceptions in C is either through the use of error codes
 * or through the @c setjmp()/longjmp() pair of functions. The former mechanism
 * is simpler to implement, and is the choice of the Argent Core Library.
 *
 * This module implements a very simple error handling mechansim in functions
 * through a combination of integer error codes and labels that mimic the
 * traditional try-catch-finally flow.
 * @{
 */


/**
 * Generic error code.
 *
 * The @c arc_erno type is used to hold error codes. Error codes may be defined
 * by client code as unsigned integers, with the exception of the error codes
 * defined below. This type aligns itself to the native word size of the host
 * environment. Any function returning this type can take advantage of the error
 * handling features provided by this module.
 */
typedef arc_word arc_erno;


/**
 * No error.
 *
 * The @c ARC_ERNO_NULL symbolic constant indicates that no error has occurred.
 * This error code is reserved by the Argent Core Library, and should @b not be
 * redefined by client code. Functions that take advantage of the error handling
 * mechanism implemented by this module return this symbolic constant (through
 * @c arc_erno_get()) by default if they don't encounter any errors during
 * execution.
 *
 * @see ARC_TRY
 * @see arc_assert()
 * @see arc_try()
 */
#define ARC_ERNO_NULL ((arc_erno) 0x0)


/**
 * Invalid pointer error.
 *
 * The @c ARC_ERNO_HANDLE symbolic constant indicates that an invalid pointer
 * has been passed to a function or macro. This error code is reserved by the
 * Argent Core Library, and should @b not be redefined by client code.
 *
 * @see ARC_TRY
 * @see arc_assert_handle()
 */
#define ARC_ERNO_HANDLE ((arc_erno) 0x1)


/**
 * Invalid state error.
 *
 * The @c ARC_ERNO_STATE symbolic constant indicates that an operation has taken
 * place that has resulted in an invalid state of an entity. This error code is
 * reserved by the Argent Core Library, and should @b not be redefined by client
 * code.
 *
 * @see ARC_TRY
 * @see arc_assert_state()
 */
#define ARC_ERNO_STATE ((arc_erno) 0x2)


/**
 * Out of bounds error.
 *
 * The @c ARC_ERNO_RANGE symbolic constant indicates that a value that is
 * outside its acceptable range has been passed to a function or macro. This
 * error code is reserved by the Argent Core Library, and should @b not be
 * redefined by client code.
 *
 * @see ARC_TRY
 * @see arc_assert_range()
 */
#define ARC_ERNO_RANGE ((arc_erno) 0x3)


/**
 * The @c ARC_ERNO_STRING symbolic constant indicates that an invalid string has
 * been passed to a function or macro. An invalid string is considered to be one
 * that is either a null pointer or an empty string. This error code is reserved
 * by the Argent Core Library, and should @b not be redefined by client code.
 *
 * @see ARC_TRY
 * @see arc_assert_string()
 */
#define ARC_ERNO_STRING ((arc_erno) 0x4)


/**
 * Get current error code.
 *
 * The @c arc_erno_get() macro returns the current error code within a function
 * that makes use of the error handling mechanism defined by this module. The
 * error code returned is an @c arc_erno value, either one of those defined by
 * this module, or one defined by client code.
 *
 * @return The current error code.
 *
 * @see arc_erno_set()
 * @see ARC_TRY
 */
#define arc_erno_get() \
    ((const arc_erno) arc__erno__)


/**
 * Set current error code.
 *
 * The @c arc_erno_set() macro sets the current error code within a function
 * that makes use of the error handling mechanism defined by this module. The
 * current error code can be set to an @c arc_erno value, either one of those
 * defined by this module, or one defined by client code.
 *
 * @param e The @c arc_erno error code to set.
 *
 * @see arc_erno_get()
 * @see ARC_TRY
 */
#define arc_erno_set(e) \
    (arc__erno__ = (e))


/**
 * Start try block.
 *
 * The @c ARC_TRY label identifies the starting point of the try block within a
 * function that returns an @c arc_erno value. The try block contains the normal
 * flow of code that may encounter errors. It must be placed at the beginning of
 * the function body and terminated by a @c ARC_TRY block.
 *
 * The code that may encounter errors within this block must be tested through
 * the @c arc_try() and @c arc_assert() family of macros defined below. In case
 * an error occurs, then control is passed to the adjancent @c ARC_CATCH block
 * without executing the reamining code in the try block.
 *
 * If no error occurs, then control automatically moves to the @c ARC_FINALLY
 * block placed after the @c ARC_CATCH block; this allows for the necessary
 * cleanup code to be performed.
 *
 * @warning Be sure to include the @c ARC_CATCH and @c ARC_FINALLY blocks if
 * using @c ARC_TRY.
 *
 * @see ARC_CATCH
 * @see ARC_FINALLY
 * @see arc_try()
 * @see arc_assert()
 */
#define ARC_TRY                                    \
    register arc_erno arc__erno__ = ARC_ERNO_NULL; \
    goto ARC__TRY__;                               \
    ARC__TRY__


/**
 * Start catch block.
 *
 * The @c ARC_CATCH label identifies the starting point of a catch block within
 * a function that returns an @c arc_erno value. The catch block contains the
 * error handling code, and must be placed immediately at the end of an @c
 * ARC_TRY block.
 *
 * The @c ARC_CATCH block must be terminated by an adjacent ARC_FINALLY block.
 * This allows all necessary cleanup code to be performed after the error
 * handling code has been executed.
 *
 * @warning At no point should the @c arc_try() and @c arc_assert() family of
 * macros be used in the @c ARC_CATCH block, as this would potentially lead to
 * an infinite loop.
 *
 * @see ARC_TRY
 * @see ARC_FINALLY
 * @see arc_try()
 * @see arc_assert()
 */
#define ARC_CATCH        \
    goto ARC__FINALLY__; \
    ARC__CATCH__


/**
 * Start finally block.
 *
 * The @c ARC_FINALLY label identifies the starting point of a finally block
 * within a function that returns an @c arc_erno value. The finally block
 * contains the cleanup code that is common to both the @c ARC_TRY and @c
 * ARC_CATCH blocks, and must be placed immediately at the end of an @c ARC_TRY
 * block.
 *
 * The @c ARC_FINALLY block must be terminated by returning the current error
 * code provided by the @c arc_erno_get() macro defined above.
 *
 * @warning At no point should the @c arc_try() and @c arc_assert() family of
 * macros be used in the @c ARC_FINALLY block as this could potentially lead to
 * an infinite loop.
 *
 * @see ARC_TRY
 * @see ARC_CATCH
 * @see arc_try()
 * @see arc_assert()
 */
#define ARC_FINALLY ARC__FINALLY__


/**
 * Verify generic precondition.
 *
 * The @c arc_assert() macro verifies whether a generic precondition, expressed
 * as a predicate @p p, is true before any further processing takes place. If
 * the assertion fails, then an @c arc_erno error code @p e is raised in the
 * current context and control jumps to the adjacent @c ARC_CATCH block.
 *
 * @param p Precondition predicate being asserted.
 * @param e Error code to be raised if assertion fails.
 *
 * @warning This macro can only be called within an @c ARC_TRY block; it should
 * @b never be called within an @c ARC_CATCH or @c ARC_FINALLY block as it may
 * lead to an infinite loop.
 *
 * @see ARC_TRY
 * @see arc_try()
 * @see arc_assert_handle()
 * @see arc_assert_state()
 * @see arc_assert_range()
 * @see arc_assert_string()
 */
#define arc_assert(p, e)       \
do {                           \
    if (arc_unlikely (!(p))) { \
        arc__erno__ = (e);     \
        goto ARC__CATCH__;     \
    }                          \
} while (0)


/**
 * Verify handle precondition.
 *
 * The @c arc_assert_handle() macro verifies whether a handle to an entity meets
 * a specific precondition, expressed as a predicate @p p. If the assertion
 * fails, then @c ARC_ERNO_HANDLE is raised in the current context and control
 * jumps to the adjacent @c ARC_CATCH block.
 *
 * @param p Precondition predicate being asserted.
 *
 * @note This macro is a convenience wrapper around @c arc_assert().
 *
 * @warning This macro can only be called within an @c ARC_TRY block; it should
 * @b never be called within an @c ARC_CATCH or @c ARC_FINALLY block as it may
 * lead to an infinite loop.
 *
 * @see ARC_TRY
 * @see ARC_ERNO_HANDLE
 * @see arc_try()
 * @see arc_assert()
 */
#define arc_assert_handle(p) \
    arc_assert((p), ARC_ERNO_HANDLE)


/**
 * Verify state precondition.
 *
 * The @c arc_assert_state() macro verifies whether the state of an entity meets
 * a specific precondition, expressed as a predicate @p p. If the assertion
 * fails, then @c ARC_ERNO_STATE is raised in the current context and control
 * jumps to the adjacent @c ARC_CATCH block.
 *
 * @param p Precondition predicate being asserted.
 *
 * @note This macro is a convenience wrapper around @c arc_assert().
 *
 * @warning This macro can only be called within an @c ARC_TRY block; it should
 * @b never be called within an @c ARC_CATCH or @c ARC_FINALLY block as it may
 * lead to an infinite loop.
 *
 * @see ARC_TRY
 * @see ARC_ERNO_STATE
 * @see arc_try()
 * @see arc_assert()
 */
#define arc_assert_state(p) \
    arc_assert((p), ARC_ERNO_STATE)


/**
 * Verify range precondition.
 *
 * The @c arc_assert_range() macro verifies whether an entity lies within a
 * specific range, expressed as a predicate @p p. If the assertion fails, then
 * @c ARC_ERNO_RANGE is raised in the current context and control jumps to the
 * adjacent @c ARC_CATCH block.
 *
 * @param p Precondition predicate being asserted.
 *
 * @note This macro is a convenience wrapper around @c arc_assert().
 *
 * @warning This macro can only be called within an @c ARC_TRY block; it should
 * @b never be called within an @c ARC_CATCH or @c ARC_FINALLY block as it may
 * lead to an infinite loop.
 *
 * @see ARC_TRY
 * @see ARC_ERNO_RANGE
 * @see arc_try()
 * @see arc_assert()
 */
#define arc_assert_range(p) \
    arc_assert((p), ARC_ERNO_RANGE)


/**
 * Verify string precondition.
 *
 * The @c arc_assert_string() macro verifies whether a string @p s is valid. A
 * string is considered to be valid if it is not a null pointer and it is not
 * empty. If the assertion fails, then @c ARC_ERNO_STRING is raised in the
 * current context and control jumps to the adjacent @c ARC_CATCH block.
 *
 * @param p Precondition predicate being asserted.
 *
 * @note This macro is a convenience wrapper around @c arc_assert().
 *
 * @warning This macro can only be called within an @c ARC_TRY block; it should
 * @b never be called within an @c ARC_CATCH or @c ARC_FINALLY block as it may
 * lead to an infinite loop.
 *
 * @see ARC_TRY
 * @see ARC_ERNO_STRING
 * @see arc_try()
 * @see arc_assert()
 */
#define arc_assert_string(s) \
    arc_assert((s) && *(s), ARC_ERNO_STRING)


/**
 * Validate postcondition.
 *
 * The @c arc_try() macro validates whether a postcondition @p, expressed as a
 * function returning an @c arc_erno value, has not failed. The function is
 * deemed to have run successfully if it has not raised any error as flagged by
 * the returned error code. If the validation fails, then control will jump to
 * the adjacent @c ARC_CATCH block.
 *
 * @param p Postcondition being evaluated.
 *
 * @warning This macro can only be called within an @c ARC_TRY block; it should
 * @b never be called within an @c ARC_CATCH or @c ARC_FINALLY block as it may
 * lead to an infinite loop.
 *
 * @see ARC_TRY
 * @see arc_assert()
 */
#define arc_try(p)                         \
do {                                       \
    if (arc_unlikely (rush__erno__ = (p))) \
        goto ARC__CATCH__;                 \
} while (0)


#endif /* !defined ARGENT_CORE */

