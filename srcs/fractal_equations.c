/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_equations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deyaberg <deyaberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:16:43 by deyaberg          #+#    #+#             */
/*   Updated: 2020/06/28 23:46:21 by ezalos           ###   ########.fr       */
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
	if (ft_fabs(zn->a) > 2 || ft_fabs(zn->b) > 2
	|| (zn->a * zn->a) + (zn->b * zn->b) > 4)
		return (FALSE);
	return (TRUE);
}
