#include "so_long.h"

void	check_right(char *map_dfs, int x, int y, t_info *info)
{
	if (map_dfs[y * info->width + x + 1] != '1')
	{
		if (map_dfs[y * info->width + x + 1] == 'E')
		{	
			map_dfs[y * info->width + x + 1] = '1';
			dfs(map_dfs, x, y, info);
		}
		else
			dfs(map_dfs, x + 1, y, info);
	} 
}

void	check_left(char *map_dfs, int x, int y, t_info *info)
{
   if (map_dfs[y * info->width + x - 1] != '1')
	{
		if (map_dfs[y * info->width + x - 1] == 'E')
		{	
			map_dfs[y * info->width + x - 1] = '1';
			dfs(map_dfs, x, y, info);
		}
		else
			dfs(map_dfs, x - 1, y, info);
	} 
}

void	check_bottom(char *map_dfs, int x, int y, t_info *info)
{
   if (map_dfs[(y + 1) * info->width + x] != '1')
	{
		if (map_dfs[(y + 1) * info->width + x] == 'E')
		{	
			map_dfs[(y + 1) * info->width + x] = '1';
			dfs(map_dfs, x, y, info);
		}
		else
			dfs(map_dfs, x, y + 1, info);
	} 
}

void	check_top(char *map_dfs, int x, int y, t_info *info)
{
   if (map_dfs[(y - 1) * info->width + x] != '1')
	{
		if (map_dfs[(y - 1) * info->width + x] == 'E')
		{	
			map_dfs[(y - 1) * info->width + x] = '1';
			dfs(map_dfs, x, y, info);
		}
		else
			dfs(map_dfs, x, y - 1, info);
	} 
}

void	dfs(char *map_dfs, int x, int y, t_info *info)
{
	map_dfs[y * info->width + x] = '1';
	check_top(map_dfs, x, y, info);
	check_bottom(map_dfs, x, y, info);
	check_right(map_dfs, x, y, info);
	check_left(map_dfs, x, y, info);
}
