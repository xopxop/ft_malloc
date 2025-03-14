/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:53:06 by dthan             #+#    #+#             */
/*   Updated: 2025/03/13 15:47:12 by dthan            ###   ########.fr       */
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

t_block	*zone_extend_new_block(t_zone *zone)
{
	t_block	*new_block;

	new_block = new_block();
	if (!new_block)
		return (NULL);
	new_block->next = zone->blocks;
	zone->blocks = new_block;
	return (new_block);
}
