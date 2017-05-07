void Proceed() {
   gROOT->ProcessLine(".L MyClass.C+");
   gROOT->ProcessLine(".L Analys_new.C+");
   //gROOT->ProcessLine("Analys_new(\"mckslpath\",\"mcksl\")");
   //gROOT->ProcessLine("Analys_new(\"mceegpath\",\"mcegg\")");
   //gROOT->ProcessLine("Analys_new(\"datapath\",\"data\")");
   gROOT->ProcessLine("Analys_new(\"mcrhopath\",\"mcrho\")");
}
