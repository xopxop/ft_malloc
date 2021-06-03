NAME		:= libft_malloc.so
CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror -g

SRC_DIR		:= src
OBJ_DIR		:= obj

ifeq ($(HOSTTYPE),)
HOSTTYPE	:= $(shell uname -m)_$(shell uname -s)
endif

all: