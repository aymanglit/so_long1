/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:41:34 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/05 22:30:04 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	if (!str)
		exit(1);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	check_file_extension(char *path)
{
	char	*wanted_exten;
	int		file_extention;

	file_extention = ft_strlen(path) - 4;
	wanted_exten = ".ber";
	if (ft_strncmp(&path[file_extention], wanted_exten, 5) == 0)
	{
		return (1);
	}
	return (0);
}

int	check_file_exist(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit (1);
	close(fd);
	return (1);
}

void	print_errors(int i)
{
	if (i == 1)
		ft_putstr("\033[0;31m the map is not surrounded by walls.\n");
	else if (i == 2)
		ft_putstr("\033[0;31m the map isn't the same length.\n");
	else if (i == 3)
		ft_putstr("\033[0;31m the file must end with .ber\n");
	else if (i == 4)
		ft_putstr("\033[0;31m there's no player in the map or more than one\n");
	else if (i == 5)
		ft_putstr("\033[0;31m no token in the map, no reason to play\n");
	else if (i == 6)
		ft_putstr("\033[0;31m the map must contain only one exit\n");
	else if (i == 7)
		ft_putstr("\033[0;33m the player | the exit is surrounded by walls\n");
	else if (i == 8)
		ft_putstr("\033[0;33m can't collect tokens\n");
	else if (i == 9)
		ft_putstr("\033[0;33m please check elemnts\n");
	else if (i == 10)
		ft_putstr("\033[0;33m the file is empty!\n");
	exit(1);
}

int	check_file(char *path)
{
	if (check_file_extension(path) == 0)
	{
		print_errors (3);
	}
	if (!check_file_exist(path))
		print_errors (10);
	return (1);
}
