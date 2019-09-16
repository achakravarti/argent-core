#if !defined ARGENT_CORE
#define ARGENT_CORE


/**************************************************************************//**
 * @defgroup compiler Argent Core Compiler Module
 * Compiler identification.
 *
 * The Compiler Module provides an interface to reliably determine the compiler
 * being used at compilation time. This is useful when conditionally compiling
 * code that depends on specific features provided by a compiler.
 *
 * Currently, only the GNU C and Clang compilers are supported directly, and GNU
 * C compatible compilers indirectly. This is expected to be adequate as far as
 * portability is concerned, as GNU C is the most widely ported compiler.
 *
 * However, in future, support for other compilers, including MSVC, @b may be
 * introduced if there is adequate reason to do so.
 * @{
 */


/**
 * GNU C compiler.
 *
 * The @c AG_COMPILER_GNUC symbolic constant represents the GNU C compiler. This
 * constant is returned by the @c ag_compiler() macro (defined below) if it
 * detects that the GNU C compiler is being used.
 *
 * @note This constant has been defined as a symbolic constant instead of an
 * enumeration so that it may be used at file scope outside any function body.
 *
 * @see ag_compiler()
 */
#define AG_COMPILER_GNUC (0)


/**
 * LLVM Clang front-end.
 *
 * The @c AG_COMPILER_CLANG symbolic constant represents the Clang front-end of
 * the LLVM compiler. This constant is returned by the @c ag_compiler() macro
 * (defined below) if it detects that the Clang compiler is being used.
 *
 * @note This constant has been defined as a symbolic constant instead of an
 * enumeration so that it may be used at file scope outside any function body.
 *
 * @see ag_compiler()
 */
#define AG_COMPILER_CLANG (1)


/**
 * Determine compiler used.
 *
 * The @c ag_compiler() macro determines at compile-time the C compiler that is
 * being used. This macro returns one of the @c AG_COMPILER_* family of symbolic
 * constants as appropriate.
 *
 * @return AG_COMPILER_GNUC if GNU C (or compatible) compiler is being used.
 * @return AG_COMPILER_CLANG if Clang compiler is being used.
 *
 * @note In case a compiler other than those supported by the Argent Core
 * Library is used, then the @c ag_compiler() macro raises a compilation error.
 */
#if (defined __GNUC__)
#       define ag_compiler() AG_COMPILER_GNUC
#elif (defined __clang__)
#       define ag_compiler() AG_COMPILER_CLANG
#else
#       error ag_compiler(): unsupported C compiler
#endif


/**
 * @example compiler.h
 * This is an example showing how to code against the Argent Core Compiler
 * Module interface.
 * @}
 */


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
 * The @c ag_pure macro is used to decorate the declaration of a pure function.
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
#   define ag_pure __attribute__((pure))
#else
#   define ag_pure
#   warning ag_pure has no effect on non GCC-compatible compilers
#endif


/**
 * Hints that a function is called frequently.
 *
 * The @c ag_hot macro is used to decorate a function declaration in order to
 * indicate that it is called frequently. This hint follows the GCC attribute
 * syntax, and is recommended to be placed in the function declaration just
 * before the function return type.
 *
 * @warning This hint is available only on GCC and GCC-compatible compilers such
 * as Clang; on other compilers, this macro degrades with a warning that it has
 * no effect.
 *
 * @see ag_cold
 */
#if (defined __GNUC__ || defined __clang__)
#   define ag_hot __attribute__((hot))
#else
#   define ag_hot
#   warning ag_hot has no effect on non GCC-compatible compilers
#endif


/**
 * Hints that a function is called infrequently.
 *
 * The @c ag_cold macro is used to decorate a function declaration in order to
 * indicate that is called infrequently. This hint follows the GCC attribute
 * syntax, and is recommended to be placed in the function declaration just
 * before the function return type.
 *
 * @warning This hint is available only on GCC and GCC-compatible compilers such
 * as Clang; on other compilers, this macro degrades with a warning that it has
 * no effect.
 *
 * @see ag_hot
 */
#if (defined __GNUC__ || defined __clang__)
#   define ag_cold __attribute__((cold))
#else
#   define ag_cold
#   warning ag_cold has no effect on non GCC-compatible compilers
#endif


