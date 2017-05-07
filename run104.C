#include <iostream>
void run104() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30518.root";
TString outputFileName = "output104.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
