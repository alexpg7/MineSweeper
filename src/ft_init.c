#include "minesweeper.h"

void	ft_printmat(char **mat, int dim)
{
	for (int i = 0; i < dim; i++)
		ft_printf("%s\n", mat[i]);
}

void	ft_putgrid(t_vars *vars)
{
	int	g;
	int	j;

	g = vars->grid;
	for (int i = 0; i < g; i++)
	{
		for (j = 0; j < g; j++)
			vars->mat[i][j] = 'X';
		vars->mat[i][j] = '\0';
	}
}

void	ft_init(t_vars *vars)
{
	int	g;
	int	i;

	g = vars->grid;
	vars->mat = (char **)malloc(sizeof(char *) * (g + 1));
	vars->mat2 = (char **)malloc(sizeof(char *) * (g + 1));
	if (!vars->mat || !vars->mat2)
		ft_exit(1, vars);
	for (i = 0; i <= g; i++)
	{
		vars->mat[i] = NULL;
		vars->mat2[i] = NULL;
	}
	for (i = 0; i <= g; i++)
	{
		vars->mat[i] = (char *)malloc(sizeof(char) * (g + 1));
		vars->mat2[i] = (char *)malloc(sizeof(char) * (g + 1));
		if (!(vars->mat[i]) || !(vars->mat2[i]))
			ft_exit(1, vars);
	}
	ft_putgrid(vars);
	ft_printmat(vars->mat, vars->grid);
}