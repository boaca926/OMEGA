#include <iostream>
void run199() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30634.root";
TString outputFileName = "output199.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
