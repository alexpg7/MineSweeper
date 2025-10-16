#include "minesweeper.h"

int	ft_readget(int *num)
{
	char	*prompt;

	prompt = get_next_line(0);
	if (!prompt)
		return (-1);
	*num = ft_atoi(prompt);
	if (ft_strlen(prompt) == 1)
		*num = 9;
	free(prompt);
	return (*num);
}

int	ft_checkgrid(char *str)
{
	int		num;

	if (!str)
	{
		while (1)
		{
			if (ft_readget(&num) == -1)
				return (-1);
			if (num > 16 || num < 9)
				ft_printf("Please, choose a valid number (9-16):\n");
			else
				break ;
		}
		get_next_line(-1);
	}
	else
	{
		num = ft_atoi(str);
		while (num > 16 || num < 9)
		{
			ft_printf("Please, choose a valid number (9-16):\n");
			if (ft_readget(&num) == -1)
				return (-1);
			if (num < 0)
				return (-1);
			if (!(num > 16 || num < 9))
				break ;
		}
		get_next_line(-1);
	}
	return (num);
}

int	main(int narg, char **argv)
{
	t_vars	vars;
	int		g;

	if (narg == 1)
	{
		ft_printf("Introduce a number (9-16) to choose grid size. Press enter to continue with default size (9x9):\n");
		g = ft_checkgrid(NULL);
		if (g < -1)
			return (1);
		vars.grid = g;
	}
	else if (narg >= 2)
	{
		g = ft_checkgrid(argv[1]);
		if (g < -1)
			return (1);
		vars.grid = g;
	}
	else
		return (1);
	ft_init(&vars);
	vars.sprites = (t_sprite *)malloc(sizeof(t_sprite));
	ft_initsprites(&vars);
	vars.res = RES * g;
	ft_beginwin(&vars);
}