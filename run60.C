#include <iostream>
void run60() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30446.root";
TString outputFileName = "output60.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
