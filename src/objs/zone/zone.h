/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:11:15 by du.than           #+#    #+#             */
/*   Updated: 2025/03/17 07:25:21 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZONE_H
#define ZONE_H
#include "../block/block.h"
#define TINY_ZONE_LIMIT_SIZE 

typedef struct s_zone
{
	struct s_block *blocks;
}	t_zone;

t_chunk		*zone_find_free_chunk(t_zone *zone, size_t size);
t_block		*zone_extend_new_block(t_zone *zone, size_t size);

#endif
