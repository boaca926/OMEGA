#include <iostream>
void run83() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30488.root";
TString outputFileName = "output83.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
