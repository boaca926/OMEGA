#include <iostream>
void run47() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30402.root";
TString outputFileName = "output47.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
