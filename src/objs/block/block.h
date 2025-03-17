/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 04:03:28 by dthan             #+#    #+#             */
/*   Updated: 2025/03/17 07:49:02 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_H
#define BLOCK_H
#include "../chunk/chunk.h"

typedef struct s_block_meta_data
{
	size_t	total_data_size;
	size_t	available_data_size;
}	t_block_meta_data;

typedef struct s_block
{
	t_block_meta_data	meta_data;
	struct s_block		*next;
}	t_block;

t_block *new_block(size_t size);
t_chunk *block_find_free_chunk(t_block *block, size_t size);
size_t	aligned_block_data_size();
t_chunk *block_get_first_chunk(t_block *block);

#endif
