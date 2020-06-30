#include "head.h"

double	pix_to_math(double pixel, double size, double start, double end)
{
	double small;

	small = start + ((double)((double)pixel / (double)size) * (double)(end - start));
	return (small);
}
