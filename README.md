# DataMergeFilter

This extracts and saves detector data which coincide with the SAMURAI
timestamp.

### DataMergeFilter
Sample base class. You can inherit it for your application.
DataMergeFilter_PFAD is an example. Most of cases can be covered by
the methods in the base class, but you have to write some part
(indicated by *****) in DataMergeFilter_XXX::Filter().

### pfad_data_filter.cc
Sample main program for PFAD using DataMergeFilter_PFAD. "cd src;
make; make install" generates executable file. NPTOOL is required and
$NPTOOL_HOME is needed to be defined (see Makefile).

### macros/pfad_run.C
sample root macros to use DataMergeFilter_PFAD. They are useful to see what
is going on in the procedure shown on Canvas. 

### macros/chkmerge.C
sample root macros to make plots from merged data.
