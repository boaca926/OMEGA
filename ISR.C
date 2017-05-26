#include "Getname.C"

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

double getW0(double *m) {
	double mm = m[0], W0_temp = 0, w0_temp = 0.;
	double p1 = 0., p2 = 0., p3 = 0.;
	double y1 = TMath::Cos(theta0); //cout<<mm<<endl;
	double x = 1-TMath::Power(mm/sqrtS,2);
	p1 = getF1(&x); //cout<<p1<<endl;
	p2 = getF2(&x); //cout<<p2<<endl;
	TF1 *f1 = new TF1("fint",w0_theta,-y1,-y1,2);
	f1->SetParameter(0,p1);
	f1->SetParameter(1,p2);
	f1->SetParameter(2,p3);
	f1->SetParNames("Norm");
	//f1->Draw();
	//w0_temp = w0_theta(&y1,&mm); cout<<w0_temp<<endl;
	//W0_temp = fint->Integral(-y1,y1); cout<<W0_temp<<endl;
	W0_temp = alphapi*(0.5*(2-2*x+x*x)*TMath::Log((1+y1)/(1-y1))-x*x*y1);
	cout<<W0_temp<<endl;
	return W0_temp;
}

void ISR() {
	const int nb = 1, nbstep = 100;
	double W0list[nbstep];
	double mlist[nbstep];
	double par[1] = {1.};
	double m1 = 200., m2 = 1020., m_temp = 0., sum = 0.;
	double step = (m2-m1)/nbstep;
	for (int i=0;i<nbstep;i++) {
		mlist[i] = m1+i*step; //cout<<mlist[i]<<endl;
		W0list[i] = getW0(&mlist[i]); //cout<<W0list[i]<<endl;		
	}
	TCanvas *c = new TCanvas("c","W(s,x)",700,700);
	c->cd(1);
	TGraph* gf= new TGraph(nbstep,mlist,W0list);
	gf->SetLineWidth(3); 
	gf->SetMarkerStyle(21);
	gf->SetLineColor(2);
	gf->Draw("CA");
}
