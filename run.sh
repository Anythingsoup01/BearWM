#!/bin/bash

XEPHYR=$(which Xephyr)
xinit ./xinitrc -- \
    "$XEPHYR" \
    :1 \
    -ac \

exec ./build/BearWM
