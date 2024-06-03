#!/bin/bash

cd /home/alireza/Documents/Traffic/build

cmake ..
make

cd ../exe

./traffic_light &
./vehicle &
./pedestrian &

cd ..
