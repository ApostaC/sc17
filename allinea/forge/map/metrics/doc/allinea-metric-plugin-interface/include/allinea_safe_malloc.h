/*! \file
 *  \brief Async signal safe memory management functions for use in metric plugins
 */

#ifndef ALLINEA_SAFE_MALLOC_H
#define ALLINEA_SAFE_MALLOC_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! \name Memory management functions
 *  \brief Async signal safe replacements for memory management functions.
 *
 *  Since metric library functions need to be async signal safe the standard
 *  libc memory management functions (such as \c malloc, \c free, \c new, \c delete)
 *  cannot be used. The following memory management functions can safely be
 *  used by the metric plugin libraries even if they are called from inside
 *  a signal handler.
 * @{ */

//! An async-signal-safe version of \c malloc.
/*! Allocates a memory region of size bytes. To be used instead of the libc \c malloc.
 *
 *  If memory is exhausted an error is printed to stderr and the process aborted.
 *
 *  Memory allocated by this function should be released by a call to allinea_safe_free().
 *  Do not try to use the libc \c free() to free memory allocated by this function.
 *
 *  \param[in] size  The number of bytes of memory to allocate.
 *
 *  \returns a pointer to the start of the allocated memory region.
 *
 *  \ingroup api */
extern void* allinea_safe_malloc(size_t size);

//! An async-signal-safe version of \c free.
/*! Frees a memory region previously allocated with allinea_safe_malloc.
 *
 *  To be used instead of the libc \c free. Do not use this function to
 *  deallocate memory blocks previously allocated by the libc \c malloc.
 *
 *  \param[in,out] ptr  A pointer to the start of the memory region to free. This should
 *                      have been previously allocated with allinea_safe_malloc(),
                        allinea_safe_realloc(), or allinea_safe_calloc().
 *  \ingroup api */
extern void allinea_safe_free(void *ptr);

//! An async-signal-safe version of \c calloc.
/*! Allocates \p size * \p nmemb bytes and zero-initialises the memory.
 *
 *  To be used instead of the libc \c calloc.
 *
 *  If memory is exhausted an error is printed to stderr and the process aborted.
 *
 *  Memory allocated by this function should be released by a call to allinea_safe_free().
 *  Do not use libc \c free to free memory allocated by this function.
 *
 *  \param[in] nmemb  the number of bytes per element to allocate
 *  \param[in] size   the number of elements to allocate
 *
 *  \returns a pointer to the start of the allocated memory region.
 *
 *  \ingroup api */
extern void* allinea_safe_calloc(size_t nmemb, size_t size);

//! An async-signal-safe version of \c realloc.
/*! Reallocates a memory region if necessary, or allocates
 *  a new one if NULL is supplied for \p ptr.
 *
 *  To be used instead of the libc \c realloc.
 *
 *  If memory is exhausted an error is printed to stderr and the process aborted.
 *
 *  Pointers to memory regions supplied to this function should be allocated
 *  by a call to allinea_safe_malloc(), allinea_safe_calloc() or allinea_safe_realloc().
 *
 *  Memory allocated by this function should be release by a call to allinea_safe_free().
 *  Do not use libc \c free to free memory allocated by this function.
 *
 *  \param[in] ptr   the starting address of the memory region to reallocate
 *  \param[in] size  the new minimum size to request
 *
 *  \returns a pointer to a memory region with at least \p size bytes available
 *
 *  \ingroup api */
extern void* allinea_safe_realloc(void *ptr, size_t size);

//!@} // Doxygen grouping comment

#ifdef __cplusplus
}
#endif

#endif
