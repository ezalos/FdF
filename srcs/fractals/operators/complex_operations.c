#include "head.h"

t_complex	complex_square(t_complex *cpx)
{
	t_complex	square;

	square.real = (cpx->real * cpx->real) - (cpx->imag * cpx->imag);
	square.imag = 2 * cpx->real * cpx->imag;
	return (square);
}

t_complex	complex_cube(t_complex *cpx)
{
	t_complex	cube;

	cube.real = cpx->real * ((cpx->real * cpx->real)\
		- (3 * cpx->imag * cpx->imag));
	cube.imag = (3 * cpx->real * cpx->real * cpx->imag)\
		- (cpx->imag * cpx->imag * cpx->imag);
	return (cube);
}

t_complex	complex_inverse(t_complex *cpx)
{
	t_complex	inverse;

	inverse.real = cpx->real /\
		((cpx->real * cpx->real) + (cpx->imag * cpx->imag));
	inverse.imag = -cpx->imag / (cpx->real * cpx->real + cpx->imag * cpx->imag);
	return (inverse);
}

t_complex	complex_product(t_complex *n1, t_complex *n2)
{
	t_complex	product;

	product.real = (n1->real * n2->real) - (n1->imag * n2->imag);
	product.imag = (n1->real * n2->imag) + (n2->real * n1->imag);
	return (product);
}

double		complex_module(t_complex *cpx)
{
	return ((cpx->real * cpx->real) + (cpx->imag * cpx->imag));
}
