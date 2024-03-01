TARGET1 = pfad_data_filter
TARGET2 = catana_data_filter

SRCS  = $(wildcard DataMergeFilter*.cc)
OBJS  = $(notdir $(SRCS:.cc=.o))

CXXFLAGS = -Wall -O2 $(shell root-config --cflags) -I$(NPTOOL_HOME)/default/include
LDFLAGS += $(shell root-config --glibs) -L$(NPTOOL_HOME)/default/lib -lNPPfad

all: $(TARGET1) $(TARGET2)

pfad_data_filter: $(OBJS) pfad_data_filter.o
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $@.o

catana_data_filter: $(OBJS) catana_data_filter.o
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $@.o

clean:
	rm -f *.o *~
	rm -f $(TARGET1) ../bin/$(TARGET1)
	rm -f $(TARGET2) ../bin/$(TARGET2)

install:
	cp $(TARGET1) ../bin/
	cp $(TARGET2) ../bin/
