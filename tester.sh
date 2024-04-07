#!/bin/bash

for i in average best worst 
do
  ./a.out $i $i.txt &
done
wait

