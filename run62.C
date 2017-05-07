#include <iostream>
void run62() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30450.root";
TString outputFileName = "output62.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
