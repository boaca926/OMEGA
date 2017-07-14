#include "Getname.C"
#include "gethisto.C"

double getF1(double *x) {
	double F1_temp = 0.;
	//std::cout<<"C = "<<C<<endl;
	double B1=1-C;
	double B2=1-2.*C;
	F1_temp = B1/x-B2;
	
	return F1_temp;
}

double getF2(double *x) {
	double F2_temp = 0.;
	double B1 = 1-C;
	double B2 = 1-2.*C;
	
	double F2_temp = -B1/x+B2+x/2.;
	
	return F2_temp;
}

double getF3(double *x) {
	double F3_temp = 0.;
	double B2 = 1-2.*C;
	
	F3_temp = -B2*x/2.;
	
	return F3_temp;
}

double w0_theta (double *y, double *par) {
	double Y = y[0];
	double B1 = 1-C;
	double w0_theta = (par[0]+par[1]*TMath::Power(Y,2)+par[2]*TMath::Power(Y,4))/(1-2*B1+B1*B1*TMath::Power(Y,4));
	//cout<<par[0]<<endl;
	//cout<<par[1]<<endl;
	//cout<<w0_theta<<endl;
	return w0_theta;
}

double getdelta(double *m, int *index) {
	double delta = 0., beta = 0., L = 0.;
	double x = 0., A = 0., a = 0., mm = 0, B = 0., C = 0., d = 0., D = 0., pi = 0.;
	double y1 = TMath::Cos(theta0);
	double W = 0.;
	double W0_temp = 0., W00_temp = 0.;
	pi = TMath::Pi();
	mm = m[0];
	x = 1.-TMath::Power(mm/sqrtS,2.);
	L = TMath::Log(TMath::Power(sqrtS/me,2.));
	beta = 2.*alphapi*(L-1.);
	a  = beta-1.;	
	A = beta*TMath::Power(x,a);
	B = 1.+alphapi*(pi*pi/3.-1./2.)+(3./4.)*beta-(beta*beta/24.)*(L/3.+2.*pi*pi-37./4.);
	C=beta*(1.-x/2.);
	d=(1.+3.*(1.-x)*(1.-x));
	D=(beta*beta/8.)*(4.*(2.-x)*TMath::Log(1./x)-d*TMath::Log(1.-x)/x-6.+x);
	if (index[0]) {
		W0_temp = (alphapi/x)*(TMath::Log(TMath::Power(sqrtS/me,2))-1)*(2-2*x+x*x);
		//std::cout<<"full range"<<endl;
	}
	else {
		W0_temp = (alphapi/x)*((2.-2.*x+x*x)*TMath::Log((1.+y1)/(1.-y1))-x*x*y1);
		//std::cout<<"large angle"<<endl;		
	}
	W = A*B-C+D; 
	delta = W/W0_temp-1;
	//cout<<index[0]<<endl;
	
	return delta;
}

double getWfunc(double *m) {
	double delta = 0., beta = 0., L = 0.;
	double x = 0., A = 0., a = 0., mm = 0, B = 0., C = 0., d = 0., D = 0., pi = 0.;
	double y1 = TMath::Cos(theta0);
	double W = 0.;
	double W0_temp = 0., W00_temp = 0.;
	pi = TMath::Pi();
	mm = m[0];
	x = 1.-TMath::Power(mm/sqrtS,2.);
	L = TMath::Log(TMath::Power(sqrtS/me,2.));
	beta = 2.*alphapi*(L-1.);
	a  = beta-1.;	
	A = beta*TMath::Power(x,a);
	B = 1.+alphapi*(pi*pi/3.-1./2.)+(3./4.)*beta-(beta*beta/24.)*(L/3.+2.*pi*pi-37./4.);
	C=beta*(1.-x/2.);
	d=(1.+3.*(1.-x)*(1.-x));
	D=(beta*beta/8.)*(4.*(2.-x)*TMath::Log(1./x)-d*TMath::Log(1.-x)/x-6.+x);
	W = A*B-C+D; 
	
	return W;
}

