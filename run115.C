#include <iostream>
void run115() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30539.root";
TString outputFileName = "output115.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
