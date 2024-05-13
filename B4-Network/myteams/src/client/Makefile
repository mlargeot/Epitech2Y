##
## EPITECH PROJECT, 2023
## B-NWP-400-REN-4-1-myteams-morgan.largeot
## File description:
## Makefile
##

NAME =	myteams_cli

SRC	= 	main.c \
		\
		start_handling/usage/display_usage.c \
		start_handling/error_handling/handle_error.c \
		\
		utils/split_string.c \
		utils/destroy_array.c \
		utils/mkstw.c \
		utils/get_array_size.c \
		\
		client_handling/init_client.c \
		client_handling/destroy_client.c \
		\
		handle_client_command.c \
		handle_server_response.c \
		\
		commands/send/send_serv_request.c \
		commands/send/help.c \
		commands/send/args_handler.c \
		\
		commands/recv/event_49_to_100.c \
		commands/recv/event_114_to_186.c \
		commands/recv/event_205_to_276.c \
		commands/recv/event_288_to_337.c \
		commands/recv/event_352_to_414.c \
		commands/recv/event_430_to_471.c \
		commands/recv/event_500_to_501.c \
		\
		../shared/time.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I ../../include/ \
			-I ../../libs/myteams/

LDFLAGS	=	-L ../../libs/myteams -lmyteams -luuid \

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
