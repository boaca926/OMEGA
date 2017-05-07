#include <iostream>
void run197() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30632.root";
TString outputFileName = "output197.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
