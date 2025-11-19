#!/usr/bin/env bash

# compile g
if gcc g.c -o g -O3 -Wall -Wextra -pedantic; then
    # move to PATH
    if sudo cp ./g /usr/bin/g; then
        # remove binary from local repo
        if rm ./g; then
            # status message
            printf ":: done ♥\n"
        else
        # or kill myself
            printf ":: couldnt remove binary from local repo, fuck you ♥\n"
        fi
    else
    # or kill yourself
        printf ":: couldnt copy to PATH, fuck you ♥\n"
    fi
else 
# or kill ourselves
    printf ":: couldnt compile, fuck you ♥\n"
fi

