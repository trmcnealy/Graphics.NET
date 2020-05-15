#!/bin/bash

for f in *.glsl;
do
    echo "Processing $f file..";
 
    ./glsl2cpp.exe --file $f --namespace glsl --output $(basename "$f" .glsl).hpp --name $(basename "$f" .glsl);
done