double getW0func(double *m) {
	double beta = 0., L = 0.;
	double x = 0., A = 0., a = 0., mm = 0, B = 0., C = 0., d = 0., D = 0., pi = 0.;
	double y1 = TMath::Cos(theta0);
	double W0 = 0.;
	
	pi = TMath::Pi();
	mm = m[0];
	x = 1.-TMath::Power(mm/sqrtS,2.);
	L = TMath::Log(TMath::Power(sqrtS/me,2.));
	beta = 2.*alphapi*(L-1.);
	a  = beta-1.;	
	A = beta*TMath::Power(x,a);
	B = 1.+alphapi*(pi*pi/3.-1./2.)+(3./4.)*beta-(beta*beta/24.)*(L/3.+2.*pi*pi-37./4.);
	C=beta*(1.-x/2.);
	d=(1.+3.*(1.-x)*(1.-x));
	D=(beta*beta/8.)*(4.*(2.-x)*TMath::Log(1./x)-d*TMath::Log(1.-x)/x-6.+x);
	
	W0 = (alphapi/x)*((2.-2.*x+x*x)*TMath::Log((1.+y1)/(1.-y1))-x*x*y1);
	std::cout<<"large angle"<<endl;
	
	return W0;
}

double getcorr(double *m) {
	double delta = 0., beta = 0., L = 0.;
	double x = 0., A = 0., a = 0., mm = 0, B = 0., C = 0., d = 0., D = 0., pi = 0.;
	double y1 = TMath::Cos(theta0);
	double W = 0.;
	double W0_temp = 0., W00_temp = 0.;
	pi = TMath::Pi();
	mm = m[0];
	x = 1.-TMath::Power(mm/sqrtS,2.);
	L = TMath::Log(TMath::Power(sqrtS/me,2.));
	beta = 2.*alphapi*(L-1.);
	a  = beta-1.;	
	A = beta*TMath::Power(x,a);
	B = 1.+alphapi*(pi*pi/3.-1./2.)+(3./4.)*beta-(beta*beta/24.)*(L/3.+2.*pi*pi-37./4.);
	C=beta*(1.-x/2.);
	d=(1.+3.*(1.-x)*(1.-x));
	D=(beta*beta/8.)*(4.*(2.-x)*TMath::Log(1./x)-d*TMath::Log(1.-x)/x-6.+x);
	W0_temp = (alphapi/x)*((2.-2.*x+x*x)*TMath::Log((1.+y1)/(1.-y1))-x*x*y1);
	W = A*B-C+D; 
	delta = W/W0_temp;
	//cout<<index[0]<<endl;
	
	return delta;
}

double getRatio(double *sqrts, double *xx) {
	double ssqrts = sqrts[0], W0_temp = 0, w0_temp = 0., W00_temp;
	double R = 0.;
	double p1 = 0., p2 = 0., p3 = 0.;
	double y1 = TMath::Cos(theta0); //cout<<theta0<<endl;
	//cout<<alpha<<endl;
	//double x = 1-TMath::Power(mm/sqrtS,2);
	double x = xx[0];
	//cout<<x<<endl;
	//p1 = getF1(&x); //cout<<p1<<endl;
	//p2 = getF2(&x); //cout<<p2<<endl;
	//TF1 *f1 = new TF1("fint",w0_theta,-y1,-y1,2);
	//f1->SetParameter(0,p1);
	//f1->SetParameter(1,p2);
	//f1->SetParameter(2,p3);
	//f1->SetParNames("Norm");
	//f1->Draw();
	//w0_temp = w0_theta(&y1,&mm); cout<<w0_temp<<endl;
	//W0_temp = fint->Integral(-y1,y1); cout<<W0_temp<<endl;
	W0_temp = (alphapi/x)*((2-2*x+x*x)*TMath::Log((1+y1)/(1-y1))-x*x*y1);
	W00_temp = (alphapi/x)*(TMath::Log(TMath::Power(ssqrts/me,2))-1)*(2-2*x+x*x);
	//cout<<W0_temp<<endl;
	R = W0_temp/W00_temp;
	return R;
}

