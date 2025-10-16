#include "../lib/Libft/libft.h"
#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <signal.h>

#define RES 25 //resolution of a cell

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
}	t_vars;

void	ft_exit(int ex, t_vars *vars);
void	ft_init(t_vars *vars);