void chkmerge(){

  TFile* f0 = new TFile("root/hd01_smts_run0136.root");
  TTree *t = (TTree*)f0->Get("t_smts");
  t->AddFriend("PhysicsTree_flt","root/pfad_230MeV_run07_flt.root");
  t->AddFriend("Data_F_flt","root/catana_run0139_flt.root");

  t->Draw("PhysicsTree_flt.LTS:smts","PhysicsTree_flt.IsTSMatched","colz");
  t->Draw("PhysicsTree_flt.LTS:Data_F_flt.Timestamp","PhysicsTree_flt.IsTSMatched","colz");


  
}
