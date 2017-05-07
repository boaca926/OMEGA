#include <iostream>
void run303() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30783.root";
TString outputFileName = "output303.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
