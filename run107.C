#include <iostream>
void run107() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30522.root";
TString outputFileName = "output107.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
