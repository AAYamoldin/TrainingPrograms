#!/bin/sh
ls -l | awk '{ if (FNR%2 == 1) {print $0}}'
