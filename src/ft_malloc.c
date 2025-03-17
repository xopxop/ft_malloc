/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 00:37:32 by dthan             #+#    #+#             */
/*   Updated: 2025/03/17 11:08:17 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "helpers/formulars.h"

t_zone	*select_zone(size_t size)
{
	if (size > 0 && size <= TINY_ZONE_MAX_CHUNK_SIZE)
		return (&(g_heap.tiny));
	else if (size > TINY_ZONE_MAX_CHUNK_SIZE && size <= SMALL_ZONE_MAX_CHUNK_SIZE)
		return (&(g_heap.small));
	return (&(g_heap.large));
}

void	*ft_malloc(size_t size)
{
	t_zone	*zone;
	t_block	*block;
	t_chunk	*chunk;

	if (size == 0) return (NULL);
	size = aligned_data_size(size, ALIGNMENT);
	zone = select_zone(size);
	if (!zone) return (NULL);
	chunk = zone_find_free_chunk(zone, size);
	if (!chunk)
	{
		block = zone_extend_new_block(zone, size);
		if (!block) return (NULL);
		chunk = block_find_free_chunk(block, size);
	}
	if (chunk->meta_data.data_size > size + aligned_chunk_data_size())
		chunk_split(chunk, size);
	chunk->meta_data.is_free = 0;
	return (chunk_get_data(chunk));
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
