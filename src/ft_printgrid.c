#include "minesweeper.h"

void	pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + y * vars->line_length + x * vars->bits_per_pixel / 8;
	*(unsigned int *)dst = color;
}

unsigned int	ft_colorconversion(char c, int mode)
{
	if (mode == 1) //explode
	{
		if (c == 'G')
			return (RED);
	}
	if (c == 'G')
		return (GREY);
	else if (c == 'g')
		return (GREY2);
	else if (c == 'B')
		return (BLUE);
	else if (c == 'C')
		return (CYAN);
	else if (c == 'H')
		return (GREEN);
	else if (c == 'Y')
		return (YELL);
	else if (c == 'O')
		return (ORAN);
	else if (c == 'R')
		return (RED);
	else if (c == 'M')
		return (MAG);
	else if (c == 'P')
		return (PURP);
	else if (c == 'V')
		return (VIOL);
	else if (c == 'L')
		return (BLACK);
	else
		return (WHITE);
}

void	ft_paintcell(int x, int y, char **sprit, t_vars *vars, int mode)
{
	int	pixX = x % RES; //coordinates in sprite
	int	pixY = y % RES;
	int		color;

	pixX = pixX * PIX / RES; //pixels in sprite
	pixY = pixY * PIX / RES;
	color = ft_colorconversion(sprit[pixY][pixX], mode);
	pixel_put(vars, x, y, color);
}

void	ft_paintsprite(int x, int y, t_vars *vars, char c, int pi, int pj)
{
	int	mode = 0;

	if (c == ' ')
		ft_paintcell(x, y, vars->sprites->num0, vars, mode);
	else if (c == '1')
		ft_paintcell(x, y, vars->sprites->num1, vars, mode);
	else if (c == '2')
		ft_paintcell(x, y, vars->sprites->num2, vars, mode);
	else if (c == '3')
		ft_paintcell(x, y, vars->sprites->num3, vars, mode);
	else if (c == '4')
		ft_paintcell(x, y, vars->sprites->num4, vars, mode);
	else if (c == '5')
		ft_paintcell(x, y, vars->sprites->num5, vars, mode);
	else if (c == '6')
		ft_paintcell(x, y, vars->sprites->num6, vars, mode);
	else if (c == '7')
		ft_paintcell(x, y, vars->sprites->num7, vars, mode);
	else if (c == '8')
		ft_paintcell(x, y, vars->sprites->num8, vars, mode);
	else if (c == '9')
		ft_paintcell(x, y, vars->sprites->num9, vars, mode);
	else if (c == 'M')
	{
		if (vars->cx == pi && vars->cy == pj)
			mode = 1;
		ft_paintcell(x, y, vars->sprites->mine, vars, mode);
	}
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
				ft_paintcell(i, j, vars->sprites->cell, vars, 0);
			else if (vars->mat[pi][pj] == 'F')
				ft_paintcell(i, j, vars->sprites->flag, vars, 0);
			else
				ft_paintsprite(i, j, vars, vars->mat2[pi][pj], pi, pj);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}