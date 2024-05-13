##
## EPITECH PROJECT, 2022
## make
## File description:
## desc
##

SRC = \
	src/map_add.c \
	src/map_new.c \
	src/map_remove.c \
	src/map_get.c \
	src/map_set.c \

OBJ = $(SRC:.c=.o)

GCC = gcc

INCLUDE_FLAGS = \
	-I include

C_WARNING_FLAGS = -Wextra -Wall -g
C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

.c.o:
	@echo "$(notdir $(CURDIR)): C '$<'"
	@$(GCC) $(C_FLAGS) -c -o $*.o $<

all: simple_map.a
.PHONY : all

simple_map.a: $(OBJ)
	@ar rc $@ $(OBJ)
.PHONY : simple_map.a

clean:
	@find . \( -name "*.o" -or -name "*.a" \) -delete
.PHONY : clean

fclean: clean
	@rm -f simple_map.a

re: clean all
.PHONY: re
