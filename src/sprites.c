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

void	ft_fill1(t_vars *vars)
{
	t_sprite	*sprite = vars->sprites;

	ft_malloc(&(sprite->num1), vars);
	ft_copystr("gggggggggggggg", sprite->num1, 0);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num1, 1);
	ft_copystr("gGGGGGGBGGGGGg", sprite->num1, 2);
	ft_copystr("gGGGGGBBGGGGGg", sprite->num1, 3);
	ft_copystr("gGGGGBBBGGGGGg", sprite->num1, 4);
	ft_copystr("gGGGBBBBGGGGGg", sprite->num1, 5);
	ft_copystr("gGGGGGBBGGGGGg", sprite->num1, 6);
	ft_copystr("gGGGGGBBGGGGGg", sprite->num1, 7);
	ft_copystr("gGGGGGBBGGGGGg", sprite->num1, 8);
	ft_copystr("gGGGGGBBGGGGGg", sprite->num1, 9);
	ft_copystr("gGGGGGBBGGGGGg", sprite->num1, 10);
	ft_copystr("gGGGBBBBBBGGGg", sprite->num1, 11);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num1, 12);
	ft_copystr("gggggggggggggg", sprite->num1, 13);
}


void	ft_fill2(t_vars *vars)
{
	t_sprite	*sprite = vars->sprites;

	ft_malloc(&(sprite->num2), vars);
	ft_copystr("gggggggggggggg", sprite->num2, 0);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num2, 1);
	ft_copystr("gGGGGCCCCGGGGg", sprite->num2, 2);
	ft_copystr("gGGGCCCCCCGGGg", sprite->num2, 3);
	ft_copystr("gGGGCCGGCCGGGg", sprite->num2, 4);
	ft_copystr("gGGGCGGGCCGGGg", sprite->num2, 5);
	ft_copystr("gGGGGGGCCCGGGg", sprite->num2, 6);
	ft_copystr("gGGGGGCCCGGGGg", sprite->num2, 7);
	ft_copystr("gGGGGCCCGGGGGg", sprite->num2, 8);
	ft_copystr("gGGGCCCGGGGGGg", sprite->num2, 9);
	ft_copystr("gGGGCCGGGGGGGg", sprite->num2, 10);
	ft_copystr("gGGGCCCCCCGGGg", sprite->num2, 11);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num2, 12);
	ft_copystr("gggggggggggggg", sprite->num2, 13);
}

void	ft_fill3(t_vars *vars)
{
	t_sprite	*sprite = vars->sprites;

	ft_malloc(&(sprite->num3), vars);
	ft_copystr("gggggggggggggg", sprite->num3, 0);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num3, 1);
	ft_copystr("gGGGGHHHHGGGGg", sprite->num3, 2);
	ft_copystr("gGGGHHGGHHGGGg", sprite->num3, 3);
	ft_copystr("gGGGHGGGGHGGGg", sprite->num3, 4);
	ft_copystr("gGGGGGGGHHGGGg", sprite->num3, 5);
	ft_copystr("gGGGGGHHHGGGGg", sprite->num3, 6);
	ft_copystr("gGGGGGGGHHGGGg", sprite->num3, 7);
	ft_copystr("gGGGGGGGGHGGGg", sprite->num3, 8);
	ft_copystr("gGGGHGGGGHGGGg", sprite->num3, 9);
	ft_copystr("gGGGHHGGHHGGGg", sprite->num3, 10);
	ft_copystr("gGGGGHHHHGGGGg", sprite->num3, 11);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num3, 12);
	ft_copystr("gggggggggggggg", sprite->num3, 13);
}

void	ft_fill4(t_vars *vars)
{
	t_sprite	*sprite = vars->sprites;

	ft_malloc(&(sprite->num4), vars);
	ft_copystr("gggggggggggggg", sprite->num4, 0);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num4, 1);
	ft_copystr("gGGGGGGGYYGGGg", sprite->num4, 2);
	ft_copystr("gGGGGGGYYYGGGg", sprite->num4, 3);
	ft_copystr("gGGGGGYYYYGGGg", sprite->num4, 4);
	ft_copystr("gGGGGYYGYYGGGg", sprite->num4, 5);
	ft_copystr("gGGGYYGGYYGGGg", sprite->num4, 6);
	ft_copystr("gGGYYGGGYYGGGg", sprite->num4, 7);
	ft_copystr("gGGYYYYYYYYGGg", sprite->num4, 8);
	ft_copystr("gGGGGGGGYYGGGg", sprite->num4, 9);
	ft_copystr("gGGGGGGGYYGGGg", sprite->num4, 10);
	ft_copystr("gGGGGGGGYYGGGg", sprite->num4, 11);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num4, 12);
	ft_copystr("gggggggggggggg", sprite->num4, 13);
}

