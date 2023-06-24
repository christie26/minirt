/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:49:42 by minkim3           #+#    #+#             */
/*   Updated: 2023/06/24 21:54:56 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_ambient	get_ambient(char **tab)
{
	t_ambient	ambient;

	ambient.ratio = get_double(tab[1]);
	ambient.color = get_color(tab[2]);
	return (ambient);
}
