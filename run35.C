#include <iostream>
void run35() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30383.root";
TString outputFileName = "output35.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
