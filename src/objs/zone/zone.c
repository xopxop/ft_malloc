/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:53:06 by dthan             #+#    #+#             */
/*   Updated: 2025/03/17 14:30:40 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zone.h"
#include <stdio.h>

t_chunk	*zone_find_free_chunk(t_zone *zone, size_t size)
{
	t_block	*block;
	t_chunk	*chunk;

	block = zone->blocks;
	while (block)
	{
		printf("BLOCK: address of block: %p\n", block);
		chunk = block_find_free_chunk(block, size);
		printf("RETURNED CHUNK: address of chunk: %p\n", (void*)chunk);
		if (chunk) {
			return (chunk);
		}
		block = block->next;
	}
	return (NULL);
}

t_block	*zone_extend_new_block(t_zone *zone, size_t size)
{
	t_block	*block;

	block = new_block(size);
	if (!block) return (NULL);
	block->next = zone->blocks;
	zone->blocks = block;
	return (block);
}
