#include <iostream>
void run27() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30375.root";
TString outputFileName = "output27.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
