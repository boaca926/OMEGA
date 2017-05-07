#include <iostream>
void run290() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30768.root";
TString outputFileName = "output290.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
