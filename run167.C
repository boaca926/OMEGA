#include <iostream>
void run167() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30598.root";
TString outputFileName = "output167.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
