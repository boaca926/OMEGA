#include <iostream>
void run153() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30582.root";
TString outputFileName = "output153.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
