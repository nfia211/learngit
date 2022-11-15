#!/bin/bash

cppname=$1
inputname=$2
#path=$3
outname=${cppname%.*}
outname=$outname".out"
outfile=${cppname%.*}
outfile=$outfile"out.txt"
g++ $cppname -o $outname
#sudo chmod +x path/$outname
$outname < $inputname >> $outfile 2>&1