void	ft_fill5(t_vars *vars)
{
	t_sprite	*sprite = vars->sprites;

	ft_malloc(&(sprite->num5), vars);
	ft_copystr("gggggggggggggg", sprite->num5, 0);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num5, 1);
	ft_copystr("gGGGOOOOOOGGGg", sprite->num5, 2);
	ft_copystr("gGGGOOOOOOGGGg", sprite->num5, 3);
	ft_copystr("gGGGOGGGGGGGGg", sprite->num5, 4);
	ft_copystr("gGGGOGGGGGGGGg", sprite->num5, 5);
	ft_copystr("gGGGOOOOOGGGGg", sprite->num5, 6);
	ft_copystr("gGGGGGGGOOGGGg", sprite->num5, 7);
	ft_copystr("gGGGGGGGGOGGGg", sprite->num5, 8);
	ft_copystr("gGGGOGGGGOGGGg", sprite->num5, 9);
	ft_copystr("gGGGOOGGOOGGGg", sprite->num5, 10);
	ft_copystr("gGGGGOOOOGGGGg", sprite->num5, 11);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num5, 12);
	ft_copystr("gggggggggggggg", sprite->num5, 13);
}

void	ft_fill6(t_vars *vars)
{
	t_sprite	*sprite = vars->sprites;

	ft_malloc(&(sprite->num6), vars);
	ft_copystr("gggggggggggggg", sprite->num6, 0);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num6, 1);
	ft_copystr("gGGGGRRRRGGGGg", sprite->num6, 2);
	ft_copystr("gGGGRRGGRRGGGg", sprite->num6, 3);
	ft_copystr("gGGGRGGGGRGGGg", sprite->num6, 4);
	ft_copystr("gGGGRGGGGGGGGg", sprite->num6, 5);
	ft_copystr("gGGGRRRRRGGGGg", sprite->num6, 6);
	ft_copystr("gGGGRRGGRRGGGg", sprite->num6, 7);
	ft_copystr("gGGGRGGGGRGGGg", sprite->num6, 8);
	ft_copystr("gGGGRGGGGRGGGg", sprite->num6, 9);
	ft_copystr("gGGGRRGGRRGGGg", sprite->num6, 10);
	ft_copystr("gGGGGRRRRGGGGg", sprite->num6, 11);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num6, 12);
	ft_copystr("gggggggggggggg", sprite->num6, 13);
}

void	ft_fill7(t_vars *vars)
{
	t_sprite	*sprite = vars->sprites;

	ft_malloc(&(sprite->num7), vars);
	ft_copystr("gggggggggggggg", sprite->num7, 0);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num7, 1);
	ft_copystr("gGGGMMMMMMGGGg", sprite->num7, 2);
	ft_copystr("gGGGMMMMMMGGGg", sprite->num7, 3);
	ft_copystr("gGGGGGGGGMGGGg", sprite->num7, 4);
	ft_copystr("gGGGGGGGMMGGGg", sprite->num7, 5);
	ft_copystr("gGGGGGGGMGGGGg", sprite->num7, 6);
	ft_copystr("gGGGGGGMMGGGGg", sprite->num7, 7);
	ft_copystr("gGGGGGGMGGGGGg", sprite->num7, 8);
	ft_copystr("gGGGGGMMGGGGGg", sprite->num7, 9);
	ft_copystr("gGGGGGMGGGGGGg", sprite->num7, 10);
	ft_copystr("gGGGGGMGGGGGGg", sprite->num7, 11);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num7, 12);
	ft_copystr("gggggggggggggg", sprite->num7, 13);
}

void	ft_fill8(t_vars *vars)
{
	t_sprite	*sprite = vars->sprites;

	ft_malloc(&(sprite->num8), vars);
	ft_copystr("gggggggggggggg", sprite->num8, 0);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num8, 1);
	ft_copystr("gGGGGPPPPGGGGg", sprite->num8, 2);
	ft_copystr("gGGGPPGGPPGGGg", sprite->num8, 3);
	ft_copystr("gGGGPGGGGPGGGg", sprite->num8, 4);
	ft_copystr("gGGGPPGGPPGGGg", sprite->num8, 5);
	ft_copystr("gGGGGPPPPGGGGg", sprite->num8, 6);
	ft_copystr("gGGGPPGGPPGGGg", sprite->num8, 7);
	ft_copystr("gGGGPGGGGPGGGg", sprite->num8, 8);
	ft_copystr("gGGGPGGGGPGGGg", sprite->num8, 9);
	ft_copystr("gGGGPPGGPPGGGg", sprite->num8, 10);
	ft_copystr("gGGGGPPPPGGGGg", sprite->num8, 11);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num8, 12);
	ft_copystr("gggggggggggggg", sprite->num8, 13);
}

