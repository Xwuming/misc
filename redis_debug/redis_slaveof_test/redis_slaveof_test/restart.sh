#!/bin/bash

echo "kill ..."
ps -ef | grep redis | grep -v grep | awk '{print $2}' | xargs kill
sleep 1
echo "start ..."
sleep 1
./bin/redis-server ./conf/redis.3000.conf
./bin/redis-server ./conf/redis.3001.conf
echo OK
