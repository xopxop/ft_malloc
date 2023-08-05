/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 00:37:32 by dthan             #+#    #+#             */
/*   Updated: 2023/07/16 00:47:47 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "ft_malloc.h"

void free(void *ptr)
{
	t_block *block;

	if (ptr != NULL) {
		block = blocks_find(ptr);
		block = blocks_remove(&g_malloc_heap->blocks, block);
		delete_block_obj(block);
	}
}

void *ft_malloc(size_t size)
{
	void *memory = NULL;

	if (g_malloc_heap == NULL)
		g_malloc_heap = new_heap_obj();
	return heap_get_memory(g_malloc_heap, size);
}

void show_alloc_mem()
{
	
}

int main()
{
	char *original_str = "Hello world!";

	char *str = (char*)ft_malloc(strlen(original_str) + 1);
	strcpy(str, original_str);
	printf("%s\n", str);
	free(str);
	printf("%s\n", str);
	return (0);
}