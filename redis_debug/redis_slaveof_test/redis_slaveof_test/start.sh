#!/bin/bash

echo "start ..."
sleep 1
echo "./bin/redis-server ./conf/redis.3000.conf ..."
./bin/redis-server ./conf/redis.3000.conf
sleep 1
echo "./bin/redis-server ./conf/redis.3001.conf ..."
./bin/redis-server ./conf/redis.3001.conf
echo OK
