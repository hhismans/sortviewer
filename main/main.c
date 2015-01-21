/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:43:11 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/21 05:43:35 by hhismans         ###   ########.fr       */
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
#include "sortviewer.h"

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

int		get_pixel_color(void *img, int x, int y)
{
	int bbp;
	int sizeline;
	int endian;
	char *data;
	int ret;
	data = mlx_get_data_addr(img, &bbp, &sizeline, &endian);
	bbp /= 8;
	
	ret = data[x *bbp + y *sizeline] * 0x000001;
	ret += data[x *bbp + y *sizeline + 1] * 0x000100;
	ret += data[x *bbp + y *sizeline + 2] * 0x010000;
	ft_putnbr(ret);
	return (ret);
}

void	*upscale_img(t_env *e,void *img,  int prevW, int prevH, int postW, int postH)
{
	int i;
	int j;
	double i2;
	double j2;
	t_img ret;

	i2 = (double)(postW) / (double)(prevW);
	j2 = (double)(postH) / (double)(prevH);
	ret.img = mlx_new_image(e->mlx, postW, postH);
	i = 1;
	while (i < postW)
	{
		j = 1;
		while (j < postH)
		{
			//usleep(100000);	
			//mlx_pixel_put_img(&ret, i, j,get_pixel_color(img, i * i2, j * j2));
			mlx_pixel_put(e->mlx, e->win, i, j, get_pixel_color(img, i * i2, j * j2));
			//usleep(1000);
			j++;
		}
		i++;
	}
	return (ret.img);
}

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
	while (i< 100)
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
	while (i< tab_size)
	{
		ft_putstr("tab [");
		ft_putnbr(i);
		ft_putstr("] :");
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
	mlx_destroy_image(e->mlx, e->img_sort.img);
//	e->img_sort = mlx_new_image(e->mlx, 1000,1000);//SORT_WIDTH, SORT_HEIGHT);
	e->img_sort.img = mlx_new_image(e->mlx, SORT_WIDTH, SORT_HEIGHT);
	p1.x = 50;
	p1.y = SORT_HEIGHT - 50;
	p2.x = 50;
	i = 0;
	while(i / 5 < 100)
	{
		p2.y = p1.y - tab[i / 5] * 3;
		c.color_begin = tab[i / 5] * 10;
		c.color_end = tab[i / 5] * 10;
		ft_drawline_img_c(&(e->img_sort), p1, p2, c);
		p2.x++;
		p1.x++;
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img_sort.img, WIN_WIDTH - SORT_WIDTH,
		WIN_HEIGHT - SORT_HEIGHT);
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
		//	puttab(tab, 100);
			//usleep(100000);
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

/*void		swap_elem(int tab[], t_env *e, int elem1, int elem2)
{
	t_point p1;
	t_point p2;
	t_point ptop;
	t_color c;
	int i;

	i = elem1 * 5;
	while (i < elem1 * 5 + 5)
	{
		ptop.y = 0;
		p1.x = 50 * elem1 * 5;
		p1.y = SORT_HEIGHT - 50;
		p2.x = 50 * elem1 * 5;
		p2.y = p1.y - tab[i / 5] * 3;
		ft_drawline_img(e->img_sort, p1, ptop, 0x000000);
		c.color_begin = tab[i / 5] * 10;
		c.color_end = tab[i / 5] * 10;
		ft_drawline_img_c(e->img_sort, p1, p2, c);
		i++;
	}
	i = elem2 * 5;
		p1.x = 50 * elem2 * 5;
		p1.y = SORT_HEIGHT - 50;
		p2.x = 50 * elem2 * 5;
	while (i < elem2 * 5 + 5)
	{
		ptop.y = 0;
		p1.x = 50;
		p1.y = SORT_HEIGHT - 50;
		p2.x = 50;
		p2.y = p1.y - tab[i / 5] * 3;
		ft_drawline_img(e->img_sort, p1, ptop, 0x000000);
		c.color_begin = tab[i / 5] * 10;
		c.color_end = tab[i / 5] * 10;
		ft_drawline_img_c(e->img_sort, p1, p2, c);
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img_sort, WIN_WIDTH - SORT_WIDTH,
		WIN_HEIGHT - SORT_HEIGHT);
}

void		tab_cocktail_sort(int tab[], int size_tab, t_env *e)
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
			swap_elem(tab, e, i, i + 1);
	//		mlx_put_tab(e, tab);
		//	puttab(tab, 100);
			//usleep(100000);
			tmp = 1;
		}
		i++;
		if (i == size_tab - 1)
		{
			while (i > 0)
			{
				if(tab[i] < tab[i - 1])
				{
					tmp = tab[i];
					tab[i] = tab[i - 1];
					tab[i - 1] = tmp;
					//mlx_put_tab(e, tab);
					swap_elem(tab, e, i, i + 1);
				//		puttab(tab, 100);
				//usleep(100000);
				}
				i--;
			}
		}
		if (tmp != -1)
			tmp = -1;
	}
}*/


t_env	*set_mlx(void)
{
	t_env *e;

	e = (t_env *)malloc(sizeof(*e));
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_WIDTH, WIN_HEIGHT, "Sort_viewer.42");
	e->logo.img = mlx_xpm_file_to_image(e->mlx, "./xpm/logo.xpm",
			&(e->logo_width), &(e->logo_height));
	mlx_put_image_to_window(e->mlx, e->win, e->logo.img, 0,0);
	void *imgtest = upscale_img(e,e->logo.img, e->logo_width, e->logo_height, 500, 500);
	mlx_put_image_to_window(e->mlx, e->win, imgtest, 0,0);
	e->img_sort.img = mlx_new_image(e->mlx, SORT_WIDTH, SORT_HEIGHT);
	e->img_sort.data = mlx_get_data_addr(e->img_sort.img, &(e->img_sort.bbp),
			&(e->img_sort.sizeline), &(e->img_sort.endian));
	e->logo.data = mlx_get_data_addr(e->logo.img, &(e->logo.bbp),
			&(e->logo.sizeline), &(e->logo.endian));
	return (e);
}
int		main(void)
{
	int tab[100];
	t_env *e;

	e = set_mlx();
	set_tab(tab);
//	puttab(tab, 100);
	mlx_put_tab(e, tab);
	tab_bubble_sort(tab, 100, e);
//	mlx_loop(e->mlx);
	return (0);
}
