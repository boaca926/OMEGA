#!/bin/bash

cd /home/bo/Desktop/omega/mckslout
#echo hello
printf '%s\n' "$PWD"/* >/home/bo/Desktop/omega/mcksloutpath

cd /home/bo/Desktop/omega/mceegout
printf '%s\n' "$PWD"/* >/home/bo/Desktop/omega/mceegoutpath

cd /home/bo/Desktop/omega/dataout
printf '%s\n' "$PWD"/* >/home/bo/Desktop/omega/dataoutpath

cd /home/bo/Desktop/omega/mcrhout
printf '%s\n' "$PWD"/* >/home/bo/Desktop/omega/mcrhoutpath
cd ..
#cd ..
