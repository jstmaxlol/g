#!/usr/bin/env bash

gcc g.c -o g -O3 -Wall -Wextra -pedantic || printf ":: shit\n"
printf ":: done\n"
