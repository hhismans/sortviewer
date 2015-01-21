/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 19:07:06 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/21 01:53:30 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "sortviewer.h"
# define HEIGHT			1080
# define WIDTH			1920
# define BLUE			0x0000FF
# define GREEN			0x00FF00
# define RED			0xFF0000

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_color
{
	int				color_begin;
	int				color_end;
}					t_color;


int					expose(t_env *e);
void				map_rot(t_env *e);
void				ft_drawline(t_env env, t_point p1, t_point p2, int color);
void				ft_drawline_img(void *img_ptr, t_point p1, t_point p2, \
		int color);
void				ft_drawline_img_c(t_img *img_ptr, t_point p1, t_point p2, \
		t_color c);
void				ft_drawline_img_c_1(t_img *img_ptr, t_point p1, t_point p2, \
		t_color c);
void				ft_drawline_img_c_2(t_img *img_ptr, t_point p1, t_point p2, \
		t_color c);
void				ft_drawline_img_c_3(t_img *img_ptr, t_point p1, t_point p2, \
		t_color c);
void				case_horiz(t_img *img, t_point p1, t_point p2, \
		t_color c);
void				case_horizneg(t_img *img, t_point p1, t_point p2, \
		t_color c);
void				case_verti(t_img *img, t_point p1, t_point p2, \
		t_color c);
void				case_vertineg(t_img *img, t_point p1, t_point p2, \
		t_color c);
int					**getinfo(t_env *e, char *file);
void				conv_axono(t_env e, t_point *point, int i, int j);
void				conv_cavaliere(t_env e, t_point *point, int i, int j);
t_point				**convert_map(t_env e, \
		void (*conv)(t_env, t_point *, int, int));
void				draw_grid(t_env e, t_point **tab, int **tab_int, int gamme);
void				mlx_pixel_put_img(t_img *img, int x, int y, int color);
void				window_color(t_env e, void *img, int color, int x, int y);
int					rainbow_gen(int x);

#endif
