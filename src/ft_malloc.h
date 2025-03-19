/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:43:10 by dthan             #+#    #+#             */
/*   Updated: 2025/03/19 13:53:21 by dthan            ###   ########.fr       */
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

#define TINY_ZONE_MAX_CHUNK_SIZE 128
#define SMALL_ZONE_MAX_CHUNK_SIZE 512
// defined alignment here according to 64 bytes machine?
#define ALIGNMENT 4

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