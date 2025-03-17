/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:43:10 by dthan             #+#    #+#             */
/*   Updated: 2025/03/17 07:38:17 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
#define FT_MALLOC_H
#include "./objs/zone/zone.h"

typedef struct s_heap
{
    t_zone tiny;
    t_zone small;
    t_zone large;
}   t_heap;

// tiny and small zone has block size of one page
// large zone has block size of one to multiple pages
// tiny zone has maximum chunk size of 64 bytes
// small zone has maximum chunk size of 512 bytes
// the rest goes to large zone

#define TINY_ZONE_MAX_CHUNK_SIZE 64
#define SMALL_ZONE_MAX_CHUNK_SIZE 512
// defined alignment here according to 64 bytes machine?
#define ALIGNMENT 16

static t_heap g_heap = {
    .tiny = {
        .blocks = NULL
    },
    .small = {
        .blocks = NULL
    },
    .large = {
        .blocks = NULL
    }
};

#endif