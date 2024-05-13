##
## EPITECH PROJECT, 2023
## B-NWP-400-REN-4-1-myteams-morgan.largeot
## File description:
## Makefile
##

SRC	= main.c \
	\
	start_handling/usage/display_usage.c \
	\
	start_handling/error_handling/handle_error.c \
	\
	utils/split_str.c \
	utils/destroy_array.c \
	utils/get_array_size.c \
	utils/mkstw.c \
	utils/is_valid_channel.c \
	utils/is_valid_thread.c \
	utils/is_valid_team.c \
	utils/is_valid_user.c \
	utils/fetch_url.c \
	\
	client_handling/init_client.c \
	client_handling/destroy_client.c \
	\
	handle_client_cmd.c \
	\
	commands/send/send_serv_request.c \
	\
	commands/send/cmd/help.c \
	commands/send/cmd/login.c \
	commands/send/cmd/logout.c \
	commands/send/cmd/use.c \
	commands/send/cmd/send.c \
	commands/send/cmd/user.c \
	commands/send/cmd/users.c \
	commands/send/cmd/messages.c \
	commands/send/cmd/create/create.c \
	commands/send/cmd/create/create_team.c \
	commands/send/cmd/create/create_channel.c \
	commands/send/cmd/create/create_thread.c \
	commands/send/cmd/create/create_reply.c \

OBJ = $(SRC:.c=.o)

INCLUDE_FLAGS = \
	-I ../../include \
	-I ../../libs/myteams \
	-I ../../libs/simple-map-c/include \
	-I ../../libs/simple-list-c/include \
	-I ../../libs/simple-xml-c/include \
	-I ../../libs/simple-fetch-c/include \

C_WARNING_FLAGS = -Wextra -Wall -g
C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

# Library
LIB_FLAGS = \
	-luuid \
	-L ../../libs/simple-fetch-c -l:simple_fetch.a \
	-L ../../libs/simple-xml-c -l:simple_xml.a \
	-L ../../libs/simple-map-c -l:simple_map.a \
	-L ../../libs/simple-list-c -l:simple_list.a \
	-L ../../libs/myteams -l:libmyteams.so \

NAME = myteams_cli

GCC = gcc

all: $(NAME)

.c.o:
	@echo "$(notdir $(CURDIR)): C '$<'"
	@$(GCC) $(C_FLAGS) -c -o $*.o $<

$(NAME): simple_map simple_list simple_xml simple_fetch $(OBJ)
	@$(GCC) -o $@ $(OBJ) $(INCLUDE_FLAGS) $(LIB_FLAGS)
.PHONY: $(NAME)

clean:
	@rm -f $(OBJ)
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re

### Library ###
simple_fetch:
	make -C ../../libs/simple-fetch-c
simple_map:
	make -C ../../libs/simple-map-c
simple_list:
	make -C ../../libs/simple-list-c
simple_xml:
	make -C ../../libs/simple-xml-c
