#include <iostream>
void run183() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30616.root";
TString outputFileName = "output183.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
