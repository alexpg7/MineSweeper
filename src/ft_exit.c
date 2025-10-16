#include "minesweeper.h"

void	ft_freechararr(char **str)
{
	if (!str)
		return ;
	for (int i = 0; i < PIX; i++)
		free(str[i]);
	free(str);
}

void	ft_freesprites(t_sprite *sprites)
{
	ft_freechararr(sprites->cell);
}

int	ft_exit(t_vars *vars, int ex)
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
	ft_freesprites(vars->sprites);
	free(vars->sprites);
	if (vars->mlx)
	{
		if (vars->img)
			mlx_destroy_image(vars->mlx, vars->img);
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(ex);
}