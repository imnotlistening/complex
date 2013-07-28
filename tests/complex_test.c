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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <complex/arith.h>

#define tprint(fmt, ...) printf("  %s: " fmt, __func__, ##__VA_ARGS__)

struct complex_test {
	char       *name;
	int       (*run_test)(void);
};

struct unary_op_test {
	cx_t a;
	cx_t res;
	cx_t *(*op)(cx_t *);
};

struct binary_op_test {
	cx_t a;
	cx_t b;
	cx_t res;
	cx_t *(*op)(cx_t *, cx_t *);
};

static int cmpt_binary(void);
static int cmpt_unary(void);

static struct complex_test tests[] = {
	{ "binary", cmpt_binary },
	{ "unary",  cmpt_unary },

	/* NULL terminate. */
	{ NULL,     NULL }
};

/*
 * Simple sanity test for making sure this code works.
 */
int main(int argc, char *argv[])
{
	struct complex_test *t = tests;

	while (t->run_test) {
		printf("# Running test: %s\n", t->name);
		if (!t->run_test())
			printf("-> Passed!\n");
		else
			printf("-> Failed!\n");
		t++;
	}
	return 0;
}

static inline int test_op_binary(cx_t a, cx_t b, cx_t res,
				 cx_t *(*op)(cx_t *, cx_t *))
{
	op(&a, &b);
	return cx_cmp(&a, &res);
}

static inline int test_op_unary(cx_t a, cx_t res,
				cx_t *(*op)(cx_t *))
{
	op(&a);
	return cx_cmp(&a, &res);
}

static struct binary_op_test binary_tests[] = {
	{ cx(1, 1),  cx(-1, -1), cx(0, 0),  cx_add },
	{ cx(2, 0),  cx(0, 2),   cx(2, 2),  cx_add },
	{ cx(1, 1),  cx(-1, -1), cx(2, 2),  cx_sub },
	{ cx(0, 2),  cx(2, 0),   cx(-2, 2), cx_sub },
	{ cx(1, 1),  cx(-1, -1), cx(0, -2), cx_mult },
	{ cx(0, 2),  cx(2, 0),   cx(0, 4),  cx_mult },
	{ cx(-1, 1), cx(-1, -1), cx(2, 0),  cx_mult },
	{ cx(0, 1),  cx(0, -1),  cx(1, 0),  cx_mult },
	{ cx(1, 1),  cx(-1, -1), cx(-1, 0), cx_div },
	{ cx(0, 2),  cx(2, 0),   cx(0, 1),  cx_div },
	{ cx(-1, 1), cx(-1, -1), cx(0, -1), cx_div },
	{ cx(0, 1),  cx(0, -1),  cx(-1, 0), cx_div },

	/* NULL op terminate. */
	{ .op = NULL },
};

static struct unary_op_test unary_tests[] = {
	{ cx(0, 1),  cx(0, -1), cx_conj },

	/* NULL op terminate. */
	{ .op = NULL },
};

static char *op_to_str(void *op)
{
	if (op == cx_add)
		return "c_add";
	else if (op == cx_sub)
		return "c_sub";
	else if (op == cx_mult)
		return "c_mult";
	else if (op == cx_div)
		return "c_div";
	else if (op == cx_conj)
		return "c_conj";
	else
		return "_unknown_";
}

static int cmpt_binary(void)
{
	struct binary_op_test *t = binary_tests;
	int index = 0;
	int ret = 0;
	int pass = 0;

	while (t->op) {
		ret = test_op_binary(t->a, t->b, t->res, t->op);
		tprint("(%d) %s - %s\n", index++, op_to_str(t->op),
		        ret ? "pass!" : "fail!");
		pass -= !ret;
		if (!ret)
			tprint("  Result = [%lf, %lf]\n", t->a.r, t->a.i);
		t++;
	}
	return pass;
}

static int cmpt_unary(void)
{
	struct unary_op_test *t = unary_tests;
	int index = 0;
	int ret = 0;
	int pass = 0;

	while (t->op) {
		ret = test_op_unary(t->a, t->res, t->op);
		tprint("(%d) %s - %s\n", index++, op_to_str(t->op),
		        ret ? "pass!" : "fail!");
		pass -= !ret;
		if (!ret)
			tprint("  Result = [%lf, %lf]\n", t->a.r, t->a.i);
		t++;
	}
	return pass;
}
