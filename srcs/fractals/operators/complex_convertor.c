#include "head.h"

float	pix_to_math(float pixel, float size, float start, float end)
{
	float small;

	small = start + ((pixel / size) * (end - start));
	return (small);
}
