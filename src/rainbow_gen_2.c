/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow_gen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 06:35:47 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/11 02:49:59 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*static void set_rgb(int *tab, int r, int g, int b)
{
	tab[0] = r;
	tab[1] = g;
	tab[2] = b;
}*/

int			rainbow_gen(int x)
{
	int color_begin[3];
	int color_end[3];
	int color;
	int tab[3];

	color = 0;
	if (x <= 0)
		return (0x0544FF);
	if (x > 1530)
		return (0xFFFFFF);
	if (x >= 0 && x < 1000)
	{
		color_begin[0] = 0x52;
		color_begin[1] = 0xF5;
		color_begin[2] = 0x12;
		color_end[0] = 0x24;
		color_end[1] = 0x72;
		color_end[2] = 0x00;
		tab[0] = color_begin[0] + ((color_end[0] - color_begin[0]) * x) / 1000;
		tab[1] = color_begin[1] + ((color_end[1] = color_begin[1]) * x) / 1000;
		tab[2] = color_begin[1] + ((color_end[2] = color_begin[2]) * x) /  1000;
	}

	if (x >= 1000 && x < 1250)
	{
		color_begin[0] = 0x24;
		color_begin[1] = 0x72;
		color_begin[2] = 0x00;
		color_end[0] = 0x74;
		color_end[1] = 0xF0;
		color_end[2] = 0x0F;
		tab[0] = color_begin[0] + ((color_end[0] - color_begin[0]) * (x - 1000)) / 250;
		tab[1] = color_begin[1] + ((color_end[1] = color_begin[1]) * (x - 1000)) / 250;
		tab[2] = color_begin[1] + ((color_end[2] = color_begin[2]) * (x - 1000)) /  250;
	}

	if (x >= 1250 && x < 1530)
	{
		color_begin[0] = 0x74;
		color_begin[1] = 0xF0;
		color_begin[2] = 0x0F;
		color_end[0] = 0xFF;
		color_end[1] = 0xFF;
		color_end[2] = 0xFF;
		tab[0] = color_begin[0] + ((color_end[0] - color_begin[0]) * (x - 1250)) / 280;
		tab[1] = color_begin[1] + ((color_end[1] = color_begin[1]) * (x - 1250)) / 280;
		tab[2] = color_begin[1] + ((color_end[2] = color_begin[2]) * (x - 1250)) /  280;
	}
/*
		set_rgb(tab, 255, x, 0);
	if (255 <= x && x < 510)
		set_rgb(tab, 510 - x, 255, 0);
	if (510 <= x && x < 765)
		set_rgb(tab, 0, 255, x - 510);
	if (765 <= x && x < 1020)
		set_rgb(tab, 0, 1020 - x, 255);
	if (x >= 1020 && x <= 1530)
		set_rgb(tab, x - 1020, 0, 255);
	if (x >= 1275 && x <= 1530)
		set_rgb(tab, 255, 0, 1530 - x);*/
	color = tab[0] * 0x010000 + tab[1] * 0x000100 + tab[2] * 0x000001;
	return (color);
}
