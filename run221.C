#include <iostream>
void run221() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30668.root";
TString outputFileName = "output221.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
