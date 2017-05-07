#include <iostream>
void run128() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30553.root";
TString outputFileName = "output128.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
