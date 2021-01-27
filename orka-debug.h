#ifndef ORKA_DEBUG_H
#define ORKA_DEBUG_H


#define D_OUT stderr
#define D_FMT_PREFIX "[%s:%d] %s()\n\t"
#define D_FMT_ARGS __FILE__, __LINE__, __func__


#define __PRINT_ERR(fmt, ...) fprintf(D_OUT, D_FMT_PREFIX "ERROR:\t" \
                           /* force spaces */ fmt /* force spaces */ \
                          "\n%s", D_FMT_ARGS, __VA_ARGS__)
#define PRINT_ERR(...) \
        do { \
            __PRINT_ERR(__VA_ARGS__, ""); \
            abort(); \
        } while (0)

#define ASSERT_S(expr, msg) \
        do { \
            if (!(expr)){ \
                PRINT_ERR("Assert Failed:\t%s\n\tExpected:\t%s", msg, #expr); \
            } \
        } while(0)


#if _ORCA_DEBUG /* DEBUG MODE ACTIVE */

/* @param msg string to be printed in debug mode */
#       define D_PUTS(msg) fprintf(D_OUT, D_FMT_PREFIX "%s\n", D_FMT_ARGS, msg)
#       define D_NOTOP_PUTS(msg) fprintf(D_OUT, "\t%s\n", msg)
/* @param fmt like printf
   @param ... arguments to be parsed into fmt */
#       define __D_PRINT(fmt, ...) fprintf(D_OUT, D_FMT_PREFIX /* force spaces */ fmt /* force spaces */"\n%s", D_FMT_ARGS, __VA_ARGS__)
#       define D_PRINT(...) __D_PRINT(__VA_ARGS__, "")
#       define __D_NOTOP_PRINT(fmt, ...) fprintf(D_OUT, "\t" /* force spaces */ fmt /* force spaces */"\n%s", __VA_ARGS__)
#       define D_NOTOP_PRINT(...) __D_NOTOP_PRINT(__VA_ARGS__, "")
#       define D_PRINT_ERR(...) PRINT_ERR(__VA_ARGS__)
#       define D_ASSERT_S(expr, msg) ASSERT_S(expr, msg)
#       define D_ONLY(arg) (arg)

#else /* DEBUG MODE INNACTIVE */

#       define D_PUTS(msg) 
#       define D_NOTOP_PUTS(msg) 
#       define D_PRINT(...)
#       define D_NOTOP_PRINT(...)
#       define D_PRINT_ERR(...)
#       define D_ASSERT_S(expr, msg)
#       define D_ONLY(arg)
#endif

#endif // ORKA_DEBUG_H
