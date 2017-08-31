/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:36:33 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/31 13:37:36 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define USAGE "Usage : ./fractol [Mandelbrot | Julia | Newton]"

/*
** Define colors
*/
# define MENGER 0xBD8D46
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define ORANGE 0xED7F10
# define YELLOW 0xFFFF00
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define PURPLE 0xA020F0
# define BROWN 0x582900
# define BLACK 0x000000

/*
** Define keycode & event & mask
*/
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define MAX_ITER 42
# define W_WIDTH 600
# define W_HEIGHT 600

typedef struct			s_hsl
{
	float				c;
	float				t;
	float				x;
	float				m;
}						t_hsl;

typedef struct			s_plex
{
	double				r;
	double				i;
}						t_plex;

typedef struct			s_env
{
	double				zoom;
	double				px;
	double				py;
	double				max_x;
	double				max_y;
	double				min_x;
	double				min_y;
	int					move_r;
	int					move_i;
	int					help;
	int					fract_name;
	int					nvar;
	int					grey;
	t_plex				julia;
	double				move;
	void				*mlx;
	void				*win;
	void				*img;
	void				*img_b;
	int					color_m;
	int					color_picker;
	int					c_lock;
	char				*data;
	char				*data_b;
	int					bpp;
	int					sizeline;
	int					sizeline_b;
	int					endian;
	int					iter;
	int					auto_i;
	int					max_i;
	int					music;
}						t_env;

typedef struct			s_color
{
	float				r;
	float				g;
	float				b;
	int					rr;
	int					gg;
	int					bb;
}						t_color;

typedef struct			s_calc
{
	t_plex				point;
	t_plex				new;
	t_plex				old;
}						t_calc;

/*
** Functions of newton.c
*/
int						newton_calc(int x, int y, t_env *env);
t_plex					f(t_plex plx, int nvar);
t_plex					df(t_plex plx, int nvar);
void					newton(t_env *env);

/*
** Functions of complex_calc.c
*/
t_plex					c_mul(t_plex un, t_plex deux);
t_plex					c_div(t_plex un, t_plex deux);
t_plex					c_sous(t_plex un, t_plex deux);
t_plex					c_add(t_plex un, t_plex deux);
t_plex					map(int x, int y, t_env *env, int pxy);

/*
** Functions of error.c
*/
void					error_init(t_env *env, int mode);
void					error_str(char *str, t_env *env, int mode);
void					free_all(t_env *env);

/*
** Functions of mandelbrot.c
*/
int						mandelbrot_calc(int x, int y, t_env *env);
void					mandelbrot(t_env *env);
void					melting_pot(t_env *env);
int						melting_calc(int x, int y, t_env *env);

int						menger_calc(int x, int y, t_env *env);
void					menger(t_env *env);

/*
** Functions of burning_ship.c
*/
int						burning_calc(int x, int y, t_env *env);
void					burning_ship(t_env *env);

/*
** Functions of julia.c
*/
int						julia_calc(int x, int y, t_env *env);
void					julia(t_env *env);

/*
** Functions of mlx.c
*/
void					set_var(t_env *env);
void					pixel_put_image(unsigned long img_color, int x, int y,
		t_env *env);

/*
** Functions of update.c
*/
void					zoom(int keycode, t_env *env);
void					maj_var(t_env *env);
void					maj_julia(t_env *env);
int						maj_iter(int fract);

/*
** Functions of color.c
*/
unsigned int			set_color(int hauteur1, int black, t_env *env);
unsigned int			get_color(float h, float s, float l, t_env *env);
void					init_hsl(t_hsl *calc, float h, float s, float l);
void					calc_rgb(float l, t_hsl *calc, t_color *color);
float					choose_rgb(float r, float g, float b, t_color *c);

/*
** Functions of draw.c
*/
int						draw(t_env *env);
void					draw_fract(int fract, t_env *env);
void					print_info(t_env *env);
void					print_info2(t_env *env);

/*
** Functions of key_hook.c
*/
int						key_hook(int keycode, t_env *env);
int						key_hook2(int keycode, t_env *env);
int						key_hook3(int keycode, t_env *env);
int						key_hook4(int keycode, t_env *env);
int						key_hook5(int keycode, t_env *env);

/*
** Functions of mouse_hook.c
*/
int						exit_cross(t_env *env);
int						mouse_hook(int button, int x, int y, t_env *env);
int						mouse_move(int x, int y, t_env *env);
void					zoom_in(t_plex m, t_env *env);
void					zoom_out(t_plex m, t_env *env);

/*
** Functions of str_tools.c
*/
int						is_fract_name(char *str);
int						is_alnum_comma(char c);
int						is_white(char c);

/*
** Functions of help.c
*/
void					print_help(t_env *env);
void					print_help2(int d, int h, t_env *env);
void					create_help(t_env *env);
void					destroy_help(t_env *env);

/*
** Functions of init
*/
void					init_mlx(t_env *env);
char					*fract_name(t_env *env);
void					make_it_uni(t_env *env, unsigned int color);
void					make_it_b(t_env *env);
void					pixel_b(unsigned int color, int x, int y, t_env *env);
#endif
