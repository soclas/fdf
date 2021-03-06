/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <nkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 23:58:16 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/20 04:51:08 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define CORTEX 12
# define MINUS 13
# define ADD_D 14
# define RM_D 15
# define COLOR_N 17

# define MALLOC_ERROR "Error : malloc"
# define READ_ERROR "Error : read"
# define OPEN_ERROR "Error : open"
# define LINE_ERROR "Error : wrong line lenght"
# define CHAR_ERROR "Error : wrong char in file"

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_env
{
	int			reso;
	void		*mlx;
	void		*win;
	int			l;
	int			i;
	int			length;
	int			zoom;
	int			mvtx;
	int			mvty;
	float		z;
	int			**tab;
	float		x;
	float		y;
	float		x0;
	float		x1;
	float		y0;
	float		y1;
	t_img		*img;
	int			tab_c[10];
	int			color_index;
	int			color_display;
}				t_env;

void			ft_color(t_env *e);
void			draw_between(t_env *e);
void			draw_col(t_env *e, int j, int i);
void			draw_line(t_env *e, int j, int i);
int				draw_map(t_env *e);
int				ft_start_struct(char *buffer, int nbl, int nbi, int i);
int				ft_check(char *buffer, int i, int num, int start);
int				ft_length_error(char *buffer);
int				ft_start_error(char *buffer);
int				ft_invalid(char *buffer, int i);
int				ft_expose_hook(t_env *e);
int				ft_key_hook2(int keycode, t_env *e);
int				ft_key_hook3(int keycode, t_env *e);
int				ft_key_hook(int keycode, t_env *e);
int				**ft_tab(char *buffer, int nbl, int nbi, int j);
int				ft_start_exe(char *argv, int argc, int *ed);
char			*ft_endbuffer(char *buffer, int *length);

#endif
