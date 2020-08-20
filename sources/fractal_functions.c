/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theinone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 10:45:50 by theinone          #+#    #+#             */
/*   Updated: 2020/08/20 10:45:52 by theinone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			mandelbrot(t_frac *f)
{
	f->pr = 2.0 * (f->x - W_WIDTH / 2) / (0.5 * f->zoom * W_WIDTH) + f->mvx;
	f->pi = 2.0 * (f->y - W_HEIGHT / 2) / (0.5 * f->zoom * W_HEIGHT) + f->mvy;
	f->n_re = 0;
	f->n_im = 0;
	f->o_re = 0;
	f->o_im = 0;
	f->iterations = 0;
	while (f->iterations < f->max_iter)
	{
		f->o_re = f->n_re;
		f->o_im = f->n_im;
		f->n_re = f->o_re * f->o_re - f->o_im * f->o_im + f->pr;
		f->n_im = 2 * f->o_re * f->o_im + f->pi;
		if ((f->n_re * f->n_re + f->n_im * f->n_im) > 4)
			break ;
		f->iterations++;
	}
	return (f->iterations);
}

int			mandelbar(t_frac *f)
{
	f->pr = 2.0 * (f->x - W_WIDTH / 2) / (0.5 * f->zoom * W_WIDTH) + f->mvx;
	f->pi = 2.0 * (f->y - W_HEIGHT / 2) / (0.5 * f->zoom * W_HEIGHT) + f->mvy;
	f->n_re = 0;
	f->n_im = 0;
	f->o_re = 0;
	f->o_im = 0;
	f->iterations = 0;
	while (f->iterations < f->max_iter)
	{
		f->o_re = f->n_re;
		f->o_im = f->n_im;
		f->n_re = f->o_re * f->o_re - f->o_im * f->o_im + f->pr;
		f->n_im = -2 * f->o_re * f->o_im + f->pi;
		if ((f->n_re * f->n_re + f->n_im * f->n_im) > 4)
			break ;
		f->iterations++;
	}
	return (f->iterations);
}

int			julia_movement(int x, int y, t_frac *f)
{
	f->j_re = 2.0 * (x - W_WIDTH / 2) / (0.5 * f->zoom * W_WIDTH) + f->mvx;
	f->j_im = 2.0 * (y - W_HEIGHT / 2) / (0.5 * f->zoom * W_HEIGHT) + f->mvy;
	draw(f);
	return (0);
}

int			julia(t_frac *f)
{
	f->n_re = 2.0 * (f->x - W_WIDTH / 2) / (0.5 * f->zoom * W_WIDTH) + f->mvx;
	f->n_im = 2.0 * (f->y - W_HEIGHT / 2) / (0.5 * f->zoom * W_HEIGHT) + f->mvy;
	mlx_hook(f->win, 6, (1L << 6), julia_movement, f);
	f->iterations = 0;
	while (f->iterations < f->max_iter)
	{
		f->o_re = f->n_re;
		f->o_im = f->n_im;
		f->n_re = f->o_re * f->o_re - f->o_im * f->o_im + f->j_re;
		f->n_im = 2 * f->o_re * f->o_im + f->j_im;
		if ((f->n_re * f->n_re + f->n_im * f->n_im) > 4)
			break ;
		f->iterations++;
	}
	return (f->iterations);
}
