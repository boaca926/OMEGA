#include <iostream>
void run127() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30552.root";
TString outputFileName = "output127.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
