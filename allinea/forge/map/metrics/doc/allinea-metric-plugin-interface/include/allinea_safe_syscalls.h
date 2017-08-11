/*! \file
 *  \brief Async signal safe I/O functions for use in metric plugins
 *  */

#ifndef ALLINEA_SAFE_SYSCALLS_H
#define ALLINEA_SAFE_SYSCALLS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

/*! \name Standard Utility Functions
 *  \brief Replacements for common libc utility functions.
 *  Since metric library functions need to be async signal safe most
 *  standard libc functions cannot be used. Additionally even basic syscalls
 *  (such as \c read and \c write) cannot be used without risking corruption
 *  of some other metrics the enclosing profiler may be tracking (for examples,
 *  bytes read/written). The following functions can be safely called inside
 *  signal handlers and will accommodate I/O being done by the metric plugin
 *  without corrupting I/O metrics being tracked by the enclosing profiler.
 * @{ */

//! Gets the current time using the same clock as the enclosing profiler (async-signal-safe).
/*! A replacement for \c clock_gettime that uses the enclosing profiler's
 *  preferred system clock (i.e. \c CLOCK_MONOTONIC).
 *  \return The current time
 *  \ingroup api
 */
struct timespec allinea_get_current_time();


//! Closes the file descriptor @a fd previously opened by allinea_safe_open (async-signal-safe).
/*! A replacement for \c close.
 *  When used in conjunction with allinea_safe_read() and allinea_safe_write() the
 *  bytes read / written will not be included in the enclosing profiler's I/O accounting.
 *  \param fd The file descriptor to close.
 *  \return 0 on success; -1 on failure and errno set.
 *  \ingroup api
 */
extern int allinea_safe_close(int fd);


//! An async-signal-safe version of \c fprintf.
/*! \param fd The file descriptor to write to.
 *  \param format The format string.
 *  \param ... Zero or more values to be substituted into the \a format string
 *              in the same manner as printf.
 *  \ingroup api */
extern void allinea_safe_fprintf(int fd, const char *format, ...);


//! Opens the given @a file for reading or writing (async-signal-safe).
/*! A replacement for \c open.
 *  When used in conjunction with allinea_safe_read() and allinea_safe_write() the
 *  bytes read / written will not be included in the enclosing profiler's I/O accounting.
 *  \param file The name of the file to open (may be an absolute or relative path)
 *  \param oflags Flags specifying how the file should be opened. Accepts all the
 *              flags that may be given to the libc \c open function i.e.
 *              \c O_RDONLY, \c O_WRONLY, or \c O_RDWR.
 *  \return The file descriptor of the open file; -1 on failure and errno set.
 *  \ingroup api
 */
extern int allinea_safe_open (const char *file, int oflags, ...);


//! An async-signal-safe replacement for \c printf.
/*! \param format The format string.
 *  \param ... Zero or more values to be substituted into the \a format string
 *              in the same manner as printf.
 *  \ingroup api */
extern void allinea_safe_printf(const char *format, ...);


//! Reads up to @a count bytes from @a buf to @a fd (async-signal-safe)
/*! A replacement for \c read.
 *  When used in conjunction with allinea_safe_open() and allinea_safe_close()
 *  the read bytes will be excluded from the enclosing profiler's I/O accounting.
 *  \param fd The file descriptor to read from
 *  \param buf The buffer to read to.
 *  \param count The maximum number of bytes to read.
 *  \return The number of bytes actually read; -1 on failure and errno set.
 *  \ingroup api
 */
extern ssize_t allinea_safe_read(int fd, void *buf, size_t count);


//! Read the entire contents of @a fd into @a buf (async-signal-safe).
/*! When used in conjunction with allinea_safe_open() and allinea_safe_close()
 *  the read bytes will be excluded from the enclosing profiler's I/O accounting.
 *  \param fd The file descriptor to read from.
 *  \param buf Buffer in which to copy the contents
 *  \param count Size of the buffer. At most this many bytes will be written
 *              to @a buf.
 *  \return If successful the number of bytes read, else -1 and @a errno is set.
 *  \ingroup api
 */
extern ssize_t allinea_safe_read_all(int fd, void *buf, size_t count);


/*! Read a line from @a fd into @a buf (async-signal-safe). */
/*! The final newline '\\n' will be removed and a final '\0' added.
 *  When used in conjunction with allinea_safe_open() and allinea_safe_close()
 *  the written bytes will be excluded from the enclosing profiler's I/O accounting.
 *
 *  Lines longer than \a count will be truncated.
 *
 *  \param fd The file descriptor to read from.
 *  \param buf Buffer in which to copy the contents
 *  \param count Size of the buffer. At most this many bytes will be written
 *              to @a buf.
 *  \return If successful the number of bytes read, else -1 and @a errno is set.
 *  \ingroup api
 */
extern ssize_t allinea_safe_read_line(int fd, void *buf, size_t count);


//! An async-signal-safe version of \c vfprintf.
/*! \param fd The file descriptor to write to.
 *  \param format The format string.
 *  \param ap A list of arguments for \a format
 *  \ingroup api
 */
extern void allinea_safe_vfprintf(int fd, const char *format, va_list ap);


//! Writes up to @a count bytes from @a buf to @a fd (async-signal-safe).
/*! A replacement for \c write
 *  When used in conjunction with allinea_safe_open() and allinea_safe_close()
 *  the written bytes will be excluded from the enclosing profiler's I/O accounting.
 *  \param fd The file descriptor to write to.
 *  \param buf The buffer to write from.
 *  \param count The number of bytes to write.
 *  \return The number of bytes actually written; -1 on failure and errno set.
 *  \ingroup api
 */
extern ssize_t allinea_safe_write(int fd, const void *buf, size_t count);


//!@} // Doxygen grouping comment

#ifdef __cplusplus
}
#endif

#endif

