void Proceed() {
   gROOT->ProcessLine(".L MyClass.C+");
   gROOT->ProcessLine(".L Analys_new.C+");
   gROOT->ProcessLine("Analys_new(\"mckslpath\",\"mcksl\")");
   //gROOT->ProcessLine("Analys_new(\"mceggpath\",\"mcegg\")");
   //gROOT->ProcessLine("Analys_new(\"exppath\",\"expdata\")");
   //gROOT->ProcessLine("Analys_new(\"mcppgpath\",\"mcppg\")");
   //gROOT->ProcessLine("Analys_new(\"mcrhopath\",\"mcrho\")");
}
