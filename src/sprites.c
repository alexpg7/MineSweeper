#include "minesweeper.h"

void	ft_copystr(char *str, char **dest, int i)
{
	for (int j = 0; j < PIX; j++)
	{
		dest[i][j] = str[j];
	}
	dest[i][PIX] = '\0';
}

void	ft_malloc(char ***cell, t_vars *vars)
{
	*cell = (char **)malloc(sizeof(char *) * PIX);
	if (!(*cell))
		ft_exit(vars, 1);
	for (int i = 0; i < PIX; i++)
	{
		(*cell)[i] = (char *)malloc(sizeof(char) * (PIX + 1));
	}
}

void	ft_fillcell(t_vars *vars)
{
	t_sprite	*sprite = vars->sprites;

	ft_malloc(&(sprite->cell), vars);
	ft_copystr("GGGGGGGGGGGGGG", sprite->cell, 0);
	ft_copystr("GGGGGGGGGGGGGg", sprite->cell, 1);
	ft_copystr("GGWWWWWWWWWWgg", sprite->cell, 2);
	ft_copystr("GGWWWWWWWWWWgg", sprite->cell, 3);
	ft_copystr("GGWWWWWWWWWWgg", sprite->cell, 4);
	ft_copystr("GGWWWWWWWWWWgg", sprite->cell, 5);
	ft_copystr("GGWWWWWWWWWWgg", sprite->cell, 6);
	ft_copystr("GGWWWWWWWWWWgg", sprite->cell, 7);
	ft_copystr("GGWWWWWWWWWWgg", sprite->cell, 8);
	ft_copystr("GGWWWWWWWWWWgg", sprite->cell, 9);
	ft_copystr("GGWWWWWWWWWWgg", sprite->cell, 10);
	ft_copystr("GGWWWWWWWWWWgg", sprite->cell, 11);
	ft_copystr("Gggggggggggggg", sprite->cell, 12);
	ft_copystr("gggggggggggggg", sprite->cell, 13);
}

void	ft_initsprites(t_vars *vars)
{
	ft_fillcell(vars);
}