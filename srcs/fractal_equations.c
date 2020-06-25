/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_equations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deyaberger <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:16:43 by deyaberge         #+#    #+#             */
/*   Updated: 2020/06/24 18:17:04 by deyaberge        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int		mandelbrot_equation(t_complex *zn, t_complex *c)
{
	float	a_sqr;
	float	b_sqr;
	float	two_ab;
	float	real;


	// Zn+1 = Zn^2 + c
	a_sqr = zn->a * zn->a;
	b_sqr = zn->b * zn->b;
	two_ab = 2 * zn->b * zn->a;
	real = a_sqr + (-1 * b_sqr);
	zn->a = real + c->a;
	zn->b = two_ab + c->b;
	if (zn->a > 2 || zn->b > 2 || zn->a < -2 || zn->b < -2
	|| sqrt((zn->a * zn->a) + (zn->b * zn->b)) > 2)
		return (FALSE);
	return (TRUE);
}
