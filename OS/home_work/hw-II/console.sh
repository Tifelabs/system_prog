# !/bin/bash

console=(Xbox, PlayStation, Nintendo)
echo CONSOLE TYPES

for x in ${console[@]}; do
    echo "\t" $x
done