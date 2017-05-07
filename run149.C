#include <iostream>
void run149() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30576.root";
TString outputFileName = "output149.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
