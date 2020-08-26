/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:50:31 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/03/12 11:50:32 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LEM_IN_H
# define __LEM_IN_H
# include "./libft/ft_printf.h"
# include "./libft/get_next_line.h"
# include "./libft/libft.h"
# include <limits.h>
# define VALID "qrps"

typedef struct s_room	t_room;
typedef struct s_rooms	t_rooms;
typedef struct s_path	t_path;
typedef struct s_hlp	t_hlp;
typedef struct s_wr		t_wr;
typedef struct s_opt	t_opt;

struct					s_room
{
	char				*name;
	int					x;
	int					y;
	char				type;
	char				vis;
	char				blocked;
	t_rooms				*links;
	t_room				*par;
	int					aant;
};

struct					s_opt
{
	int					q;
	int					r;
	int					p;
	int					s;
};

struct					s_rooms
{
	t_room				**rooms;
	int					i;
	int					length;
};

struct					s_hlp
{
	char				**str;
	int					i;
	int					length;
};

struct					s_path
{
	t_rooms				**path;
	int					i;
	int					length;
};

struct					s_wr
{
	void				**ptr;
	int					i;
	int					length;
};

int						g_t;
int						g_sum;
int						g_req_stat;
int						g_my_stat;
ssize_t					g_ants;
t_room					*g_start;
t_room					*g_end;
t_rooms					*g_rms;
t_rooms					*g_q;
t_path					*g_path;
t_hlp					*g_fil;
t_opt					g_opt;

void					writ_links(char *line);
void					ft_writ(char *line);
void					free_str(char **str);
int						count_spl(char **str);
t_room					*find_room(t_rooms *r, char	*name);
void					free_str(char **str);
int						count_spl(char **str);
int						check_coords(t_room *room);
void					free_vis(void);
int						keksus(void);
int						expr(int j);
int						check_ants(t_rooms *p, int a);
void					add_ant(t_room *p);
void					reverse_path(void);
void					moove(t_rooms *p);
void					move_ants(void);
void					alloc_p(void);
void					errorchik(char *str, int a);
void					print_file(void);
void					errorchik(char *str, int a);
void					valid(char *line);
void					valid2(int n_str, char *line);
void					*alloc_arr(int count, int l);
void					array_writ(void *ary, void *ptr);
void					bfs(void);
void					show_rooms(void);
void					show_path(void);
void					show_stat(void);
void					show(void);
void					error_invalid(char str);
void					parse_flags(char *str);
void					parse_opt(int ac, char **av);

#endif
