#include <iostream>
void run398() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30961.root";
TString outputFileName = "output398.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
