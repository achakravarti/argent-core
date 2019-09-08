#if !defined ARGENT_CORE
#define ARGENT_CORE

#if (defined __GNUC__ || defined __clang__)
#   define arc_pure __attribute__((pure))
#else
#   define arc_pure
#   warning arc_pure has no effect on non GCC-compatible compilers
#endif

#if (defined __GNUC__ || defined __clang__)
#   define arc_hot __attribute__((hot))
#else
#   define arc_hot
#   warning arc_hot has no effect on non GCC-compatible compilers
#endif


#if (defined __GNUC__ || defined __clang__)
#   define arc_cold __attribute__((cold))
#else
#   define arc_cold
#   warning arc_cold has no effect on non GCC-compatible compilers
#endif


#if (defined __GNUC__ || defined __clang__)
#   define arc_likely(p) (__builtin_expect(!!(p), 1))
#else
#   define arc_likely
#   warning arc_likely has no effect on non GCC-compatible compilers
#endif


#if (defined __GNUC__ || defined __clang__)
#   define arc_unlikely(p) (__builtin_expect(!!(p), 0))
#else
#   define arc_unlikely
#   warning arc_unlikely has no effect on non GCC-compatible compilers
#endif


#endif /* !defined ARGENT_CORE */

