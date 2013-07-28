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
 */

#include <complex/arith.h>

#include <stdio.h>

/**
 * Add @a and @b and store the result in @a.
 *
 *@a A complex number.
 *@b Another complex number.
 */
inline cx_t *cx_add(cx_t *a, cx_t *b)
{
	a->r += b->r;
	a->i += b->i;
	return a;
}

/**
 * Subtract @b from @a and store the result in @a.
 *
 *@a A complex number.
 *@b Another complex number.
 */
inline cx_t *cx_sub(cx_t *a, cx_t *b)
{
	a->r -= b->r;
	a->i -= b->i;
	return a;
}

/**
 * Multiple @a and @b and store the result in @a.
 *
 *@a A complex number.
 *@b Another complex number.
 */
inline cx_t *cx_mult(cx_t *a, cx_t *b)
{
	double temp;
	temp = (a->r * b->r) - (a->i * b->i);
	a->i = (a->i * b->r) + (a->r * b->i);
	a->r = temp;
	return a;
}

/**
 * Divide @a by @b and store the result in @a.
 *
 *@a A complex number.
 *@b Another complex number.
 */
inline cx_t *cx_div(cx_t *a, cx_t *b)
{
	double temp;
	temp = ((a->r * b->r) + (a->i * b->i)) /
	       ((b->r * b->r) + (b->i * b->i));
	a->i = ((a->i * b->r) - (a->r * b->i)) /
	       ((b->r * b->r) + (b->i * b->i));
	a->r = temp;
	return a;
}

/**
 * Returns true if the two passed complex numbers are the same.
 *
 *@a A complex number.
 *@b Another complex number.
 */
inline int cx_cmp(cx_t *a, cx_t *b)
{
	return (a->r == b->r) && (a->i == b->i);
}

/**
 * Compute the complex conjugate.
 *
 *@c A complex number.
 */
inline cx_t *cx_conj(cx_t *c)
{
	c->i *= -1;
	return c;
}
