#!/bin/sh
if [ $# -eq 1 ]; then
    PHP_DIR=$1
else
   echo "usage: $0 <php-config path>" 
   exit
fi
echo "building wrap.."
swig -php7 crc64.i

echo "building interface.."
gcc  -fpic  `$PHP_DIR --includes`   -c crc64.c crc64_wrap.c

echo "linking.. "
gcc -shared *.o  -o crc64.so
echo "success"
