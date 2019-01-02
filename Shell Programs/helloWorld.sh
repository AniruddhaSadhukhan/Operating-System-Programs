#!/bin/sh
echo "Enter name:"
read name
echo "Name: $name"
echo "Creating file  ${name}_file"
touch "${name}_file"
