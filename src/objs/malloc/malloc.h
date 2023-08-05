/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:45:39 by dthan             #+#    #+#             */
/*   Updated: 2023/08/05 16:07:42 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZONE_H
#define ZONE_H
# include "../block/block.h"

/*
	Static malloc: already pre-allocate the memory. When an user asks for
	memory via this malloc, It will look for an available chunk in a block then
	give it to the user.
	max_asking_bytes: for filtering the malloc, max bytes per chunk
	total_used_bytes: for printing info
	total_used_chunk_count: for printing info
	blocks: blocks link list
*/

typedef struct s_static_malloc
{
	size_t max_asking_bytes;
	size_t total_used_bytes;
	size_t total_used_chunk_count;
	struct s_block *blocks;
} t_static_malloc;

/*
	Dynamic malloc: contain a list of memory blocks which has only one chunk
	per block. Whenever an user asks for a large memory which can not fit into
	the static mallocs, then use this malloc for containing the memory block.
	max_asking_bytes: for control the limit memory from the system
	total_used_bytes: for printing info
	total_used_chunk_count: for printing info
	blocks: blocks link list
*/

typedef struct s_dynamic_malloc
{
	size_t max_asking_bytes;
	size_t total_used_bytes;
	size_t total_used_chunk_count;
	struct s_block *blocks;
} t_dynamic_malloc;

t_static_malloc *new_static_malloc_obj(int pages_per_block);
t_dynamic_malloc *new_dynamic_malloc_obj();
void *static_malloc_get_memory(t_static_zone *zone, size_t bytes);
void *dynamic_malloc_get_memory(t_dynamic_zone *zone, size_t bytes);

#endif
