/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:11:15 by du.than           #+#    #+#             */
/*   Updated: 2024/12/27 15:59:47 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZONE_H
#define ZONE_H
#include "../block/block.h"

typedef struct s_zone
{
	size_t total_size;
	size_t used_size;
	struct s_block *blocks;
}	t_zone;

t_block *zone_create_new_block(t_zone *zone, size_t size);
t_chunk *zone_find_free_chunk(t_zone *zone, size_t size);

#endif
