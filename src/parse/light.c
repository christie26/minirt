/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:49:29 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:49:29 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_light	*get_light(char **tab)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (light == NULL)
		exit(EXIT_FAILURE);
	if (!tab[1] || !tab[2] || !tab[3])
		error_msg(LACK_ELEMENT);
	light->coordinate = get_coordinate(tab[1]);
	light->brightness = get_double(tab[2]);
	if (light->brightness < 0 || light->brightness > 1)
		error_msg(PARSE_LIGHT);
	light->color = get_color(tab[3]);
	if (tab[4])
		error_msg(PARSE_LIGHT);
	return (light);
}
