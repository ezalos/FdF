/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deyaberger <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 18:19:36 by deyaberge         #+#    #+#             */
/*   Updated: 2020/08/02 19:03:53 by deyaberge        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int		tricorn_is_in_set(t_complex *zn)
{
	if (ft_fabs(zn->real) > 2 || ft_fabs(zn->imag) > 2)
		return (FALSE);
	if (complex_module(zn) > 4)
		return (FALSE);
	return (TRUE);
}

int				tricorn_equation(t_complex *zn, t_complex *c)
{
//	zn->imag *= -1;
	*zn = complex_square(zn);
//	zn->imag *= -1;
	zn->imag += c->imag;
	zn->real += c->real;
	return(tricorn_is_in_set(zn));
}
