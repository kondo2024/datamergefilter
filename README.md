# DataMergeFilter

This extracts and saves detector data which coincide with SAMURAI
timestamp.

### DataMergeFilter
Sample base class. You can inherit it for your
application. DataMergeFilter_PFAD is an example. Most of cases can be
covered by the base class, But you have to write some part 
(indicated by *****) in DataMergeFilter::Filter(). 

### pfad_data_filter.cc
Sample main program using DataMergeFilter_PFAD. "cd src; make; make
install" generates executable file. 

### macros/xxx_run.C
sample root macros to use DataMergeFilter. They are useful to see what
is going on in the procedure shown on Canvas.

### macros/chkmerge.C
sample root macros to make plots from merged data.
