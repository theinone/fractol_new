/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theinone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:01:25 by theinone          #+#    #+#             */
/*   Updated: 2020/08/20 11:01:27 by theinone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			keypressed(int keycode, t_frac *frac)
{
	if (keycode == MAIN_PAD_ESC)
		exit(0);
	else if (keycode == ARROW_UP)
		frac->mvy = frac->mvy - (0.1 / frac->zoom);
	else if (keycode == ARROW_DOWN)
		frac->mvy = frac->mvy + (0.1 / frac->zoom);
	else if (keycode == ARROW_LEFT)
		frac->mvx = frac->mvx + (0.1 / frac->zoom);
	else if (keycode == ARROW_RIGHT)
		frac->mvx = frac->mvx - (0.1 / frac->zoom);
	else if (keycode == NUMPAD_PLUS || keycode == KEY_PLUS)
		frac->zoom = frac->zoom * 2;
	else if (keycode == NUMPAD_MINUS || keycode == KEY_MINUS)
		frac->zoom = frac->zoom / 2;
	else if (keycode == NUMPAD_ENTER || keycode == KEY_ENTER)
		frac->max_iter += 10;
	else if (keycode == KEY_ONE)
		frac->color_scheme = 1;
	else if (keycode == KEY_TWO)
		frac->color_scheme = 2;
	draw(frac);
	return (0);
}

int			zoom(int button, int x, int y, t_frac *frac)
{
	if (x > 0 && y > 0)
	{
		if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		{
			if (button == MOUSE_SCROLL_UP)
				frac->zoom = frac->zoom * 1.2;
			else
				frac->zoom = frac->zoom * 0.8;
			draw(frac);
		}
	}
	return (0);
}
