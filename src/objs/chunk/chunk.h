/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:09:30 by dthan             #+#    #+#             */
/*   Updated: 2023/07/03 12:08:19 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_H
#define CHUNK_H

typedef struct s_chunk
{
  int available;
	size_t size;
  size_t max_size;
  size_t offset;
	struct s_chunk *next;
}	t_chunk;

#endif