/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:09:30 by dthan             #+#    #+#             */
/*   Updated: 2025/03/13 14:53:18 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_H
#define CHUNK_H
#define CHUNK_META_DATA_SIZE sizeof(t_chunk_meta_data)
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

tchunk	*new_chunk(char *base_address, size_t data_size);
void	chunk_split(t_chunk *chunk, size_t bytes);
void	*chunk_get_data(t_chunk *chunk);

#endif
