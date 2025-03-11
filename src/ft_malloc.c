/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 00:37:32 by dthan             #+#    #+#             */
/*   Updated: 2025/01/10 14:25:54 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "helpers/formulars.h"

t_zone *select_zone(size_t size)
{
	if (size > 0 && size <= 512)
		return &g_malloc_heap.tiny;
	else if (size > 512 && size <= 4096)
		return &g_malloc_heap.small;
	else if (size > 4096)
		return &g_malloc_heap.large;
	return NULL;
}

size_t alignment(t_zone *zone)
{
	if (zone == &g_malloc_heap.tiny)
		return szieof(*void);
	else if (zone == &g_malloc_heap.small)
		return 16;
	long cache_line_size = sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
	if (cache_line_size == -1) return 64;
	return cache_line_size;
}

void	*ft_malloc(size_t size)
{
	t_zone	*zone;
	t_block	*block;
	t_chunk	*chunk;
	size_t	alignment;

	zone = select_zone(size);
	if (!zone) return NULL;
	size = align_size(size, alignment(zone));
	chunk = zone_find_free_chunk(zone, size);
	if (!chunk)
	{
		block = zone_create_new_block(zone, size);
		if (!block) return NULL;
		chunk = block_find_free_chunk(block, size);
	}
	chunk_split(chunk, size);
	chunk->free = 0;
	return (char*)chunk + CHUNK_SIZE;
}

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
