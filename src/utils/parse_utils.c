/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:50:57 by minkim3           #+#    #+#             */
/*   Updated: 2023/06/24 20:50:58 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minirt.h"

double	string_to_double(char *str)
{
    double	result = 0.0;
    double	fraction = 0.1;
    int		sign = 1;
    int		decimalFound = 0;

    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str != '\0') {
        if (*str == '.') {
            decimalFound = 1;
            str++;
            continue;
        }

        if (*str < '0' || *str > '9') {
            printf("Invalid input: %s\n", str);
            return 0.0; // or any other appropriate error handling
        }

        if (decimalFound) {
            result = result + (*str - '0') * fraction;
            fraction *= 0.1;
        } else {
            result = result * 10.0 + (*str - '0');
        }

        str++;
    }

    return result * sign;
}

 #include <string.h>

void	string_to_color(char *str, t_color *color)
{
    char* token;
    char* rest = ft_strdup(str);
    int i = 0;
    
    while ((token = strtok_r(rest, ",", &rest)) != NULL && i < 3) {
        int value = ft_atoi(token);
        
        if (value < 0 || value > 255) {
            printf("Invalid color component: %s\n", token);
            free(color);
            return ; // or any other appropriate error handling
        }
        
        switch (i) {
            case 0:
                color->red = value;
                break;
            case 1:
                color->green = value;
                break;
            case 2:
                color->blue = value;
                break;
        }
        
        i++;
    }
    
    free(rest);
    
    if (i != 3) {
        printf("Invalid color format: %s\n", str);
        free(color);
        return ; // or any other appropriate error handling
    }
    
    // return color;
}