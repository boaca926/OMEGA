#include <iostream>
void run289() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30766.root";
TString outputFileName = "output289.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
