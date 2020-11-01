#!/bin/env sh

# Tool to make a shapes.js file by looking for all the .obj files.

echo > shapes.js
for path in $(ls *.obj); do
    name=$(echo $path | rev | cut -c 5- | rev)
    echo "Found shape: $name ($path)"
    cat $path | ./obj2webgl $name >> shapes.js
done

