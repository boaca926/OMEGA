#include <iostream>
void run95() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30506.root";
TString outputFileName = "output95.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
