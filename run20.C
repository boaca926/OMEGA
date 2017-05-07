#include <iostream>
void run20() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30349.root";
TString outputFileName = "output20.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
