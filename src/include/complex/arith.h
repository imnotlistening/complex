/*
 * (C) Copyright 2013
 * Alex Waterman <imNotListening@gmail.com>
 *
 * complex is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * complex is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with complex.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _COMPLEX_ARITH
#define _COMPLEX_ARITH

/*
 * Size of each component of the complex number.
 */
#if _COMPLEX_PREC == 8 || !defined(_COMPLEX_PREC)
typedef double complex_component_t;
#elif _COMPLEX_PREC == 4
typedef float complex_component_t;
#else
#error Invalid complex precision; use either 4 or 8.
#endif

/*
 * Complex pair.
 */
typedef struct complex_t {
	complex_component_t r;
	complex_component_t i;
} cx_t;

/*
 * Basic complex arithmetic operations. All binary operations store the result
 * of the computation in the first argument.
 */
inline cx_t *cx_add(cx_t *a, cx_t *b);
inline cx_t *cx_sub(cx_t *a, cx_t *b);
inline cx_t *cx_mult(cx_t *a, cx_t *b);
inline cx_t *cx_div(cx_t *a, cx_t *b);
inline cx_t *cx_conj(cx_t *c);
inline int   cx_cmp(cx_t *a, cx_t *b);

/*
 * Macros for obtaining the components of the complex number.
 */
#define cx_r(c) ((c)->r)
#define cx_i(c) ((c)->i)

#define cx_dr(c) ((double) cx_r(c))
#define cx_sr(c) ((float)  cx_r(c))
#define cx_di(c) ((double) cx_i(c))
#define cx_si(c) ((float)  cx_i(c))

/*
 * Other useful things.
 */
#define cx(__r, __i) { .r = __r, .i = __i }
#define cx_set(c, __r, __i)			\
	do { (c)->r = (__r); (c)->i = (__i) } while (0)
#define define_cx(c, r, i) cx_t c = cx(r, i)

#endif
