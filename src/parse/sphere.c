/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spere.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:51:20 by minkim3           #+#    #+#             */
/*   Updated: 2023/06/24 21:51:21 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_sphere	get_sphere(char **tab)
{
	t_sphere	sphere;

	sphere.cordinate = get_coordinate(tab[1]);
	sphere.diameter = get_double(tab[2]);
	sphere.color = get_color(tab[3]);
	return (sphere);
}
