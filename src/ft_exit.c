#include "minesweeper.h"

void	ft_exit(int ex, t_vars *vars)
{
	int	g;

	g = vars->grid;
	if (vars->mat)
	{
		for (int i = 0; i <= g; i++)
			free(vars->mat[i]);
		free(vars->mat);
	}
	if (vars->mat2)
	{
		for (int i = 0; i <= g; i++)
			free(vars->mat2[i]);
		free(vars->mat2);
	}
	exit(ex);
}