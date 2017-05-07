#include <iostream>
void run344() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30900.root";
TString outputFileName = "output344.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
