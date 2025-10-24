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
	vars->count = 0;
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

int	ft_around(int r, int a, int b, int grid)
{
	int	i = r / grid;
	int	j = r % grid;
	int	dist1 = (i > a) * (i - a) + (i <= a) * (a - i);
	int	dist2 = (j > b) * (j - b) + (j <= b) * (b - j);

	if (dist1 > 1 || dist2 > 1)
		return (1);
	return (0);
}

void	ft_putmines(int a, int b, t_vars *vars)
{
	int	g;
	int	j;
	int	r;
	int	nmines;

	srand(time(NULL));
	g = vars->grid;
	nmines = 40 - (16 - g) * 30 / 7;
	vars->nmines = nmines;
	for (int i = 0; i < g; i++)
	{
		for (j = 0; j < g; j++)
			vars->mat2[i][j] = 'O';
		vars->mat2[i][j] = '\0';
	}
	for (int k = 0; k < nmines;)
	{
		while (1)
		{
			r = rand() % (g * g);
			if (ft_around(r, a, b, g))
				break ;
		}
		for (int i = 0; i < g; i++)
		{
			for (j = 0; j < g; j++)
			{
				if (r == i * g + j)
				{
					vars->mat2[i][j] = 'M';
					k++;
				}
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

void	ft_printinstructions(void)
{
	ft_printf("INSTRUCTIONS:\n\tLeft click: unhide cell\n");
	ft_printf("\tRight click: put flag\n\t\"R\": restart game\n");
}

void	ft_initboard(t_vars *vars)
{
	vars->flag = 0;
	ft_putgrid(vars);
}

void	ft_init(t_vars *vars)
{
	int	g;
	int	i;

	g = vars->grid;
	vars->end = 0;
	vars->mat = (char **)malloc(sizeof(char *) * (g + 1));
	vars->mat2 = (char **)malloc(sizeof(char *) * (g + 1));
	if (!vars->mat || !vars->mat2)
		ft_exit(vars, 1);
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
			ft_exit(vars, 1);
	}
	ft_printinstructions();
	ft_initboard(vars);
	//ft_printmat(vars->mat2, vars->grid);
}