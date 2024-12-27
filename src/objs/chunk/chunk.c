/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:10:19 by dthan             #+#    #+#             */
/*   Updated: 2024/12/26 15:28:02 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"

void *chunk(void *address, size_t size)
{
	t_chunk *chunk = address;
	chunk->free = 1;
	chunk->size = size;
	chunk->next = NULL;
	return (char *)chunk + CHUNK_SIZE;
}

void chunk_split(t_chunk *chunk, size_t size)
{
	t_chunk *new_chunk;
	if (chunk->size >= size + CHUNK_META_SIZE + ALIGNMENT)
	{
		new_chunk = (t_chunk*)((char*)chunk + CHUNK_META_SIZE + size);
		new_chunk->free = 1;
		new_chunk->next = chunk->next;

		chunk->size = size;
		chunk->next = new_chunk;
	}
}
