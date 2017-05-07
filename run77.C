#include <iostream>
void run77() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30471.root";
TString outputFileName = "output77.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
