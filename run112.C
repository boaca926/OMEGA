#include <iostream>
void run112() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30536.root";
TString outputFileName = "output112.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
