#include "../lib/Libft/libft.h"
#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <signal.h>

#define RES 50 //resolution of a cell
#define PIX 14

//COLORS
#define GREY 0x898989
#define GREY2 0x747474
#define WHITE 0xBDBDBD

typedef struct s_sprite
{
	char	**cell;
}	t_sprite;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		res;
	int		grid;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	**mat; //indicates the hidden cells
	char	**mat2; //indicates the mines and numbers
	int		n;
	t_sprite	*sprites;
}	t_vars;

int		ft_exit(t_vars *vars, int ex);
void	ft_init(t_vars *vars);
void	ft_beginwin(t_vars *vars);
void	ft_initsprites(t_vars *vars);
void	ft_paintboard(t_vars *vars);