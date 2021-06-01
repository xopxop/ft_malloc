/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 00:37:32 by dthan             #+#    #+#             */
/*   Updated: 2021/04/13 21:13:50 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#define TINY_HEAP_SIZE	(4 * getpagesize())
#define SMALL_HEAP_SIZE	(8 * getpagesize())
#define LARGE_HEAP_SIZE(size) size + sizeof(t_heap) + sizeof(t_block)
#define TINY_BLOCK_SIZE (TINY_HEAP / 128)
#define SMALL_BLOCK_SIZE (SMALL_HEAP / 128)

typedef enum			e_heap_type
{
	TINY = 0,
	SMALL,
	LARGE
}						t_heap_type;

typedef struct			s_block
{
	size_t				size;
	struct s_block		*next;
	struct s_block		*prev;
	int					is_allocated;
	int					is_deallocated;
	char				data[1];
}						t_block;

pthread_mutex_t g_mutex;

typedef struct			s_heap
{
	t_heap_type			heap_type;
	t_heap				*next;
	size_t				total_size;
	size_t				free_size;
	size_t				block_count;
	t_block				*first_block;
	t_block				*last_block;
	char				pad[32];
}						t_heap;

typedef struct			s_central_heap
{
	t_heap				*tiny;
	t_heap				*small;
	t_heap				*large;
}						t_central_heap;

typedef	struct			s_malloc_state
{
	
}						t_malloc_state;


t_central_heap g_central_heap;

void	*allocate_the_available_block_in_heap(const size_t size)
{
	
}

t_block	*extend_heap(t_block *last_block, size_t size)
{
	t_block	*new_block;


}

#include <sys/mman.h>>



t_heap_type	find_heap_type(size_t size)
{
	if (size <= TINY_BLOCK_SIZE)
		return (TINY);
	else if (size <= SMALL_BLOCK_SIZE)
		return (SMALL);
	return (LARGE);
}

t_heap	*find_heap_from_the_central_heap(t_heap_type heap_type)
{
	if (heap_type == TINY)
		return (g_central_heap.tiny);
	else if (heap_type == SMALL)
		return (g_central_heap.small);
	return (g_central_heap.large);
}

size_t	get_heap_size(t_heap_type heap_type, const size_t size)
{
	if (heap_type == TINY)
		return ((size_t)TINY_HEAP_SIZE);
	else if (heap_type == SMALL)
		return ((size_t)SMALL_HEAP_SIZE);
	return ((size_t)LARGE_HEAP_SIZE(size));
}

t_heap	*init_heap(t_heap_type	heap_type, const size_t size)
{
	void *pmap;

	pmap = mmap(
		NULL,
		get_heap_size(heap_type, size),
		PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,
		-1,
		0);
	if (pmap == MAP_FAILED)
		return (NULL);
	return ((t_heap*)pmap);
}

void	*allocate_memory_in_the_central_heap(t_heap_type heap_type, const size_t size)
{
	t_heap *heap;

	heap = find_heap_from_the_central_heap(heap_type);
	if (!heap)
	{
		heap = init_heap(heap_type, size);
		if (!heap)
			return (NULL);
	}
	return (allocate_memory_in_the_heap(heap, size));
}

void	preparing_the_returned_block(t_block *block, const size_t size)
{
	block->size = size;
	block->free = 1;
	block->
}

int		is_fittable_slot(t_heap	*heap, const size_t size)
{
	if (heap->first_block == NULL)
		return (1);
	
}

/*
ptr_heap = *heap;
while (ptr_heap)
{
	ptr_block = heap->first_block;
	while (ptr_block)
	{
		if (!ptr_block->occupied && is_suitable_block(ptr->block))
			return (ptr_block);
		ptr_block = ptr_block->next;
	}
	if (heap_able_to_create_new_block(ptr_heap))
		return (create_new_block_in_the_heap(ptr_heap, size));
	ptr_heap = ptr_heap->next;
}
new_heap = create_new_heap(heap_type);
if (heap == NULL)
	*heap = new_heap;
else
	push_new_heap_into_list_of_heap(heap, new_heap);
return (new_heap, size);
*/

t_block	*create_new_block_in_the_heap(t_heap *heap, size_t	size, t_block *last_block)
{
	t_block *new_block;

	if (last_block == NULL)
		return (create_a_fresh_block());
	new_block = (void*)last_block + sizeof(t_block) + size;
	new_block->next = NULL;
	new_block->prev = last_block;
	last_block->next = new_block;
	new_block->is_allocated = 1;
	new_block->size = size;
	new_block->is_deallocated = 0;

}

void	*find_free_memory_in_singular_heap(t_heap *heap, size_t size)
{
	t_block	*ptr_block;
	t_block	*last_block;
	
	ptr_block = heap->first_block;
	last_block = NULL;
	while (ptr_block)
	{
		if (!ptr_block->occupied && is_fittable_block(size))
			return (ptr_block->data);
		last_block = ptr_block;				
		ptr_block = ptr_block->next;
	}
	if (heap_able_to_create_new_block(heap))
		return (create_new_block_in_the_heap(heap, size, last_block)->data);
	return (NULL);
}

void	*find_free_memory_in_plural_heaps(t_heap *first_heap, size_t size)
{
	t_heap	*ptr_heap;
	void	*returned_memory;
	
	ptr_heap = first_heap;
	while (ptr_heap)
	{
		returned_memory = find_block_singular_heap(ptr_heap, size);
		if (returned_memory)
			return (returned_memory);
		ptr_heap = ptr_heap->next;
	}
	return (NULL);
}

void	*allocate_memory(t_heap **first_heap, t_heap_type *heap_type, size_t size)
{
	t_heap	*new_heap;
	void	*returned_memory;

	returned_memory = find_free_memory_in_plural_heaps(*first_heap, size);
	if (returned_memory)
		return (returned_memory);
	new_heap = create_new_heap(heap_type);
	if (!new_heap)
		return (NULL);
	push_new_heap_into_list(first_heap, new_heap);
	return (create_new_block_in_the_heap(new_heap, size)->data);
}

void	*malloc(size_t size)
{
	void	*ret;
	// pthread_mutex_init(&g_mutex, NULL);
	pthread_mutex_lock(&g_mutex);
	ret = allocate_memory((const size_t)size);
	pthread_mutex_unlock(&g_mutex);
	// pthread_mutex_destroy(&g_mutex);
	return (ret);
}
