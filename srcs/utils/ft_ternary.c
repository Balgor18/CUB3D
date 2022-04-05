/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 04:38:16 by fcatinau          #+#    #+#             */
/*   Updated: 2022/04/05 04:38:26 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief Function for a ternaire
 *
 * @param cond for the conditions
 * @param valid_1 if cond is true return valid_1
 * @param valid_2 if cond is false return valid_2
 *
 * @return void* the value of valid_1 or valid_2
 */
void	*ft_ternary(int const cond, void *valid_1, void *valid_2)
{
	if (cond)
		return (valid_1);
	return (valid_2);
}
