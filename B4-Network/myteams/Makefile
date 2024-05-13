##
## EPITECH PROJECT, 2024
## B-NWP-400-REN-4-1-myteams-morgan.largeot
## File description:
## Makefile
##

all:
	$(MAKE) -C libs/http-standard-c
	$(MAKE) -C libs/simple-list-c
	$(MAKE) -C libs/simple-map-c
	$(MAKE) -C libs/simple-xml-c
	$(MAKE) -C libs/simple-fetch-c
	$(MAKE) -C src/client
	$(MAKE) -C src/server
	mv src/client/myteams_cli .
	mv src/server/myteams_server .

clean:
	$(MAKE) clean -C libs/http-standard-c
	$(MAKE) clean -C libs/simple-list-c
	$(MAKE) clean -C libs/simple-map-c
	$(MAKE) clean -C libs/simple-xml-c
	$(MAKE) clean -C libs/simple-fetch-c
	$(MAKE) clean -C src/client
	$(MAKE) clean -C src/server

fclean:
	$(MAKE) fclean -C libs/http-standard-c
	$(MAKE) fclean -C libs/simple-list-c
	$(MAKE) fclean -C libs/simple-map-c
	$(MAKE) fclean -C libs/simple-xml-c
	$(MAKE) fclean -C libs/simple-fetch-c
	$(MAKE) fclean -C src/client
	$(MAKE) fclean -C src/server
	rm -f myteams_cli
	rm -f myteams_server

re: fclean all
