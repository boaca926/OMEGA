#include <iostream>
void run154() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30584.root";
TString outputFileName = "output154.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
