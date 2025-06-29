#!/bin/bash

Xephyr :1 -ac
sleep 1

exec ./build/BearWM
