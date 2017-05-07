#include <iostream>
void run55() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30436.root";
TString outputFileName = "output55.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
