/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theinone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:53:43 by theinone          #+#    #+#             */
/*   Updated: 2020/02/20 15:44:30 by theinone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		draw(t_frac *frac)
{
	frac->x = 0;
	frac->y = 0;
	while (frac->y < W_HEIGHT)
	{
		while (frac->x < W_WIDTH)
		{
			if (frac->fractal == 0)
				set_color(frac, mandelbrot(frac));
			else if (frac->fractal == 1)
				set_color(frac, julia(frac));
			else
				set_color(frac, mandelbar(frac));
			frac->data[frac->y * W_WIDTH + frac->x] = frac->color;
			frac->x++;
		}
		frac->x = 0;
		frac->y++;
	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->win, frac->img_ptr, 0, 0);
}

void		init_fractol(char *name)
{
	t_frac frac;

	frac.mlx_ptr = mlx_init();
	if (ft_strcmp(name, "mandelbrot") == 0)
		frac.fractal = 0;
	else if (ft_strcmp(name, "julia") == 0)
		frac.fractal = 1;
	else if (ft_strcmp(name, "mandelbar") == 0)
		frac.fractal = 2;
	frac.win = mlx_new_window(frac.mlx_ptr, W_WIDTH, W_HEIGHT, name);
	frac.img_ptr = mlx_new_image(frac.mlx_ptr, W_WIDTH, W_HEIGHT);
	frac.size_l = 16;
	frac.bpp = 16;
	frac.endian = 1;
	frac.data = (int *)mlx_get_data_addr(frac.img_ptr, &frac.bpp,
	&frac.size_l, &frac.endian);
	frac.zoom = 0.5;
	frac.max_iter = 50;
	frac.color_scheme = 1;
	frac.mvx = 0.1;
	frac.mvy = 0.1;
	draw(&frac);
	mlx_key_hook(frac.win, keypressed, &frac);
	mlx_mouse_hook(frac.win, zoom, &frac);
	mlx_loop(frac.mlx_ptr);
}

void		show_usage(void)
{
	ft_putendl("Usage: ./fractol <fractal name>");
	ft_putendl("Available fractals:");
	ft_putendl("mandelbrot");
	ft_putendl("julia");
	ft_putendl("mandelbar");
}

int			check_name(char *name)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(name, "julia") == 0)
		return (1);
	else if (ft_strcmp(name, "mandelbar") == 0)
		return (1);
	else
		return (0);
}

int			main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("error: insufficient input. See usage.");
		show_usage();
		exit(0);
	}
	if (check_name(argv[1]) == 0)
	{
		ft_putendl("error: insufficient input. See usage.");
		show_usage();
		exit(0);
	}
	init_fractol(argv[1]);
	return (0);
}
