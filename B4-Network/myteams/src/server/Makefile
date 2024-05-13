##
## EPITECH PROJECT, 2023
## B-NWP-400-REN-4-1-myteams-morgan.largeot
## File description:
## Makefile
##

NAME	=	myteams_server

SRC	= src/main.c \
		src/server.c \
		src/fd_handler.c \
		src/new_client.c \
		src/uuid.c \
		src/mkstw.c \
		src/stw.c \
		\
		src/commands/handle_command.c \
		../shared/time.c

SRC += src/db/display_db.c \
		src/db/free_db.c \
		src/db/init_db.c \
		src/db/get_set_db.c \
		src/db/load_db.c \
		src/db/save_db.c \
		src/db/exist.c \
		\
		src/db/entity/channel.c \
		src/db/entity/message.c \
		src/db/entity/team.c \
		src/db/entity/user.c \
		src/db/entity/thread.c \
		src/db/entity/comment.c \
		src/db/entity/user_team.c \
		\
		src/db/getters/get_channels.c \
		src/db/getters/get_messages.c \
		src/db/getters/get_comments.c \
		src/db/getters/simple_bis.c \
		src/db/getters/simple.c \
		src/db/getters/find.c

SRC += src/commands/login.c \
		src/commands/logout.c \
		src/commands/users.c \
		src/commands/user.c \
		src/commands/send.c \
		src/commands/messages.c \
		src/commands/subscribe.c \
		src/commands/subscribed.c \
		src/commands/unsubscribe.c \
		src/commands/use.c \
		src/commands/create.c \
		src/commands/list.c \
		src/commands/info.c \
		src/commands/unauthorized.c \
		src/commands/not_found.c \
		src/commands/already_exist.c \
		src/commands/client_event.c


OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I ../../include/ \
			-I ../../libs/myteams/

LDFLAGS	=	-L ../../libs/myteams -lmyteams -luuid

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
