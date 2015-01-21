/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 13:48:33 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/21 05:50:03 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include "fdf.h"
#include <mlx.h>
#include "sortviewer.h"

void	mlx_pixel_put_img(t_img *img, int x, int y, int color)
{
	int		i;
	int bbp;

	bbp = img->bbp / 8;
	i = x * bbp + y * img->sizeline;
	if (WIDTH * bbp + HEIGHT * img->sizeline < i)
		return ;
	if (x * bbp > img->sizeline)
		return ;
	if (x >= 0 && y >= 0)
	{
		img->data[i] = color;
		img->data[i + 1] = color >> 8;
		img->data[i + 2] = color >> 16;
	}
}
