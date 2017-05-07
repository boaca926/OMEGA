#include <iostream>
void run328() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30877.root";
TString outputFileName = "output328.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
