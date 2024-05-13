##
## EPITECH PROJECT, 2022
## make
## File description:
## desc
##

SRC = \
	src/router/handle_route.c \
	src/router/add_route.c \
	src/router/find_route.c \
	\
	src/server/create_server.c \
	src/server/handle_client.c \
	src/server/start_server.c \
	src/server/handle_request.c \
	\
	src/response/send_response.c \
	src/response/free_response.c \
	src/response/type/bad_request.c \
	src/response/type/not_found.c \
	src/response/type/ok.c \
	src/response/type/created.c \
	src/response/type/forbidden.c \
	src/response/type/internal_server_error.c \
	src/response/type/unauthorized.c \
	src/response/type/no_content.c \
	src/response/type/service_unavailable.c \
	src/response/type/conflict.c \
	src/response/type/not_implemented.c \
	src/response/xml_error.c \
	\
	src/request/parse_request.c \
	src/request/free_request.c \
	\
	src/utils/string_to_method.c \
	src/utils/trim_whitespace.c \
	src/utils/get_status_message.c \

OBJ = $(SRC:.c=.o)

GCC = gcc

INCLUDE_FLAGS = \
	-I include \
	-I ../simple-map-c/include \
	-I ../simple-list-c/include \
	-I ../simple-xml-c/include

C_WARNING_FLAGS = -Wextra -Wall -g
C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

.c.o:
	@echo "$(notdir $(CURDIR)): C '$<'"
	@$(GCC) $(C_FLAGS) -c -o $*.o $<

all: http_standard.a
.PHONY : all

http_standard.a: $(OBJ)
	@ar rc $@ $(OBJ)
.PHONY : http_standard.a

clean:
	@find . \( -name "*.o" -or -name "*.a" \) -delete
.PHONY : clean

fclean: clean
	@rm -f http_standard.a

re: clean all
.PHONY: re
