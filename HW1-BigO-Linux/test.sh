#!/bin/sh

RES=`ls *.pdf`

echo $RES

if [ "$RES" = "" ]
then
    echo "No PDF found yet"
    exit 1
else
    echo "PDF file found - success"
    exit 0
fi
