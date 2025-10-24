#include "minesweeper.h"

void	ft_cleanzeros(t_vars *vars, int x, int y)
{
	int	g = vars->grid;

	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (i == j && i == 0)
				continue ;
			if (x + i >= 0 && y + j >= 0 && x + i < g && y + j < g)
			{
				if (vars->mat[x + i][y + j] == 'X')
				{
					vars->mat[x + i][y + j] = ' ';
					if (vars->mat2[x + i][y + j] == ' ')
						ft_cleanzeros(vars, x + i, y + j);
				}
			}
		}
	}
}

void	ft_showmines(t_vars *vars)
{
	int	g = vars->grid;

	for (int i = 0; i < g; i++)
	{
		for (int j = 0; j < g; j++)
		{
			if (vars->mat2[i][j] == 'M')
				vars->mat[i][j] = ' ';
		}
	}
	return ;
}

int	key_hook(int keycode, t_vars * vars)
{
	if (keycode == 114)//R
	{
		vars->end = 0;
		ft_initboard(vars);
		ft_paintboard(vars);
	}
	return (keycode);
}

void	ft_firstclick(int i, int j, t_vars *vars)
{
	ft_putmines(i, j, vars);
	ft_putnumbers(vars);
	vars->flag = 1;
}

int	mouse_hook(int code, int x, int y, t_vars *vars)
{
	int	pi;
	int	pj;

	pi = x / RES;
	pj = y / RES;
	vars->cx = pi;
	vars->cy = pj;
	if (vars->end == 1)
		return (0);
	if (code == 1)
	{
		if (vars->flag == 0)
			ft_firstclick(pi, pj, vars);
		if (vars->mat[pi][pj] == 'X')
		{
			vars->mat[pi][pj] = ' ';
			if (vars->mat2[pi][pj] == ' ')
				ft_cleanzeros(vars, pi, pj);
			else if (vars->mat2[pi][pj] == 'M')
			{
				ft_showmines(vars);
				ft_paintboard(vars);
				ft_printf("YOU LOSE!\npress \"R\" to restart.\n");
				vars->end = 1;
			}
			vars->count++;
			if (vars->count >= vars->grid * vars->grid - vars->nmines)
			{
				ft_printf("YOU WIN!\n");
				vars->end = 1;
			}
		}
	}
	else if (code == 3)
	{
		if (vars->mat[pi][pj] == 'F')
			vars->mat[pi][pj] = 'X';
		else if (vars->mat[pi][pj] == 'X')
			vars->mat[pi][pj] = 'F';
	}
	ft_paintboard(vars);
	return (vars->grid);
}