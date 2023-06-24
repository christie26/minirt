/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:51:05 by minkim3           #+#    #+#             */
/*   Updated: 2023/06/24 21:51:06 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_light	get_light(char **tab)
{
	t_light	light;

	light.cordinate = get_coordinate(tab[1]);
	light.brightness = get_double(tab[2]);
	light.color = get_color(tab[3]);
	return (light);
}