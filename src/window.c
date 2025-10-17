#include "minesweeper.h"

void	ft_beginwin(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!(vars->mlx))
	{
		perror("mlx init");
		ft_exit(vars, 1);
	}
	vars->win = mlx_new_window(vars->mlx, vars->res, vars->res, "MineSweeper");
	vars->img = mlx_new_image(vars->mlx, vars->res, vars->res);
	if (!(vars->win) || !(vars->img))
	{
		perror("mlx error");
		ft_exit(vars, 1);
	}
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	if (!(vars->addr) || !(vars->bits_per_pixel) || !(vars->line_length))
	{
		perror("mlx address get");
		ft_exit(vars, 1);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_hook(vars->win, 17, 0L, ft_exit, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	ft_paintboard(vars);
	mlx_loop(vars->mlx);
}