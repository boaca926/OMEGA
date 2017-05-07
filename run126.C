#include <iostream>
void run126() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30551.root";
TString outputFileName = "output126.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
