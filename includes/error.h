/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:47:39 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:47:41 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H

# define ERROR_H

# define MALLOC_ERROR "Fail to malloc"
# define INVALID_ARGUMENT "Wrong argument"
# define WRONG_FORMAT "Put .rt format"
# define INVALID_IDENTIFIER "Invalid indentifier in .rt file"

# define PARSE_AMBIENT "parsing error: Ambient light"
# define PARSE_CAMERA "parsing error: Camera"
# define PARSE_LIGHT "parsing error: Light"
# define PARSE_COLOR "parsing error: color"
# define PARSE_VECTOR "parsing error: vector"
# define PARSE_COORDINATE "parsing error: coordinate"
# define PARSE_DOUBLE "parsing error: double"

# define PARSE_SPHERE "parsing error: sphere"
# define PARSE_PLANE "parsing error: plane"
# define PARSE_CYLINDER "parsing error: cylinder"
# define PARSE_PARABOLOID "parsing error: paraboloid"

# define LACK_ELEMENT "Missing necessary elements in .rt file"

#endif