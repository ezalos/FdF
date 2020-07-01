#include "head.h"


int			*ft_gradient(int color_1, int color_2, int len)
{
	int				*gradient;
	int				i;
	int				new;
	float			add[BGRA];

	i = 0;
	gradient = ft_memalloc(sizeof(int) * len);
	if (!gradient)
		return (NULL);
	gradient[i] = color_1;
	new = color_1;
	space_in_gradient(add, color_1, color_2, len);
	while (len > 1 && ++i < len - 1)
	{
		new = add_color(add, new);
		gradient[i] = new;
	}
	gradient[i] = color_2;
	return (gradient);
}

int		*ft_join_gradient(int *gradient, int *to_add, int size_grad, int size_add)
{
	int		*new;
	int		i;
	int		j;

	if (gradient == NULL)
		return (to_add);
	new = ft_memalloc(sizeof(int) * (size_grad + size_add));
	if (!new)
		return (NULL);
	i = 0;
	while (i < size_grad)
	{
		new[i] = gradient[i];
		i++;
	}
	j = 0;
	while (j < size_add)
	{
		new[i + j] = to_add[j];
		j++;
	}
	return (new);
}
