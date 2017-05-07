#include <iostream>
void run427() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30999.root";
TString outputFileName = "output427.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
