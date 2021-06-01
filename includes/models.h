/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:17:01 by dthan             #+#    #+#             */
/*   Updated: 2021/04/01 20:44:27 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODELS_H
# define MODELS_H
# include <sys/mman.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/resource.h>

typedef unsigned long	size_t;

typedef enum			e_heap_group
{
	TINY,
	SMALL,
	LARGE
}						t_heap_group;

typedef struct			s_heap
{
	struct s_heap		*prev;
	struct s_heap		*next;
	t_heap_group		group;
	size_t				total_size;
	size_t				free_size;
	size_t				block_count;
}						t_heap;

#endif
