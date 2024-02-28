#include "DataMergeFilter.hh"
#include <iostream>
#include "TCanvas.h"

int main(int argc, char **argv){

  if (argc<4){
    std::cout<<"usage: pfad_data_filter filename_sm filename_det filename_output"
	     <<std::endl;
    return 0;
  }

  TString fname_sm(argv[1]);
  TString fname_det(argv[2]);
  TString fname_out(argv[3]);

  DataMergeFilter filter;
  // set parameters
  filter.SetInputSMTreeName("t_smts");
  filter.SetInputDetTreeName("PhysicsTree");
  filter.SetTS2us_sm(0.01);
  filter.SetTS2us_det(0.04);
  filter.SetTSMatchWindow(10);// us
  filter.SetBranchName_smTS("smts");
  filter.SetBranchName_detTS("LTS");

  //
  bool IsOKFile;
  IsOKFile = filter.OpenInputFiles(fname_sm.Data(), fname_det.Data());
  if (!IsOKFile) return 1;

  IsOKFile = filter.OpenOutputFile(fname_out.Data());
  if (!IsOKFile) return 1;
  
  filter.FindRunStart();
  filter.FindRunEnd(850000);// temp

  filter.TSCombinations("start");
  filter.CorrectTSPeriod();
//  filter.FindTSOffset("start");// included in CorrectTSPeriod()
  filter.Filter();
  filter.MakePlots();

  return 0;
}
