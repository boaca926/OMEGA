#include <iostream>
void run291() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30770.root";
TString outputFileName = "output291.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
