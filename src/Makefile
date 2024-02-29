TARGETS = pfad_data_filter catana_data_filter
#TARGET = pfad_data_filter
#TARGET = read_pfaddata

SRCS  = $(wildcard DataMergeFilter*.cc)
OBJS  = $(notdir $(SRCS:.cc=.o))

CXXFLAGS = -Wall -O2 $(shell root-config --cflags) -I$(NPTOOL_HOME)/default/include
LDFLAGS += $(shell root-config --glibs) -L$(NPTOOL_HOME)/default/lib -lNPPfad

all: $(TARGETS)

pfad_data_filter: $(OBJS) pfad_data_filter.o
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $@.o

catana_data_filter: $(OBJS) catana_data_filter.o
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $@.o

clean:
	rm -f $(TARGETS) *.o *~
	rm -f ../bin/$(TARGETS)

install:
	cp $(TARGETS) ../bin
