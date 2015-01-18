/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:43:11 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/18 19:04:36 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
/*int		expose(t_env *e)
{
	t_point **tab_conv;

	if (e->perspec == AXONO)
		tab_conv = convert_map(*e, conv_axono);
	else if (e->perspec == CAVALIERE)
		tab_conv = convert_map(*e, conv_cavaliere);
	mlx_destroy_image((*e).mlx, (*e).img);
	(*e).img = mlx_new_image((*e).mlx, WIDTH, HEIGHT);
	draw_grid(*e, tab_conv, e->tab_int, e->gamme * e->mult_z / 5);
	mlx_put_image_to_window((*e).mlx, (*e).win, (*e).img, 0, 0);
	free(tab_conv);
	return (0);
}

void	key_hook2(int keycode, t_env *e)
{
}

void	key_hook3(int keycode, t_env *e)
{
}

int		key_hook(int keycode, t_env *e)
{
}*/
#define GOTOSON 0
#define GOTOFATHER 1
void	*upscale_img(void *img, int prevW, int prevH, int postW, int postH)
{
	int i;
	int bbp;
	int size_line;
	int endian;
	char *data;

	data = mlx_get_data_addr(img, &bbp, &sizeline, &endian);
	while (i < prevW)
	{
		j = 0;
		while (j < sizeline)
		{
			data[j] = 
			j++;
		}
	}
}
int		main(void)
{
	int h;
	int w;
	int father;
	int *tmp;
	t_env *e;

	h = 300;
	w = 300;
	e = (t_env *)malloc(sizeof(*e));
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1000, 1000, "Sort_viewer.42");
	e->img = mlx_xpm_file_to_image(e->mlx, "./xpm/logo.xpm", &w, &h);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0,0);
	tmp = (int *)ft_memalloc(4);
	father = fork();
	*tmp = 1;
	if (father == 0)
	{
		while(1)
		{
		//	printf("in father\t*tmp = %p\ttmp = %d \n", tmp, *tmp);
			if (*tmp == GOTOFATHER)
			{
				ft_putendl("father hllo");
				*tmp = GOTOSON;
			}
		}
	}
	else if (father != 0)
	{
		while(1)
		{
	//		printf("in son\t\t*tmp = %p\ttmp = %d \n", tmp, *tmp);
			if (*tmp == GOTOSON)
			{
				ft_putendl("son hellow");
				*tmp = GOTOFATHER;
			}
//			printf("son tmp = %p\n", tmp);
		}
	}
	return (0);
}
