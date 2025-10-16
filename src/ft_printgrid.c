#include "minesweeper.h"

void	pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + y * vars->line_length + x * vars->bits_per_pixel / 8;
	*(unsigned int *)dst = color;
}

void	ft_paintcell(int x, int y, t_vars *vars)
{
	int	pixX = x % RES; //coordinates in sprite
	int	pixY = y % RES;
	char	col;
	int		color;

	pixX = pixX * PIX / RES; //pixels in sprite
	pixY = pixY * PIX / RES;
	col = vars->sprites->cell[pixX][pixY];
	if (col == 'G')
		color = GREY;
	else if (col == 'g')
		color = GREY2;
	else
		color = WHITE;
	pixel_put(vars, x, y, color);
}

void	ft_paintboard(t_vars *vars)
{
	int	i = 0;
	int	j = 0;
	int	pi;
	int	pj;
	int	res = vars->res;
	int	g = vars->grid;

	while (i < res)
	{
		j = 0;
		while (j < res)
		{
			pi = i * g / res; //coordinates in board
			pj = j * g / res;
			if (vars->mat[pi][pj] == 'X')
				ft_paintcell(i, j, vars);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}