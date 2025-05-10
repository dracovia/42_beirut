/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:18:09 by mfassad           #+#    #+#             */
/*   Updated: 2025/04/30 16:07:02 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define     TRUE    1
# define     FALSE   0

# define     EVEN(nbr)  (nbr % 2) == 0
# define     SUCCESS 0
# define     EVEN_MSG "I have an even number of arguments."
# define     ODD_MSG "I have an odd number of arguments."

typedef int	t_bool;

#endif