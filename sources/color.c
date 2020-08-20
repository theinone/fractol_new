/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theinone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 10:57:03 by theinone          #+#    #+#             */
/*   Updated: 2020/08/20 10:57:05 by theinone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		color_scheme_1(t_frac *frac, int i)
{
	int c;

	c = 0;
	if (i == 0 || i >= frac->max_iter)
		frac->color = 0x000000;
	else
	{
		frac->color = 0x000055;
		while (c++ < i)
			frac->color++;
	}
}

void		color_scheme_2(t_frac *frac, int i)
{
	if (i == 0 || i >= frac->max_iter)
		frac->color = 0x000000;
	else if (i % 3 == 0)
		frac->color = 0x000000;
	else if (i % 4 == 0)
		frac->color = 0x0D1826;
	else if (i % 5 == 0)
		frac->color = 0x16F2B4;
	else if (i % 6 == 0)
		frac->color = 0xF2B279;
	else if (i % 7 == 0)
		frac->color = 0xF25050;
	else if (i % 8 == 0)
		frac->color = 0x027368;
	else if (i % 9 == 0)
		frac->color = 0xA7C8F2;
	else
		frac->color = 0xff0000;
}

void		set_color(t_frac *frac, int i)
{
	if (frac->color_scheme == 1)
		color_scheme_1(frac, i);
	else if (frac->color_scheme == 2)
		color_scheme_2(frac, i);
}