/**
 * Hints that a predicate is likely to be true.
 *
 * The @c ag_likely() macro indicates that a predicate expression @p p is @b
 * likely to evaluate to @c true. This hint has been modelled after the @c
 * likely() macro used in the Linux kernel source.
 *
 * @param p predicate expected to be true.
 *
 * @warning This hint is available only on GCC and GCC-compatible compilers such
 * as Clang; on other compilers, this macro degrades with a warning that it has
 * no effect.
 *
 * @see ag_unlikely()
 */
#if (defined __GNUC__ || defined __clang__)
#   define ag_likely(p) (__builtin_expect(!!(p), 1))
#else
#   define ag_likely
#   warning ag_likely has no effect on non GCC-compatible compilers
#endif


/**
 * Hints that a predicate is likely to be false.
 *
 * The @c ag_unlikely() macro indicates that a predicate expression @p p is @b
 * unlikely to evaluate to @c false. This hint has been modelled after the @c
 * unlikely() macro used in the Linux kernel source.
 *
 * @param p predicate expected to be false.
 *
 * @warning This hint is available only on GCC and GCC-compatible compilers such
 * as Clang; on other compilers, this macro degrades with a warning that it has
 * no effect.
 *
 * @see ag_likely()
 */
#if (defined __GNUC__ || defined __clang__)
#   define ag_unlikely(p) (__builtin_expect(!!(p), 0))
#else
#   define ag_unlikely
#   warning ag_unlikely has no effect on non GCC-compatible compilers
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
 * The @c ag_bool type represents a Boolean value that can hold only either @c
 * AG_BOOL_FALSE or @c AG_BOOL_TRUE for false and true values respectively.
 *
 * @see AG_BOOL_FALSE
 * @see AG_BOOL_TRUE
 */
typedef bool ag_bool;


/**
 * Boolean value False.
 *
 * The @c AG_BOOL_FALSE symbolic constant represents the Boolean value False,
 * and is one of the values that can be held by the @c ag_bool type.
 *
 * @see ag_bool
 * @see AG_BOOL_TRUE
 */
#define AG_BOOL_FALSE (false)


/**
 * Boolean value True.
 *
 * The @c AG_BOOL_TRUE symbolic constant represents the Boolean value True, and
 * is one of the values that can be held by the @c ag_bool type.
 *
 * @see ag_bool
 * @see AG_BOOL_FALSE
 */
#define AG_BOOL_TRUE (true)


/**
 * Native word value.
 *
 * The @c ag_word type represents an unsigned integer word native to the host
 * processor.
 *
 * @see ag_word_8
 * @see ag_word_16
 * @see ag_word_32
 * @see ag_word_64
 */
typedef uint_fast64_t ag_word;


/**
 * 8-bit word value.
 *
 * The @c ag_word_8 type represents an unsigned integer word that is guaranteed
 * to be at least 8 bits wide across all machine architectures supported by the
 * Argent Core Library.
 *
 * @see ag_word
 * @see ag_word_16
 * @see ag_word_32
 * @see ag_word_64
 */
typedef uint8_t ag_word_8;


/**
 * 16-bit word value.
 *
 * The @c ag_word_16 type represents an unsigned integer word that is
 * guaranteed to be at least 16 bits wide across all machine architectures
 * supported by the Argent Core Library.
 *
 * @see ag_word
 * @see ag_word_8
 * @see ag_word_32
 * @see ag_word_64
 */
typedef uint16_t ag_word_16;


/**
 * 32-bit word value.
 *
 * The @c ag_word_32 type represents an unsigned integer word that is
 * guaranteed to be at least 32 bits wide across all machine architectures
 * supported by the Argent Core Library.
 *
 * @see ag_word
 * @see ag_word_8
 * @see ag_word_16
 * @see ag_word_64
 */
typedef uint32_t ag_word_32;


/**
 * 64-bit word value.
 *
 * The @c ag_word_64 type represents an unsigned integer word that is
 * guaranteed to be at least 64 bits wide across all machine architectures
 * supported by the Argent Core Library.
 *
 * @see ag_word
 * @see ag_word_8
 * @see ag_word_16
 * @see ag_word_32
 */
typedef uint64_t ag_word_64;


