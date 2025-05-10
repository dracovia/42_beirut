/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:39:21 by mfassad           #+#    #+#             */
/*   Updated: 2025/04/28 18:57:55 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		is_base(char *base);
int		num_len(int num, char *to_base);
int		ft_atoi_base(char *nbr, char *base);

char	*tocharposi(int len, long n, char *num, char *base)
{
	int		i;
	long	len_base;

	i = len - 1;
	len_base = ft_strlen(base);
	while (n > 0)
	{
		num[i--] = base[n % len_base];
		n /= len_base;
	}
	return (num);
}

char	*ft_putbase(int nbr, char *base)
{
	long	n;
	char	*num;
	int		len;
	int		is_neg;

	if (!is_base(base))
		return (NULL);
	len = num_len(nbr, base);
	is_neg = nbr < 0;
	num = (char *) malloc(sizeof (char) * (len + 1));
	num[len] = '\0';
	n = (long)nbr;
	if (n == 0)
		num[0] = base[0];
	if (n < 0)
		n = n * (-1);
	num = tocharposi(len, n, num, base);
	if (is_neg)
		num[0] = '-';
	return (num);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	val;

	if (!is_base(base_from) || !is_base(base_to))
		return (NULL);
	val = (long)ft_atoi_base(nbr, base_from);
	if (!(val >= -2147483648 && val <= 2147483647))
		return (NULL);
	return (ft_putbase(val, base_to));
}
