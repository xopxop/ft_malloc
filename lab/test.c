#include <stdio.h>
#include <unistd.h>
#define TINY(x) x > 0 && x <= 10
#include <stdlib.h>

typedef enum			e_heap_type
{
	TINY,
	SMALL,
	LARGE
}						t_heap_type;

typedef struct			s_block
{
	size_t				size;
	struct s_block		*next;
	struct s_block		*prev;
	int					free;
	char				data[1];
}						t_block;

typedef struct			s_heap
{
	t_heap_type			heap_type;
	size_t				total_size;
	size_t				free_size;
	size_t				block_count;
	t_block				*first_block;
	char				pad[24];
}						t_heap;

int main()
{
	printf("heap: %ld\n", sizeof(t_heap));
	printf("block: %ld\n", sizeof(int));
	return 0;
}