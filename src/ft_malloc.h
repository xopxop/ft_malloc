/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:43:10 by dthan             #+#    #+#             */
/*   Updated: 2024/12/27 16:22:15 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
#define FT_MALLOC_H
#include "../objs/zone/zone.h"

typedef struct s_heap
{
    t_zone tiny;
    t_zone small;
    t_zone large;
}   t_heap;

static t_heap g_heap = {
    .tiny = {
        .total_size = 0,
        .used_size = 0,
        .blocks = NULL
    },
    .small = {
        .total_size = 0,
        .used_size = 0,
        .blocks = NULL
    },
    .large = {
        .total_size = 0,
        .used_size = 0,
        .blocks = NULL
    }
};

#endif