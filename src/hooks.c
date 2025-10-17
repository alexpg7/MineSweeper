#include "minesweeper.h"

int	mouse_hook(int code, int x, int y, t_vars *vars)
{
	int	pi;
	int	pj;

	pi = x / RES;
	pj = y / RES;
	if (code == 1)
	{
		if (vars->mat[pi][pj] != 'F')
			vars->mat[pi][pj] = ' ';
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