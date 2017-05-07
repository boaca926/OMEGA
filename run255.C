#include <iostream>
void run255() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30720.root";
TString outputFileName = "output255.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
