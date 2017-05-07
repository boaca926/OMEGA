#include <iostream>
void run181() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30612.root";
TString outputFileName = "output181.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
