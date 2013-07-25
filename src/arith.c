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

/**
 * Add @a and @b and store the result in @a.
 *
 *@a A complex number.
 *@b Another complex number.
 */
inline complex_t *c_add(complex_t *a, complex_t *b)
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
inline complex_t *c_sub(complex_t *a, complex_t *b)
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
inline complex_t *c_mult(complex_t *a, complex_t *b)
{
	a->r = (a->r * b->r) - (a->i * b->i);
	a->i = (a->i * b->r) + (a->r * b->i);
	return a;
}

/**
 * Divide @a by @b and store the result in @a.
 *
 *@a A complex number.
 *@b Another complex number.
 */
inline complex_t *c_div(complex_t *a, complex_t *b)
{
	a->r = ((a->r * b->r) + (a->i * b->i)) /
	       ((b->r * b->r) + (b->i * b->i));
	a->i = ((a->i * b->r) - (a->r * b->i)) /
	       ((b->r * b->r) + (b->i * b->i));
	return a;
}

/**
 * Compute the complex conjugate.
 *
 *@c A complex number.
 */
inline complex_t *c_conj(complex_t *c)
{
	c->r *= -1;
	return c;
}
