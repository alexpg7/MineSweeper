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

int	ft_countmines(char **mat, int i, int j, int g)
{
	int	count;

	count = 0;
	for	(int i1 = -1; i1 < 2; i1++)
	{
		for	(int j1 = -1; j1 < 2; j1++)
		{
			if (i1 == j1 && i1 == 0)
				continue ;
			if (i + i1 >= 0 && j + j1 >= 0 && i + i1 < g && j + j1 < g)
			{
				if (mat[i + i1][j + j1] == 'M')
					count++;
			}
		}
	}
	return (count);
}

void	ft_putnumbers(t_vars *vars)
{
	int	g;
	int	n;

	g = vars->grid;
	for (int i = 0; i < g; i++)
	{
		for (int j = 0; j < g; j++)
		{
			n = 0;
			if (vars->mat2[i][j] == ' ')
				n = ft_countmines(vars->mat2, i, j, g);
			if (n != 0)
				vars->mat2[i][j] = n + '0';
		}
	}
}

void	ft_putmines(t_vars *vars)
{
	int	g;
	int	j;
	int	r;
	int	nmines;

	srand(time(NULL));
	g = vars->grid;
	nmines = 40 - (16 - g) * 30 / 7;
	for (int k = 0; k < nmines; k++)
	{
		r = rand() % (g * g);
		for (int i = 0; i < g; i++)
		{
			for (j = 0; j < g; j++)
			{
				if (r == i * g + j)
					vars->mat2[i][j] = 'M';
				else
				{
					if (vars->mat2[i][j] != 'M')
						vars->mat2[i][j] = ' ';
				}
			}
			vars->mat2[i][j] = '\0';
		}
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
	ft_putmines(vars);
	ft_putnumbers(vars);
	//ft_printmat(vars->mat2, vars->grid);
}