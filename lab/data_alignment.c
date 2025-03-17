#include <stdio.h>

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

size_t align_size(size_t size, size_t alignment)
{
    return (size + (alignment - 1)) & ~(alignment - 1);
}


int main() {
        printf("Data size: %zu bytes\n", sizeof(char));
        // printf("Data size: %zu bytes\n", align_size(sizeof(t_struct), 16));
}