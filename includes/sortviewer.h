/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortviewer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 17:41:04 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/21 01:47:12 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTVIEWER_H
# define SORTVIEWER_H

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define SORT_WIDTH 1000
# define SORT_HEIGHT 600

typedef struct		s_img
{
	void			*img;
	int				bbp;
	int				endian;
	int				sizeline;
	char			*data;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			logo;
	t_img			img_sort;
	int				logo_width;
	int				logo_height;
}					t_env;

#endif
