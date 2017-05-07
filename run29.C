#include <iostream>
void run29() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30377.root";
TString outputFileName = "output29.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
