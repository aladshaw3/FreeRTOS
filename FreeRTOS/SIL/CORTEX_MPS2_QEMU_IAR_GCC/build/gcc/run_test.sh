#!/bin/bash

# Run the code and grab the pid
qemu-system-arm -machine mps2-an385 -cpu cortex-m3 -kernel output/RTOSDemo.out -monitor none -nographic -serial stdio &
last_pid=$!

# Display pid to console
echo $last_pid

# Sleep bash for 10 seconds
sleep 10

# Kill the qemu emulation
kill -KILL $last_pid
