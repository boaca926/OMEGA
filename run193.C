#include <iostream>
void run193() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30626.root";
TString outputFileName = "output193.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