void ISR() {
	gStyle->SetOptTitle(0);
	const int nb = 1, nbstep = 10000;
	int index[nbstep];
	double R0listx1[nbstep], R0listx2[nbstep], R0listx3[nbstep];
	double sqrtslist[nbstep];
	double x1list[nbstep], x2list[nbstep], x3list[nbstep];
	double mlist[nbstep];
	double m1list[nbstep], m2list[nbstep];
	double par[1] = {1.};
	double sqrts1 = 0.1, sqrts2 = sqrtS, x1 = 0.1, x2 = 0.75, x3 = 0.9;
	double m1 = 0.1, m2 = sqrtS;
	double deltalist[nbstep];
	double step = (sqrts2-sqrts1)/nbstep;
	for (int i=0;i<nbstep;i++) {
		// relative probability W(s,x,\theta)/W_{0}(s,x,0) a function of c.m. energy sqrt(s)
		sqrtslist[i] = sqrts1+i*step; 
		x1list[i] = x1; 
		R0listx1[i] = getRatio(&sqrtslist[i],&x1list[i]); 
		x2list[i] = x2;
		R0listx2[i] = getRatio(&sqrtslist[i],&x2list[i]);
		x3list[i] = x3;	
		R0listx3[i] = getRatio(&sqrtslist[i],&x3list[i]);	
		//	radative factor delta W(s,x)/W_{0}(s,x,0)-1, given c.m. energy sqrt(s) = 1.019 GeV
		mlist[i] = m1+i*step; //cout<<mlist[i]<<endl;
		index[i] = 1;
		deltalist[i]=getdelta(&mlist[i],&index[i]);
	}
	TCanvas *d = new TCanvas("d","W(s,x)/W_{0}(s,x,0)",700,700);
	TGraph* gf= new TGraph(nbstep,mlist,deltalist);
	gf->GetXaxis()->SetRangeUser(0.15,1.0);
	gf->GetYaxis()->SetRangeUser(-0.2,0.1);
	gf->GetYaxis()->SetTitleOffset(1.4);
	gf->SetLineWidth(2); 
	gf->SetLineColor(1);
	gf->SetLineStyle(1);
	gf->GetYaxis()->SetTitle("W(s,x)/W_{0}(s,x,0)-1");
	gf->GetXaxis()->SetTitle("m [GeV]");
	d->Divide(1,1);
	d->cd(1);
	gf->Draw("CA");
	
	TCanvas *c = new TCanvas("c","W_{0}(s,x,#theta)/W_{0}(s,x,0)",700,700);
	c->cd(1);
	TGraph* gf1= new TGraph(nbstep,sqrtslist,R0listx1);
	TGraph* gf2= new TGraph(nbstep,sqrtslist,R0listx2);
	TGraph* gf3= new TGraph(nbstep,sqrtslist,R0listx3);
	
	gf2->SetLineWidth(2); 
	//gf2->SetMarkerStyle(21);
	gf2->SetLineColor(1);
	gf2->SetLineStyle(2);
	gf2->GetYaxis()->SetTitle("W_{0}(s,x,#theta_{0})/W_{0}(s,x,0)");
	gf2->GetXaxis()->SetTitle("#sqrt{s} GeV");
	gf2->GetYaxis()->SetRangeUser(0.15,0.35);
	gf2->GetYaxis()->SetTitleOffset(1.4);
	gf2->Draw("CA");
	
	gf1->SetLineWidth(2); 
	//gf1->SetMarkerStyle(21);
	gf1->SetLineColor(2);
	gf1->Draw("C");
	
	gf3->SetLineWidth(2); 
	//gf3->SetMarkerStyle(21);
	gf3->SetLineColor(4);
	gf3->SetLineStyle(3);
	gf3->Draw("C");
	
	legc1 = new TLegend(0.54,0.6,0.88,0.85);
	legc1->SetFillStyle(0); 
	legc1->SetBorderSize(0);  
	legc1->SetNColumns(1);
	legc1->AddEntry(gf1,TString::Format("x = %g",x1),"l");
	legc1->AddEntry(gf2,TString::Format("x = %g",x2),"l");
	legc1->AddEntry(gf3,TString::Format("x = %g",x3),"l");
	legc1->SetTextFont(132);
	legc1->Draw("Same");
	legtextsize(legc1, 0.03);
	
	TFile hf("./Plots/ISRPlots.root","recreate");
	c->Write();
	d->Write();
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
