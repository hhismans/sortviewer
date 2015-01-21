/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 00:50:35 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/21 00:58:15 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void				ft_drawline_img(void *img_ptr, t_point p1, t_point p2, int color)
{
	while (p1.x <= p2.y)
	{
		mlx_pixel_put_img(img_ptr, p1.x, p1.y, color);
		p1.y++;
	}
}
