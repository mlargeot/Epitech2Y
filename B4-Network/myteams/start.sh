#!/bin/bash

if [ "$1" = "cli" ]; then
    current_second=$(cat last_current_second.txt)
    LD_LIBRARY_PATH="./libs/myteams" LD_PRELOAD="./libs/myteams/libmyteams.so" ./myteams_cli 127.0.0.1 42$((current_second % 10))2

else
    current_second=$(date +%S)
    echo $current_second > last_current_second.txt
    LD_LIBRARY_PATH="./libs/myteams" LD_PRELOAD="./libs/myteams/libmyteams.so" ./myteams_server 42$((current_second % 10))2
fi
