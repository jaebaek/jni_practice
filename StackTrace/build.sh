#!/bin/bash

PROJECT=${PWD##*/}

function set_project() {
    PROJECT=$1
}

[[ $# -gt 0 ]] && set_project
echo "PROJECT=$PROJECT"

function note_create_java_file() {
    echo "Create $PROJECT.java first"
    exit 1
}

[[ -f $PROJECT.java ]] || note_create_java_file

java_home="/usr/lib/jvm/java-6-openjdk-amd64/"
gcc -shared -fpic -o lib$PROJECT.so -I"$java_home"/include -I"$java_home"/include/linux $PROJECT.c
java -Djava.library.path=. $PROJECT
