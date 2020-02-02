#!/bin/bash

x=$(wc screenshot/README)

fileCount=$(ls ./screenshot/ | grep -v README | wc -l)

#echo $fileCount

if [ $fileCount -ne 0 ]
then
    echo 'Screenshot (or just some other file) in screenshot directory - passing test'
    exit 0
else
    echo 'No Screenshot found'
    exit 1
fi
