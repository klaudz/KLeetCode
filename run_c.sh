#!/bin/sh

c_file="${1}"
if [ ! -n "${c_file}" ]; then
    echo "usage: run.sh c_file"
    exit
fi
gcc "${c_file}" common/*.c && ./a.out
rm -rf a.out