/**
 * Size value.
 *
 * The @c ag_size type represents a native unsigned size value. This type
 * expands to either 32 or 64 bits depending on the machine architecture.
 *
 * @see ag_index
 */
typedef size_t ag_size;


/**
 * Index value.
 *
 * The @c ag_index type represents a native unsigned index value. This type
 * expands to either 32 or 64 bits depending on the machine architecture.
 *
 * @see ag_size
 */
typedef size_t ag_index;


/**
 * Native integer value.
 *
 * The @c ag_int type represents a signed integer native to the host processor.
 * This type expands to a width of either 32 or 64 bits depending on the machine
 * architecture.
 *
 * @see ag_int_8
 * @see ag_int_16
 * @see ag_int_32
 * @see ag_int_64
 */
typedef int_fast64_t ag_int;


/**
 * 8-bit integer.
 *
 * The @c ag_int_8 type represents a signed integer that is guaranteed to be at
 * least 8 bits wide across all machine architectures supported by the Argent
 * Core Library.
 *
 * @see ag_int
 * @see ag_int_16
 * @see ag_int_32
 * @see ag_int_64
 */
typedef int8_t ag_int_8;


/**
 * 16-bit integer.
 *
 * The @c ag_int_16 type represents a signed integer that is guaranteed to be
 * least 16 bits wide across all machine architectures supported by the Argent
 * Core Library.
 *
 * @see ag_int
 * @see ag_int_8
 * @see ag_int_32
 * @see ag_int_64
 */
typedef int16_t ag_int_16;


/**
 * 32-bit integer.
 *
 * The @c ag_int_32 type represents a signed integer that is guaranteed to be
 * least 32 bits wide across all machine architectures supported by the Argent
 * Core Library.
 *
 * @see ag_int
 * @see ag_int_8
 * @see ag_int_16
 * @see ag_int_64
 */
typedef int32_t ag_int_32;


/**
 * 64-bit integer.
 *
 * The @c ag_int_64 type represents a signed integer that is guaranteed to be
 * least 64 bits wide across all machine architectures supported by the Argent
 * Core Library.
 *
 * @see ag_int
 * @see ag_int_8
 * @see ag_int_16
 * @see ag_int_32
 */
typedef int64_t ag_int_64;


/**
 * Native unsigned integer value.
 *
 * The @c ag_uint type represents an unsigned integer native to the host
 * processor. This type expands to a width of either 32 or 64 bits depending on
 * the machine architecture.
 *
 * @see ag_uint_8
 * @see ag_uint_16
 * @see ag_uint_32
 * @see ag_uint_64
 */
typedef uint_fast64_t ag_uint;


/**
 * 8-bit unsigned integer.
 *
 * The @c ag_uint_8 type represents an unsigned integer that is guaranteed to
 * be at least 8 bits wide across all machine architectures supported by the
 * Argent Core Library.
 *
 * @see ag_uint
 * @see ag_uint_16
 * @see ag_uint_32
 * @see ag_uint_64
 */
typedef uint8_t ag_uint_8;


/**
 * 16-bit unsigned integer.
 *
 * The @c ag_uint_16 type represents an unsigned integer that is guaranteed to
 * be at least 16 bits wide across all machine architectures supported by the
 * Argent Core Library.
 *
 * @see ag_uint
 * @see ag_uint_8
 * @see ag_uint_32
 * @see ag_uint_64
 */
typedef uint16_t ag_uint_16;


/**
 * 32-bit unsigned integer.
 *
 * The @c ag_uint_32 type represents an unsigned integer that is guaranteed to
 * be at least 32 bits wide across all machine architectures supported by the
 * Argent Core Library.
 *
 * @see ag_uint
 * @see ag_uint_8
 * @see ag_uint_16
 * @see ag_uint_64
 */
typedef uint32_t ag_uint_32;


/**
 * 64-bit unsigned integer.
 *
 * The @c ag_uint_64 type represents an unsigned integer that is guaranteed to
 * be at least 64 bits wide across all machine architectures supported by the
 * Argent Core Library.
 *
 * @see ag_uint
 * @see ag_uint_8
 * @see ag_uint_16
 * @see ag_uint_32
 */
typedef uint64_t ag_uint_64;


