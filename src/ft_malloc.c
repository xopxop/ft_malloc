/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 00:37:32 by dthan             #+#    #+#             */
/*   Updated: 2025/03/13 15:54:57 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "helpers/formulars.h"
#define ALIGNMENT 16
#define TINY_ZONE_LIMIT_SIZE (getpagesize() / 100)
#define SMALL_ZONE_LIMIT_SIZE getpagesize()

t_zone *select_zone(size_t size)
{
	if (size > 0 && size <= 512)
		return &(g_heap.tiny);
	else if (size > 512 && size <= 4096)
		return &(g_heap.small);
	else if (size > 4096)
		return &(g_heap.large);
	return NULL;
}

void	*ft_malloc(size_t size)
{
	t_zone	*zone;
	t_block	*block;
	t_chunk	*chunk;
	size_t	aligned_size;

	// Selecting the zone
	zone = select_zone(size);
	if (!zone) return NULL;
	// Aligning the data size
	aligned_size = align_data_size(size, ALIGNMENT);
	// Finding a free chunk
	chunk = zone_find_free_chunk(zone, aligned_size);
	if (!chunk)
	{
		block = zone_extend_new_block(zone, size);
		if (!block) return NULL;
		chunk = block_find_free_chunk(block, size);
	}
	// Splitting the chunk if it's bigger than the requested size
	if (chunk->bytes >= size + CHUNK_META_DATA_BYTES + ALIGNMENT)
		chunk_split(chunk, size);
	// Marking the chunk as used
	chunk->is_free = 0;
	// Returning the address of the data
	return (char*)chunk + CHUNK_META_DATA_BYTES;
}

#include <stdio.h>

// Testing the allocator
int main() {
	void	*ptr1 = ft_malloc(100); // Tiny Zone
	void	*ptr2 = ft_malloc(2000); // Small Zone
	void	*ptr3 = ft_malloc(10000); // Large Zone

	printf("Allocated (Tiny): %p\n", ptr1);
	printf("Allocated (Small): %p\n", ptr2);
	printf("Allocated (Large): %p\n", ptr3);

	return 0;
}
