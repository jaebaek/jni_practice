#!/bin/bash

java_home="/usr/lib/jvm/java-6-openjdk-amd64/"
gcc -shared -fpic -o libhello.so -I"$java_home"/include -I"$java_home"/include/linux HelloWorld.c
