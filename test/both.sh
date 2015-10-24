#! /bin/sh

taskset -c 3 ./test A &
taskset -c 3 ./test B &

