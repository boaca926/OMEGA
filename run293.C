#include <iostream>
void run293() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30772.root";
TString outputFileName = "output293.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
