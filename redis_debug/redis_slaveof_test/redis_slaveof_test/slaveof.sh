#!/bin/bash


echo "slave of ..."
./bin/redis-cli -p 3001 slaveof 127.0.0.1 3000

