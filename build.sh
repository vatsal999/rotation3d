#!/bin/sh

set -xe

CFLAGS=$(pkg-config --cflags raylib)
LIBS="$(pkg-config --libs raylib) -lm"

gcc $CFLAGS $LIBS main.c -o cube.out
