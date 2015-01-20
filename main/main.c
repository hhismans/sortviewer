/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:43:11 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/20 03:05:23 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
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
/*void	*upscale_img(void *img, int prevW, int prevH, int postW, int postH)
{
	int i;
	int j;
	int bbp;
	int size_line;
	int endian;
	char *data;

	data = mlx_get_data_addr(img, &bbp, &sizeline, &endian);
	while (i < prevW)
	{
		j = 0;
		while (j < size_line)
		{
			data[j] = 0;
			j++;
		}
	}
}*/

int		rand_a_b(int a, int b){
    return rand()%(b-a) +a;
}

void	set_tab(int tab[])
{
	int i;
	int j;
	int k;
	int tmp;

	i = 0;
	while (i < 100)
	{
		tab[i] = i;
		i++;
	}
	i = 0;
	while (i < 1000)
	{
		j = rand_a_b(0, 100);
		k = rand_a_b(0, 100);
		tmp = tab[j];
		tab[j] = tab[k];
		tab[k] = tmp;
		i++;
	}
}

void puttab(int tab[], int tab_size)
{
	int i;

	i = 0;
	while (i < tab_size)
	{
		ft_putnbr(tab[i]);
		ft_putendl("");
		i++;
	}
}

void		mlx_put_tab(t_env *e, int tab[])
{
	int i;
	t_point p1;
	t_point p2;
	t_color c;
	mlx_destroy_image(e->mlx, e->img2);
	e->img2 = mlx_new_image(e->mlx, 1000, 1000);
	p1.x = 100;
	p1.y = 900;
	p2.x = 100;
	i = 0;
	while(i / 4 < 100)
	{
		p2.y = 900 - tab[i / 4] * 3;
		c.color_begin = tab[i / 4] * 10;
		c.color_end = tab[i / 4] * 10;
		ft_putnbr(tab[i] * 10);
		ft_putstr("rainbow color: ");
		ft_putnbr(c.color_begin);
		ft_putendl("");
		ft_drawline_img_c(e->img2, p1, p2, c);
		p2.x++;
		p1.x++;
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img2, 0, 0);
}

void		tab_bubble_sort(int tab[], int size_tab, t_env *e)
{
	int i;
	int tmp;
	i = 0;
	tmp = -1;
	while(i < size_tab)
	{
		if(tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			mlx_put_tab(e, tab);
			//usleep(10);
			tmp = 1;
		}
		i++;
		if (i == size_tab - 1 && tmp == 1)
		{
			i = 0;
			tmp = -1;
		}
	}
}


int		main(void)
{
	int h;
	int w;
	int tab[100];
	t_env *e;

	h = 300;
	w = 300;
	e = (t_env *)malloc(sizeof(*e));
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1000, 1000, "Sort_viewer.42");
	e->img = mlx_xpm_file_to_image(e->mlx, "./xpm/logo.xpm", &w, &h);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0,0);
	e->img2 = mlx_new_image(e->mlx, 1000, 1000);

	set_tab(tab);
	puttab(tab, 100);
	//mlx_put_image_to_window(e->mlx, e->win, e->img2,0,0);
	tab_bubble_sort(tab, 100, e);
	mlx_loop(e->mlx);
/*	father = fork();
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
	}*/
	return (0);
}