/**
 * Native floating point value.
 *
 * The @c ag_float type represents a floating point value that is native to the
 * host processor. This type expands to either 32 or 64 bits depending on the
 * machine architecture.
 *
 * @see ag_float_32
 * @see ag_float_64
 */
typedef double ag_float;


/**
 * 32-bit floating point value.
 *
 * The @c ag_float_32 type represents a floating point value that is guaranteed
 * to be at least 32 bits wide across all machine architectures supported by the
 * Argent Core Library.
 *
 * @see ag_float
 * @see ag_float_64
 */
typedef float ag_float_32;


/**
 * 64-bit floating point value.
 *
 * The @c ag_float_32 type represents a floating point value that is guaranteed
 * to be at least 64 bits wide across all machine architectures supported by the
 * Argent Core Library.
 *
 * @see ag_float
 * @see ag_float_32
 */
typedef double ag_float_64;


/**
 * UTF-8 string.
 *
 * The ag_string type represents a UTF-8 string. An ag_string may be used
 * interchangably with a raw @c char string in most (but not all) cases. Argent
 * string instances may be allocated either on the stack or on the heap. The
 * Argent Abstractions Library provides an interface for working with Argent
 * strings.
 */
typedef char ag_string;


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
 * The @c ag_erno type is used to hold error codes. Error codes may be defined
 * by client code as unsigned integers, with the exception of the error codes
 * defined below. This type aligns itself to the native word size of the host
 * environment. Any function returning this type can take advantage of the error
 * handling features provided by this module.
 */
typedef ag_word ag_erno;


/**
 * No error.
 *
 * The @c AG_ERNO_NULL symbolic constant indicates that no error has occurred.
 * This error code is reserved by the Argent Core Library, and should @b not be
 * redefined by client code. Functions that take advantage of the error handling
 * mechanism implemented by this module return this symbolic constant (through
 * @c ag_erno_get()) by default if they don't encounter any errors during
 * execution.
 *
 * @see AG_TRY
 * @see ag_assert()
 * @see ag_try()
 */
#define AG_ERNO_NULL ((ag_erno) 0x0)


/**
 * Invalid pointer error.
 *
 * The @c AG_ERNO_HANDLE symbolic constant indicates that an invalid pointer
 * has been passed to a function or macro. This error code is reserved by the
 * Argent Core Library, and should @b not be redefined by client code.
 *
 * @see AG_TRY
 * @see ag_assert_handle()
 */
#define AG_ERNO_HANDLE ((ag_erno) 0x1)


/**
 * Invalid state error.
 *
 * The @c AG_ERNO_STATE symbolic constant indicates that an operation has taken
 * place that has resulted in an invalid state of an entity. This error code is
 * reserved by the Argent Core Library, and should @b not be redefined by client
 * code.
 *
 * @see AG_TRY
 * @see ag_assert_state()
 */
#define AG_ERNO_STATE ((ag_erno) 0x2)


/**
 * Out of bounds error.
 *
 * The @c AG_ERNO_RANGE symbolic constant indicates that a value that is
 * outside its acceptable range has been passed to a function or macro. This
 * error code is reserved by the Argent Core Library, and should @b not be
 * redefined by client code.
 *
 * @see AG_TRY
 * @see ag_assert_range()
 */
#define AG_ERNO_RANGE ((ag_erno) 0x3)


/**
 * The @c AG_ERNO_STRING symbolic constant indicates that an invalid string has
 * been passed to a function or macro. An invalid string is considered to be one
 * that is either a null pointer or an empty string. This error code is reserved
 * by the Argent Core Library, and should @b not be redefined by client code.
 *
 * @see AG_TRY
 * @see ag_assert_string()
 */
#define AG_ERNO_STRING ((ag_erno) 0x4)


/**
 * Get current error code.
 *
 * The @c ag_erno_get() macro returns the current error code within a function
 * that makes use of the error handling mechanism defined by this module. The
 * error code returned is an @c ag_erno value, either one of those defined by
 * this module, or one defined by client code.
 *
 * @return The current error code.
 *
 * @see ag_erno_set()
 * @see AG_TRY
 */
#define ag_erno_get() \
    ((const ag_erno) ag__erno__)


