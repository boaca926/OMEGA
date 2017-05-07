#include <iostream>
void run371() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30930.root";
TString outputFileName = "output371.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
