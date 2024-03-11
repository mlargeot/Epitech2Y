##
## EPITECH PROJECT, 2024
## my_ftp
## File description:
## Makefile
##

PROJECT_NAME = my_ftp

NAME = myftp

SRC =	src/err_handling/handle_error.c		\
		\
		src/server/run_server.c				\
		src/server/init_server.c			\
		src/server/server_handling.c		\
		src/server/clients_list_handling.c	\
		src/server/commands_handling.c		\
		src/server/connect_data_t.c			\
		\
		src/commands/user.c					\
		src/commands/cwd.c					\
		src/commands/cdup.c					\
		src/commands/quit.c					\
		src/commands/dele.c					\
		src/commands/pwd.c					\
		src/commands/pasv.c					\
		src/commands/port.c					\
		src/commands/help.c					\
		src/commands/noop.c					\
		src/commands/retr.c					\
		src/commands/stor.c					\
		src/commands/list.c					\
		\
		src/utils/split_str.c				\
		src/utils/close_client_data.c

MAIN = src/main.c

BUILD_DIR				=	build
OBJ						=	$(SRC:%.c=$(BUILD_DIR)/%.o) \
$(MAIN:%.c=$(BUILD_DIR)/%.o)

CFLAGS					:=	-I include/

WFLAGS					:=	-Wall -Wextra -Wno-parentheses

default:
	@$(MAKE) -j all --no-print-directory

all:	$(NAME)

$(NAME):	$(OBJ)
	@mkdir -p $(BUILD_DIR)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(WFLAGS)\
	&& echo -e "\033[1;32m[OK]\033[0m" $(NAME)\
	|| echo -e "\033[1;31m[KO]\033[0m" $(NAME)

$(BUILD_DIR)/%.o:	%.c
	@mkdir -p $(dir $@)
	@gcc -c -o $@ $< $(CFLAGS) $(WFLAGS) \
	&& echo -e "\033[1;32m[OK]\033[0m" $<\
	|| echo -e "\033[1;31m[KO]\033[0m" $<

debug: CFLAGS += -g
debug: fclean all

clean:
	@for file in $(BUILD_DIR)/; do\
		if [ -d $$file ]; then\
			rm -rf $$file;\
			echo -e "\033[1;31m[DELETED]\033[0m" $$file;\
		fi;\
	done
	@echo -e "\033[1;31m[CLEAN]\033[0m" $(PROJECT_NAME)
	@rm -f $(shell find -name '*.gc*' -type f)

fclean: clean
	@rm -rf $(BUILD_DIR)
	@echo -e "\033[1;31m[DELETED]\033[0m" $(BUILD_DIR)
	@rm -f $(NAME)
	@echo -e "\033[1;31m[DELETED]\033[0m" $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) default --no-print-directory

.PHONY: all clean fclean re debug tests_run

.SILENT: all clean fclean re debug tests_run

%:
	@echo -e "\033[1;31m[ERROR]\033[0m" "No rule to make target '$@'"
