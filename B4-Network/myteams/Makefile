##
## EPITECH PROJECT, 2024
## B-NWP-400-REN-4-1-myteams-morgan.largeot
## File description:
## Makefile
##

all:
	$(MAKE) -C src/client
	$(MAKE) -C src/server
	mv src/client/myteams_cli .
	mv src/server/myteams_server .

clean:
	$(MAKE) clean -C src/client
	$(MAKE) clean -C src/server

fclean:
	$(MAKE) fclean -C src/client
	$(MAKE) fclean -C src/server
	rm -f myteams_cli
	rm -f myteams_server

re: fclean all
