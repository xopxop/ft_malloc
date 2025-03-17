/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:09:30 by dthan             #+#    #+#             */
/*   Updated: 2025/03/17 11:17:45 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_H
#define CHUNK_H
#include <stddef.h>

typedef struct s_chunk_meta_data
{
	size_t 	data_size;
	int	is_free;
}	t_chunk_meta_data;

typedef struct s_chunk
{
	t_chunk_meta_data	meta_data;
	struct s_chunk		*next;
}	t_chunk;

t_chunk *new_chunk(void *base_address, size_t data_size);
void	chunk_split(t_chunk *chunk, size_t bytes);
void	*chunk_get_data(t_chunk *chunk);
size_t	aligned_chunk_data_size();

#endif
