/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deyaberg <deyaberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:16:43 by deyaberg          #+#    #+#             */
/*   Updated: 2020/07/01 01:42:03 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int		mandelbrot_is_in_set(t_complex *zn)
{
	if (ft_fabs(zn->real) > 2 || ft_fabs(zn->imag) > 2)
		return (FALSE);
	if (complex_module(zn) > 4)
		return (FALSE);
	return (TRUE);
}

int				mandelbrot_equation(t_complex *zn, t_complex *c)
{
	*zn = complex_square(zn);
	zn->imag += c->imag;
	zn->real += c->real;
	return(mandelbrot_is_in_set(zn));
}
