#!/bin/sh

cxx_file="${1}"
if [ ! -n "${cxx_file}" ]; then
    echo "usage: run.sh cxx_file"
    exit
fi
gcc "${cxx_file}" common/*.c -lstdc++ && ./a.out
rm -rf a.out