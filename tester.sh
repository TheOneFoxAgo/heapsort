#!/bin/bash

names=($1)
cases=(b a w)
for i in {0..2}
do
  ./a.out ${cases[$i]} results/${names[$i]}.txt &
done
wait

