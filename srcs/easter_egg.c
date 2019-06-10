/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easter_egg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:21:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/06/10 16:02:12 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

int	ft_nice_view(int choice, int x, int y)
{
	if (choice == 0)
		return (ft_random(-2147483648, 2147483647, ((y + 1) / (x + 1)) + 1, 1));
	else if (choice == 1)
		return (ft_random(-2147483648, 2147483647, ((x + 1) / (y + 1)) + 1, 1));
	else if (choice == 2)
		return (ft_random(-2147483648, 2147483647, y + x + 1, 1));
	else if (choice == 3)
		return (ft_random(-2147483648, 2147483647, (y % (x + 1)) + 1, 1));
	else if (choice == 4)
		return (ft_random(-2147483648, 2147483647, ((y * y) + 1 / ((x * x) + 1)) + 1, 1));
	else if (choice == 5)
		return (ft_random(-2147483648, 2147483647, ((y * y) + (x * x)) /(1 + ((x + y) * (x + y))), 1));
	else if (choice == 6)
		return (ft_random(-2147483648, 2147483647, ((y + 1) / (x + 1)) + 1, 1));
	else if (choice == 7)
		return (ft_random(-2147483648, 2147483647, ((y + 1) / (x + 1)) + 1, 1));
	else if (choice == 8)
		return (ft_random(-2147483648, 2147483647, ((y + 1) / (x + 1)) + 1, 1));
	else if (choice == 9)
		return (ft_random(-2147483648, 2147483647, ((y + 1) / (x + 1)) + 1, 1));
	else if (choice == 10)
		return (ft_random(-2147483648, 2147483647, ((y + 1) / (x + 1)) + 1, 1));
	else
		return (0);
}
