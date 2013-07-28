                            Complex Mathematics API
                            =======================

Table of Contents
-----------------

  1.   Overview
  2.   Basic Usage
  3.   Full API Specification
  4.   Building


Overview
--------

This aims to be a simple C implmentation of the basic complex arithmetic
operations. This supports both single and double precision floating point
arithmetic depending on C preprocessor options.


Basic Usage
-----------

All operations are either unary or binary. All operations expect their
arguments as pointers to a cx_t and return a pointer to the first argument
passed. Operations store their results in the first argument passed. Here is
and example usage:

  define_cx(cx1, 0, 1);
  cx_t cx2 = { 4, -5 };
  cx_t *result;

  /* result == &cx1 */
  result = cx_add(&cx1, &cx2);

  printf("Result = [%.3f, %.3f]\n", cx_sr(result), cx_si(result));

This will print:

  Result = [-4.000, -4.000]

Similar usage can be use for the other operations.


Full API Specification
----------------------

cx_t is an opaque type describing a complex value.

inline cx_t *cx_add(cx_t *a, cx_t *b);
inline cx_t *cx_sub(cx_t *a, cx_t *b);
inline cx_t *cx_mult(cx_t *a, cx_t *b);
inline cx_t *cx_div(cx_t *a, cx_t *b);
inline cx_t *cx_conj(cx_t *c);
inline int   cx_cmp(cx_t *a, cx_t *b);

/*
 * @c is a pointer to cx_t - these macros return the real and imaginary parts
 * of the passed complex value.
 */
#define cx_r(c)
#define cx_i(c)

/*
 * Similar to cx_r() and cx_i, these return the real and imaginry parts of the
 * passed cx_t pointer; however, these macros explicitly cast those values to
 * either a single or double precision floating point value.
 */
#define cx_dr(c)
#define cx_sr(c)
#define cx_di(c)
#define cx_si(c)

/*
 * Makes a complex value. E.g:
 *
 *   cx_t c = cx(1, 2);
 */
#define cx(__r, __i)

/*
 * Set the passed cx_t pointer to the specified real and imaginary parts.
 */
#define cx_set(c, __r, __i)

/*
 * Defines a complex variable. E.g:
 *
 *   define_cx(c, 1, 2);
 *
 * 'c' is now a complex value with real component equal to 1 and imaginary
 * component equal to 2.
 */
#define define_cx(c, r, i)


Building
========

Building this library is very simple. In the src directory just run make. This
makes some guesses about what you want. You can override the defaults if you
wish. If you build this inside of a project make sure that the library and the
rest of the project agree on whether single or double precision arithmetic is
being used. If unsure, use tyhe default (double).
