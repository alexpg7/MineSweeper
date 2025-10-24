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
#define BLACK 0x2C2C2C

//COLOR NUMBERS
#define BLUE 0x1C73FF
#define CYAN 0x16FFE0
#define GREEN 0x45D900
#define YELL 0xFFDD00
#define ORAN 0xFF7B00
#define RED 0xFF2A00
#define MAG 0xFF1783
#define PURP 0xB12BFF
#define VIOL 0x4D3DFF

typedef struct s_sprite
{
	char	**cell;
	char	**num0;
	char	**num1;
	char	**num2;
	char	**num3;
	char	**num4;
	char	**num5;
	char	**num6;
	char	**num7;
	char	**num8;
	char	**num9;
	char	**mine;
	char	**flag;
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
	int		cx; //cell where we clicked
	int		cy;
	int		end;
	int		count;
	int		nmines;
	int		flag;
	t_sprite	*sprites;
}	t_vars;

int		ft_exit(t_vars *vars, int ex);
void	ft_init(t_vars *vars);
void	ft_beginwin(t_vars *vars);
void	ft_initsprites(t_vars *vars);
void	ft_initboard(t_vars *vars);
void	ft_paintboard(t_vars *vars);
void	ft_putmines(int a, int b, t_vars *vars);
void	ft_putnumbers(t_vars *vars);
int		key_hook(int keycode, t_vars * vars);
int		mouse_hook(int code, int x, int y, t_vars *vars);