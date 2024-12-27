/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 00:37:32 by dthan             #+#    #+#             */
/*   Updated: 2024/12/26 15:27:50 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

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

void	*ft_malloc(size_t size)
{
	t_zone *zone;
	t_block *block;
	t_chunk *chunk;

	size = (size + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1);
	zone = select_zone(size);
	if (!zone) return NULL;
	chunk = zone_find_free_chunk(zone, size);
	if (!chunk) {
		block = zone_create_new_block(zone, size);
		if (!block) return NULL;
		chunk = block_find_free_chunk(block, size);
	}
	return (char*)chunk + CHUNK_SIZE;
}

int main()
{
	char *original_str = "Hello world!";

	char *str = (char*)ft_malloc(strlen(original_str) + 1);
	strcpy(str, original_str);
	printf("%s\n", str);
	free(str);
	printf("%s\n", str);
	return (0);
}
