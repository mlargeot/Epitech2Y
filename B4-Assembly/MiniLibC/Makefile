##
## EPITECH PROJECT, 2024
## MiniLibC
## File description:
## Makefile
##

NAME = libasm.so
CC = nasm
CFLAGS = -f elf64
LD = ld
LDFLAGS = -shared -o

SRC_DIR = src/

SRC = $(addprefix $(SRC_DIR),\
		memcpy.asm			 \
		memmove.asm			 \
		memset.asm			 \
		strcasecmp.asm		 \
		strchr.asm			 \
		strcmp.asm			 \
		strcspn.asm			 \
		strlen.asm			 \
		strncmp.asm			 \
		strpbrk.asm			 \
		strrchr.asm			 \
		strstr.asm			 \
		)

OBJ = $(SRC:.asm=.o)

all: $(NAME)

%.o: %.asm
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	$(LD) $(LDFLAGS) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
