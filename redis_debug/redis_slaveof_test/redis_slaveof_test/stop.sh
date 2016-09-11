#!/bin/bash

echo "kill ..."
ps -ef | grep redis | grep -v grep | awk '{print $2}' | xargs kill -9
sleep 1
echo OK
