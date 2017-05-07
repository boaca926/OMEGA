#include <iostream>
void run419() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30991.root";
TString outputFileName = "output419.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
