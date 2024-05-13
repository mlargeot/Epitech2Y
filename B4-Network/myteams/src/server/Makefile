##
## EPITECH PROJECT, 2023
## B-NWP-400-REN-4-1-myteams-morgan.largeot
## File description:
## Makefile
##

SRC	=   main.c \
		\
		middleware/auth_middleware.c \
		\
		utils/extract_bearer_token.c \
		utils/uuid.c \
		\
		controller/teams_controller.c \
		controller/channels_controller.c \
		controller/threads_controller.c \
		controller/users_controller.c \
		controller/messages_controller.c \
		controller/auth_controller.c \
		controller/ping_controller.c \
		\
		service/auth/login_auth.c \
		service/auth/logout_auth.c \
		\
		service/teams/create_team.c \
		service/teams/get_team.c \
		service/teams/subscription_team.c \
		service/teams/team_entity_to_xml.c \
		\
		service/channels/create_channel.c \
		service/channels/get_channel.c \
		service/channels/channel_entity_to_xml.c \
		\
		service/threads/create_thread.c \
		service/threads/get_thread.c \
		service/threads/reply_thread.c \
		service/threads/thread_entity_to_xml.c \
		service/threads/thread_reply_entity_to_xml.c \
		\
		service/users/get_user.c \
		service/users/send_message_user.c \
		service/users/user_entity_to_xml.c \
		\
		service/ping/get_ping.c \
		\
		service/messages/get_messages.c \
		service/messages/message_entity_to_xml.c \
		\
		db/get_set_db.c \
		db/init_db.c \
		db/save_db.c \
		db/load_db.c \
		db/free_db.c \
		db/entity/team.c \
		db/entity/channel.c \
		db/entity/thread.c \
		db/entity/user.c \
		db/entity/user_team.c \
		db/entity/message.c \
		db/entity/comment.c \
		db/getters/simple.c \
		db/getters/simple_bis.c \
		db/getters/get_channels.c \
		db/getters/get_comments.c \
		db/getters/get_messages.c \
		db/display_db.c

OBJ = $(SRC:.c=.o)

INCLUDE_FLAGS = \
	-I ../../include \
	-I ../../libs/myteams \
	-I ../../libs/simple-map-c/include \
	-I ../../libs/simple-list-c/include \
	-I ../../libs/simple-xml-c/include \
	-I ../../libs/http-standard-c/include \

C_WARNING_FLAGS = -Wextra -Wall -g
C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

# Library
LIB_FLAGS = \
	-luuid \
	-L ../../libs/http-standard-c -l:http_standard.a \
	-L ../../libs/simple-xml-c -l:simple_xml.a \
	-L ../../libs/simple-map-c -l:simple_map.a \
	-L ../../libs/simple-list-c -l:simple_list.a \
	-L ../../libs/myteams -l:libmyteams.so \

NAME = myteams_server

GCC = gcc

all: $(NAME)

.c.o:
	@echo "$(notdir $(CURDIR)): C '$<'"
	@$(GCC) $(C_FLAGS) -c -o $*.o $<

$(NAME): $(OBJ)
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
