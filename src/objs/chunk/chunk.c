/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:10:19 by dthan             #+#    #+#             */
/*   Updated: 2024/12/27 17:24:49 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"

void *new_chunk(void *address, size_t total_bytes, t_chunk *next)
{
	t_chunk *chunk = address;
	chunk->free = 1;
	chunk->size = size;
	chunk->next = NULL;
}

void chunk_split(t_chunk *chunk, size_t size)
{
	t_chunk *next_chunk;

	if (chunk->size >= size + CHUNK_META_SIZE + ALIGNMENT) // need to do sth with this
	{
		next_chunk = (t_chunk*)((char*)chunk + CHUNK_META_SIZE + size);
		next_chunk->free = 1;
		next_chunk->next = chunk->next;

		chunk->size = size;
		chunk->next = nex_chunk;
	}
}
