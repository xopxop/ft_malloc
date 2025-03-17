/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:10:19 by dthan             #+#    #+#             */
/*   Updated: 2025/03/17 14:40:12 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "../../helpers/formulars.h"
#include <stdio.h>

size_t	aligned_chunk_data_size()
{
	return (aligned_data_size(sizeof(t_chunk), sizeof(void*)));
}

void	*chunk_get_data(t_chunk *chunk)
{
	return (void*)((char*)chunk + aligned_chunk_data_size());
}

t_chunk *new_chunk(void *base_address, size_t data_size)
{
	t_chunk *chunk;

	chunk = (t_chunk*)base_address;
	chunk->meta_data.data_size = data_size;
	chunk->meta_data.is_free = 1;
	chunk->next = NULL;
	return (chunk);
}

void	chunk_split(t_chunk *chunk, size_t size)
{
	t_chunk *splitted_chunk;

	splitted_chunk = new_chunk( \
		(char*)chunk + aligned_chunk_data_size() + size, \
		chunk->meta_data.data_size - size - aligned_chunk_data_size() \
	);
	splitted_chunk->next = chunk->next;
	chunk->next = splitted_chunk;
	chunk->meta_data.data_size = size;
	// printf("SPLITTED CHUNK 1: address of chunk: %p, free: %d, data_size: %zu, next: %p\n", chunk, chunk->meta_data.is_free, chunk->meta_data.data_size, chunk->next);
	// printf("SPLITTED CHUNK 2: address of chunk: %p\n", splitted_chunk);
}
