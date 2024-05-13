##
## EPITECH PROJECT, 2022
## make
## File description:
## desc
##

SRC = \
	src/xml_free.c \
	src/xml_add_data.c \
	src/xml_get_node_inner_text.c \
	src/xml_get_node_tag.c \
	src/xml_load.c \
	src/xml_parsser.c \
	src/xml_node.c \
	src/xml_file.c \
	src/xml_new.c \
	src/xml_str.c \
	src/xml_add_node.c \
	src/xml_get_node_by_tag.c \
	\
	src/utils_str_match.c \
	src/utils_str_index_of.c \
	src/utils_str_split.c \

OBJ = $(SRC:.c=.o)

GCC = gcc

INCLUDE_FLAGS = \
	-I include \
	-I ../simple-list-c/include

C_WARNING_FLAGS = -Wextra -Wall -g
C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

.c.o:
	@echo "$(notdir $(CURDIR)): C '$<'"
	@$(GCC) $(C_FLAGS) -c -o $*.o $<

all: simple_xml.a
.PHONY : all

simple_xml.a: $(OBJ)
	@ar rc $@ $(OBJ)
.PHONY : simple_xml.a

clean:
	@find . \( -name "*.o" -or -name "*.a" \) -delete
.PHONY : clean

fclean: clean
	@rm -f simple_xml.a

re: clean all
.PHONY: re
