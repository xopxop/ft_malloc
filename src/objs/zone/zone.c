/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:53:06 by dthan             #+#    #+#             */
/*   Updated: 2024/12/27 16:02:43 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zone.h"

t_chunk	*zone_find_free_chunk(t_zone *zone, size_t size)
{
	t_block	*block;
	t_chunk	*chunk;

	block = zone->blocks;
	while (block)
	{
		chunk = block_find_free_chunk(block, size);
		if (chunk)
			return (chunk);
		block = block->next;
	}
	return (NULL);
}

t_block	*zone_create_new_block(t_zone *zone, size_t size)
{
	t_block	*block;

	block = new_block(size);
	if (!block)
		return (NULL);
	block->next = zone->blocks;
	zone->blocks = block;
	zone->total_size += block->total_size;
	return (new_block);
}