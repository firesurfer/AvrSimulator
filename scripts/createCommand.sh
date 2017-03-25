#!/bin/bash
sed 's/ADC/'"$1"'/' ADC.h > "$1".h
sed 's/ADC/'"$1"'/g' ADC.cpp > "$1".cpp