void	ft_fill9(t_vars *vars)
{
	t_sprite	*sprite = vars->sprites;

	ft_malloc(&(sprite->num9), vars);
	ft_copystr("gggggggggggggg", sprite->num9, 0);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num9, 1);
	ft_copystr("gGGGGVVVVGGGGg", sprite->num9, 2);
	ft_copystr("gGGGVVGGVVGGGg", sprite->num9, 3);
	ft_copystr("gGGGVGGGGVGGGg", sprite->num9, 4);
	ft_copystr("gGGGVGGGGVGGGg", sprite->num9, 5);
	ft_copystr("gGGGVVGGVVGGGg", sprite->num9, 6);
	ft_copystr("gGGGGVVVVVGGGg", sprite->num9, 7);
	ft_copystr("gGGGGGGGGVGGGg", sprite->num9, 8);
	ft_copystr("gGGGVGGGGVGGGg", sprite->num9, 9);
	ft_copystr("gGGGVVGGVVGGGg", sprite->num9, 10);
	ft_copystr("gGGGGVVVVGGGGg", sprite->num9, 11);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num9, 12);
	ft_copystr("gggggggggggggg", sprite->num9, 13);
}

void	ft_fillmine(t_vars *vars)
{
	t_sprite	*sprite = vars->sprites;

	ft_malloc(&(sprite->mine), vars);
	ft_copystr("gggggggggggggg", sprite->mine, 0);
	ft_copystr("gGGGGGGGGGGGGg", sprite->mine, 1);
	ft_copystr("gGGGGGLLGGGGGg", sprite->mine, 2);
	ft_copystr("gGGLGLLLLGLGGg", sprite->mine, 3);
	ft_copystr("gGGGLLWWLLGGGg", sprite->mine, 4);
	ft_copystr("gGGLLLLWWLLGGg", sprite->mine, 5);
	ft_copystr("gGLLLLLLWWLLGg", sprite->mine, 6);
	ft_copystr("gGLLLLLLLWLLGg", sprite->mine, 7);
	ft_copystr("gGGLLLLLLLLGGg", sprite->mine, 8);
	ft_copystr("gGGGLLLLLLGGGg", sprite->mine, 9);
	ft_copystr("gGGLGLLLLGLGGg", sprite->mine, 10);
	ft_copystr("gGGGGGLLGGGGGg", sprite->mine, 11);
	ft_copystr("gGGGGGGGGGGGGg", sprite->mine, 12);
	ft_copystr("gggggggggggggg", sprite->mine, 13);
}

void	ft_fill0(t_vars *vars)
{
	t_sprite	*sprite = vars->sprites;

	ft_malloc(&(sprite->num0), vars);
	ft_copystr("gggggggggggggg", sprite->num0, 0);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num0, 1);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num0, 2);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num0, 3);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num0, 4);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num0, 5);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num0, 6);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num0, 7);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num0, 8);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num0, 9);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num0, 10);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num0, 11);
	ft_copystr("gGGGGGGGGGGGGg", sprite->num0, 12);
	ft_copystr("gggggggggggggg", sprite->num0, 13);
}

void	ft_fillflag(t_vars *vars)
{
	t_sprite	*sprite = vars->sprites;

	ft_malloc(&(sprite->flag), vars);
	ft_copystr("GGGGGGGGGGGGGG", sprite->flag, 0);
	ft_copystr("GGGGGGGGGGGGGg", sprite->flag, 1);
	ft_copystr("GGWWWWWWWWWWgg", sprite->flag, 2);
	ft_copystr("GGWWWWRRWWWWgg", sprite->flag, 3);
	ft_copystr("GGWWWWRRRWWWgg", sprite->flag, 4);
	ft_copystr("GGWWWWRRRRWWgg", sprite->flag, 5);
	ft_copystr("GGWWWWRRRWWWgg", sprite->flag, 6);
	ft_copystr("GGWWWWRRWWWWgg", sprite->flag, 7);
	ft_copystr("GGWWWWLWWWWWgg", sprite->flag, 8);
	ft_copystr("GGWWWLLLWWWWgg", sprite->flag, 9);
	ft_copystr("GGWWLLLLLWWWgg", sprite->flag, 10);
	ft_copystr("GGWWWWWWWWWWgg", sprite->flag, 11);
	ft_copystr("Gggggggggggggg", sprite->flag, 12);
	ft_copystr("gggggggggggggg", sprite->flag, 13);
}

void	ft_initsprites(t_vars *vars)
{
	ft_fillcell(vars);
	ft_fill0(vars);
	ft_fill1(vars);
	ft_fill2(vars);
	ft_fill3(vars);
	ft_fill4(vars);
	ft_fill5(vars);
	ft_fill6(vars);
	ft_fill8(vars);
	ft_fill9(vars);
	ft_fillmine(vars);
	ft_fillflag(vars);
}