/**
 * Set current error code.
 *
 * The @c ag_erno_set() macro sets the current error code within a function
 * that makes use of the error handling mechanism defined by this module. The
 * current error code can be set to an @c ag_erno value, either one of those
 * defined by this module, or one defined by client code.
 *
 * @param e The @c ag_erno error code to set.
 *
 * @see ag_erno_get()
 * @see AG_TRY
 */
#define ag_erno_set(e) \
    (ag__erno__ = (e))


/**
 * Start try block.
 *
 * The @c AG_TRY label identifies the starting point of the try block within a
 * function that returns an @c ag_erno value. The try block contains the normal
 * flow of code that may encounter errors. It must be placed at the beginning of
 * the function body and terminated by a @c AG_TRY block.
 *
 * The code that may encounter errors within this block must be tested through
 * the @c ag_try() and @c ag_assert() family of macros defined below. In case
 * an error occurs, then control is passed to the adjancent @c AG_CATCH block
 * without executing the reamining code in the try block.
 *
 * If no error occurs, then control automatically moves to the @c AG_FINALLY
 * block placed after the @c AG_CATCH block; this allows for the necessary
 * cleanup code to be performed.
 *
 * @warning Be sure to include the @c AG_CATCH and @c AG_FINALLY blocks if
 * using @c AG_TRY.
 *
 * @see AG_CATCH
 * @see AG_FINALLY
 * @see ag_try()
 * @see ag_assert()
 */
#define AG_TRY                                  \
    register ag_erno ag__erno__ = AG_ERNO_NULL; \
    goto AG__TRY__;                             \
    AG__TRY__


/**
 * Start catch block.
 *
 * The @c AG_CATCH label identifies the starting point of a catch block within
 * a function that returns an @c ag_erno value. The catch block contains the
 * error handling code, and must be placed immediately at the end of an @c
 * AG_TRY block.
 *
 * The @c AG_CATCH block must be terminated by an adjacent AG_FINALLY block.
 * This allows all necessary cleanup code to be performed after the error
 * handling code has been executed.
 *
 * @warning At no point should the @c ag_try() and @c ag_assert() family of
 * macros be used in the @c AG_CATCH block, as this would potentially lead to
 * an infinite loop.
 *
 * @see AG_TRY
 * @see AG_FINALLY
 * @see ag_try()
 * @see ag_assert()
 */
#define AG_CATCH        \
    goto AG__FINALLY__; \
    AG__CATCH__


/**
 * Start finally block.
 *
 * The @c AG_FINALLY label identifies the starting point of a finally block
 * within a function that returns an @c ag_erno value. The finally block
 * contains the cleanup code that is common to both the @c AG_TRY and @c
 * AG_CATCH blocks, and must be placed immediately at the end of an @c AG_TRY
 * block.
 *
 * The @c AG_FINALLY block must be terminated by returning the current error
 * code provided by the @c ag_erno_get() macro defined above.
 *
 * @warning At no point should the @c ag_try() and @c ag_assert() family of
 * macros be used in the @c AG_FINALLY block as this could potentially lead to
 * an infinite loop.
 *
 * @see AG_TRY
 * @see AG_CATCH
 * @see ag_try()
 * @see ag_assert()
 */
#define AG_FINALLY AG__FINALLY__


/**
 * Verify generic precondition.
 *
 * The @c ag_assert() macro verifies whether a generic precondition, expressed
 * as a predicate @p p, is true before any further processing takes place. If
 * the assertion fails, then an @c ag_erno error code @p e is raised in the
 * current context and control jumps to the adjacent @c AG_CATCH block.
 *
 * @param p Precondition predicate being asserted.
 * @param e Error code to be raised if assertion fails.
 *
 * @warning This macro can only be called within an @c AG_TRY block; it should
 * @b never be called within an @c AG_CATCH or @c AG_FINALLY block as it may
 * lead to an infinite loop.
 *
 * @see AG_TRY
 * @see ag_try()
 * @see ag_assert_handle()
 * @see ag_assert_state()
 * @see ag_assert_range()
 * @see ag_assert_string()
 */
#define ag_assert(p, e)       \
do {                          \
    if (ag_unlikely (!(p))) { \
        ag__erno__ = (e);     \
        goto AG__CATCH__;     \
    }                         \
} while (0)


