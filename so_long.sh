#!/bin/zsh
export DISPLAY=':0.0'
open -a xquartz
xhost +$(hostname)
xhost local: