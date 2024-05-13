if [ "$1" = "cli" ]; then
    LD_LIBRARY_PATH="./libs/myteams" LD_PRELOAD="./libs/myteams/libmyteams.so" ./myteams_cli 127.0.0.1 8080
else
    LD_LIBRARY_PATH="./libs/myteams" LD_PRELOAD="./libs/myteams/libmyteams.so" ./myteams_server 8080
fi
