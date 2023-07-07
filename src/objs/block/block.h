/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 04:03:28 by dthan             #+#    #+#             */
/*   Updated: 2023/07/07 01:57:20 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_H
#define BLOCK_H
#include "../chunk/chunk.h";
#include <stddef.h>

typedef struct s_block
{
	size_t total_used_bytes;
  size_t max_asking_bytes;
  size_t max_bytes;
  size_t chunk_count;
  struct s_block *next;
} t_block;

t_block *new_block_obj(size_t size, size_t chunks_count);
void delete_block_obj(t_block *block);
void blocks_add(t_block **blocks, t_block *new_block);
t_block *blocks_remove(t_block **blocks, t_block *remove_block);
t_block *blocks_find(void *data);
void blocks_print(t_block *blocks);


void *block_get_memory(t_block *block, size_t size);

#endif
