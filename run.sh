#!/bin/bash

echo Start compiling
g++ -std=c++14 main.cpp -o proj2
echo Compiled successfully

echo Start running
./proj2
echo Completed successfully