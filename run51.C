#include <iostream>
void run51() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30413.root";
TString outputFileName = "output51.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
