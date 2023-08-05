/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:09:30 by dthan             #+#    #+#             */
/*   Updated: 2023/07/22 03:23:35 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_H
#define CHUNK_H

typedef struct s_chunk
{
  int available;
	size_t size;
}	t_chunk;

t_chunk *new_chunk(void *address);
void *chunk_get_memory(t_chunk *chunk, size_t size);

#endif