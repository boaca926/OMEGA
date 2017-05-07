#include <iostream>
void run424() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30996.root";
TString outputFileName = "output424.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
