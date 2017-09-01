/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:36:33 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/01 16:42:06 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# define USAGE "Usage : ./wolf3d"
# define BUFF_SIZE 1001

/*
** WALL_H 64 mean 64px of height for each "wall in real"
*/
# define WALL_H 64

/*
** Define colors
*/
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
# define W_WIDTH 320
# define W_HEIGHT 200

typedef struct			s_hsl
{
	float				c;
	float				t;
	float				x;
	float				m;
}						t_hsl;

typedef struct			s_pos
{
	double				x;
	double				y;
}						t_pos;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_cam
{
	t_pos				pos;
	t_point				point;
	double				angle;
	double				little_a;
	double				dist_e;
	double				dir;
}						t_cam;

typedef struct			s_env
{
	char				*line;
	char				**tab_file;
	int					**map;
	int					max_y;
	int					max_x;
	t_cam				cam;
	double				zoom;
	int					help;
	int					nvar;
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
	unsigned int		color;
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

/*
** Functions of error.c
*/
void					error_init(t_env *env, int mode);
void					error_str(char *str, t_env *env, int mode);

/*
** Functions of tools.c
*/
double					rad2deg(double angle);
double					deg2rad(double angle);
int						test_line(char *s);
int						is_num(char c);

/*
** Function of free_x.c
*/
void					free_tab(char **tab);
void					free_no_win(t_env *env);
void					free_all(t_env *env);
void					free_map(t_env *enc);

/*
** Functions of parse.c
*/
void					get_map(char *file, t_env *env);
void					set_map(t_env *env, char **tab_file);
int						*dup_nb(t_env *env, char *line);
int						check_nb(char **s);
int						count_nb(char *s);

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

/*
** Functions of str_tools.c
*/
t_point					search_player(char *map, t_env *env);
int						tab_len(char **tab);
int						is_wolfmap(char *c);
char					*read_file(int fd);
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
void					make_it_uni(t_env *env, unsigned int color);
void					make_it_b(t_env *env);
void					pixel_b(unsigned int color, int x, int y, t_env *env);
#endif
