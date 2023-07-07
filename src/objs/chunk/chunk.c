/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:10:19 by dthan             #+#    #+#             */
/*   Updated: 2023/07/05 21:47:18 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "../block/block.h"

t_chunk *new_chunk(void *address)
{
  t_chunk *chunk = address;
  chunk->available = 1;
  chunk->size = 0;
  return chunk;
}

void *chunk_get_memory(t_chunk *chunk, size_t size) {
  chunk->available = 0;
  chunk->size = size;
  return chunk + 1;
}
