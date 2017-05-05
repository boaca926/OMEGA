#include <iostream>
void compile() {
   gROOT->ProcessLine(".L MyClass.C+");
   gROOT->ProcessLine(".L Analys.C+"); 
//   gROOT->ProcessLine("Analys(inputFileName,outputFileName)");
   exit();
}
