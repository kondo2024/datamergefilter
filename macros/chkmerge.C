void chkmerge(){

  TFile* f0 = new TFile("root/hd01_smts_run0136.root");
  TTree *t = (TTree*)f0->Get("t_smts");
  t->AddFriend("PhysicsTree_flt","root/pfad_230MeV_run07_flt.root");
  t->AddFriend("Data_F_flt","root/catana_run0139_flt.root");

  t->Draw("PhysicsTree_flt.LTS:smts>>h1","PhysicsTree_flt.IsTSMatched","colz");
  t->Draw("PhysicsTree_flt.dTS:smts>>h2","PhysicsTree_flt.IsTSMatched","colz");

  t->Draw("Data_F_flt.Timestamp:smts>>h3","Data_F_flt.IsTSMatched","colz");
  t->Draw("Data_F_flt.dTS:smts>>h4","Data_F_flt.IsTSMatched","colz");

  t->Draw("PhysicsTree_flt.LTS:Data_F_flt.Timestamp>>h5",
	  "PhysicsTree_flt.IsTSMatched&&Data_F_flt.IsTSMatched","colz");
  t->Draw("PhysicsTree_flt.LTS:Data_F_flt.dTS>>h6",
	  "PhysicsTree_flt.IsTSMatched&&Data_F_flt.IsTSMatched","colz");

  t->Draw("Energy:Theta12>>h7",
	  "PhysicsTree_flt.IsTSMatched&&Data_F_flt.IsTSMatched&&Delta>0","colz");
  
  t->Draw("Energy:Channel>>h8",
	  "PhysicsTree_flt.IsTSMatched&&Data_F_flt.IsTSMatched&&Energy>0","colz");
  
  t->Draw("ProjectionL.z()>>h9",
	  "PhysicsTree_flt.IsTSMatched&&Data_F_flt.IsTSMatched&&Delta>0","colz");
  
}
