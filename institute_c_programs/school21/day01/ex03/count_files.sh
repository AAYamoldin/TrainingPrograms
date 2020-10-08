#!/bin/sh
find $PWD -type f -o -type d | wc -l | tr -d ' ' 
