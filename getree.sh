#!/bin/bash

cd /home/bo/Desktop/omega/ROOT
rm -f *
cd ..
rm rungetree.C
runscript=rungetree.C
echo "void rungetree() {" >> $runscript
echo 'gROOT->ProcessLine(".x getree.C");' >> $runscript
echo '}' >> $runscript
echo 'exit();' >> $runscript
root -b rungetree.C

