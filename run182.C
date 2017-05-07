#include <iostream>
void run182() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30613.root";
TString outputFileName = "output182.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