/**
 * Verify handle precondition.
 *
 * The @c ag_assert_handle() macro verifies whether a handle to an entity meets
 * a specific precondition, expressed as a predicate @p p. If the assertion
 * fails, then @c AG_ERNO_HANDLE is raised in the current context and control
 * jumps to the adjacent @c AG_CATCH block.
 *
 * @param p Precondition predicate being asserted.
 *
 * @note This macro is a convenience wrapper around @c ag_assert().
 *
 * @warning This macro can only be called within an @c AG_TRY block; it should
 * @b never be called within an @c AG_CATCH or @c AG_FINALLY block as it may
 * lead to an infinite loop.
 *
 * @see AG_TRY
 * @see AG_ERNO_HANDLE
 * @see ag_try()
 * @see ag_assert()
 */
#define ag_assert_handle(p) \
    ag_assert((p), AG_ERNO_HANDLE)


/**
 * Verify state precondition.
 *
 * The @c ag_assert_state() macro verifies whether the state of an entity meets
 * a specific precondition, expressed as a predicate @p p. If the assertion
 * fails, then @c AG_ERNO_STATE is raised in the current context and control
 * jumps to the adjacent @c AG_CATCH block.
 *
 * @param p Precondition predicate being asserted.
 *
 * @note This macro is a convenience wrapper around @c ag_assert().
 *
 * @warning This macro can only be called within an @c AG_TRY block; it should
 * @b never be called within an @c AG_CATCH or @c AG_FINALLY block as it may
 * lead to an infinite loop.
 *
 * @see AG_TRY
 * @see AG_ERNO_STATE
 * @see ag_try()
 * @see ag_assert()
 */
#define ag_assert_state(p) \
    ag_assert((p), AG_ERNO_STATE)


/**
 * Verify range precondition.
 *
 * The @c ag_assert_range() macro verifies whether an entity lies within a
 * specific range, expressed as a predicate @p p. If the assertion fails, then
 * @c AG_ERNO_RANGE is raised in the current context and control jumps to the
 * adjacent @c AG_CATCH block.
 *
 * @param p Precondition predicate being asserted.
 *
 * @note This macro is a convenience wrapper around @c ag_assert().
 *
 * @warning This macro can only be called within an @c AG_TRY block; it should
 * @b never be called within an @c AG_CATCH or @c AG_FINALLY block as it may
 * lead to an infinite loop.
 *
 * @see AG_TRY
 * @see AG_ERNO_RANGE
 * @see ag_try()
 * @see ag_assert()
 */
#define ag_assert_range(p) \
    ag_assert((p), AG_ERNO_RANGE)


/**
 * Verify string precondition.
 *
 * The @c ag_assert_string() macro verifies whether a string @p s is valid. A
 * string is considered to be valid if it is not a null pointer and it is not
 * empty. If the assertion fails, then @c AG_ERNO_STRING is raised in the
 * current context and control jumps to the adjacent @c AG_CATCH block.
 *
 * @param p Precondition predicate being asserted.
 *
 * @note This macro is a convenience wrapper around @c ag_assert().
 *
 * @warning This macro can only be called within an @c AG_TRY block; it should
 * @b never be called within an @c AG_CATCH or @c AG_FINALLY block as it may
 * lead to an infinite loop.
 *
 * @see AG_TRY
 * @see AG_ERNO_STRING
 * @see ag_try()
 * @see ag_assert()
 */
#define ag_assert_string(s) \
    ag_assert((s) && *(s), AG_ERNO_STRING)


/**
 * Validate postcondition.
 *
 * The @c ag_try() macro validates whether a postcondition @p, expressed as a
 * function returning an @c ag_erno value, has not failed. The function is
 * deemed to have run successfully if it has not raised any error as flagged by
 * the returned error code. If the validation fails, then control will jump to
 * the adjacent @c AG_CATCH block.
 *
 * @param p Postcondition being evaluated.
 *
 * @warning This macro can only be called within an @c AG_TRY block; it should
 * @b never be called within an @c AG_CATCH or @c AG_FINALLY block as it may
 * lead to an infinite loop.
 *
 * @see AG_TRY
 * @see ag_assert()
 */
#define ag_try(p)                       \
do {                                    \
    if (ag_unlikely (ag__erno__ = (p))) \
        goto AG__CATCH__ ;              \
} while (0)


#endif /* !defined ARGENT_CORE */

