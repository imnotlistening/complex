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
#if _COMPLEX_PREC == 8
typedef double complex_component_t;
#else
typedef float complex_component_t;
#endif

/*
 * Complex pair.
 */
typedef struct complex_t {
	complex_component_t r;
	complex_component_t i;
} complex_t;

/*
 * Basic complex arithmetic operations. All binary operations store the result
 * of the computation in the first argument.
 */
inline complex_t *c_add(complex_t *a, complex_t *b);
inline complex_t *c_sub(complex_t *a, complex_t *b);
inline complex_t *c_mult(complex_t *a, complex_t *b);
inline complex_t *c_div(complex_t *a, complex_t *b);
inline complex_t *c_conj(complex_t *c);

/*
 * Macros for obtaining the components of the complex number.
 */
#define complex_r(c) ((c).r)
#define complex_i(c) ((c).i)

#define complex_dr(c) ((double) complex_r(c))
#define complex_sr(c) ((float) complex_r(c))
#define complex_di(c) ((double) complex_i(c))
#define complex_si(c) ((float) complex_i(c))

/*
 * Other useful things.
 */
#define complex(__r, __i) { .r = __r, .i = __i }
#define complex_set(c, __r, __i)			\
	do { (c).r = (__r); (c).i = (__i) } while (0)
#define define_complex(c, r, i) complex_t c = complex(r, i)

#endif
