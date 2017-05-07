#include <iostream>
void run376() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30935.root";
TString outputFileName = "output376.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
