/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:32:41 by mfassad           #+#    #+#             */
/*   Updated: 2025/04/26 17:52:51 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

typedef struct dict
{
	char	*key;
	char	*value;
}t_dict;

void	ft_putstring(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

int	skip_places(int fd, char *out_c)
{
	char	c;

	while (read(fd, &c, 1) > 0)
	{
		if ((c != ' ' || c != '\t'))
		{
			*out_c = c;
			return (1);
		}
	}
	return (0);
}

char	*read_word(int fd, int *len, int mode, char first_C)
{
	char	c;
	int		size;
	char	*str;

	str = (char *) malloc (1024);
	size = 0;
	str[size++] = c;
	while (read(fd, &c, 1) > 0)
	{
		if (mode == 0 && (!(c >= '0' && c <= '9')))
			break ;
		if (mode == 1 && (!(c >= 32 && c <= 126)))
			break ;
		str[size++] = c;
	}
	str[size] = '\0';
	*len = size;
	return (str);
}

int	read_line(int fd, t_dict *dict)
{
	char	c;
	int		len_val;
	int		len_key;

	if (!skip_places(fd, &c))
		return (0);
	if (c == '\n')
		return (1);
	dict -> key = read_word(fd, &len_key, 0, c);
	if (!skip_places(fd, &c) && c != ':')
		return (-1);
	if (!skip_places(fd, &c))
		return (-1);
	dict->value = read_word(fd, &len_val, 1, c);
	while (read(fd, &c, 1) > 0 && c != ':' )
		;
	return (1);
}

t_dict	*clean_dirc(char *path, int *out_size)
{
	t_dict	*dict;
	int		fd;
	int		i;
	int		ret;

	i = 0;
	fd = open(path, O_RDONLY);
	dict = (t_dict *) malloc(sizeof (t_dict) * 100);
	ret = read_line(fd, &dict[i]);
	while (ret > 0)
		i++;
	if (ret == -1)
	{
		ft_putstring("Dict Error\n");
		free(dict);
		return (NULL);
	}
	*out_size = i;
	close(fd);
	return (dict);
}
