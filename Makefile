ft_malloc:
	gcc -g src/ft_malloc.c src/objs/heap/heap.c src/objs/block/block.c

CC := clang
CFLAGS := -Wall -Wextra -Werror
DEBUG := -g
TARGET := ft_malloc

OBJ_DIR = obj
SRC_DIR = src

mkdir:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): mkdir $(OBJ_FILES)
	$(CC) $(CFLAGS) $ $(OBJ_FILES) -o $(TARGET)

lib:
	@cd $(LIBFT_DIR) && $(MAKE) -s

all: lib $(PROGRAM)
	@echo "✅ Build completed!"

clean:
	@echo "🧹 Cleaning up compiled files..."
	@cd $(LIFT_DIR) && $(MAKE) -s clean
	@rm -rf $(OBJ_DIR)
	@echo "🧼 Clean complete!"

fclean: clean
	@echo "🧹 Cleaning up executable files..."
	@cd $(LIFT_DIR) && $(MAKE) -s fclean
	@rm -rf $(PROGRAM)
	@echo "🧼 FClean complete!"

re: fclean all

.PHONY: all mkdirs lft lftprintf clean fclean re