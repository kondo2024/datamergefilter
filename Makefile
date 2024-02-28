TARGET = pfad_data_filter
#TARGET = read_pfaddata


SRCS  = $(wildcard *.cc)
OBJS  = $(notdir $(SRCS:.cc=.o))

CXXFLAGS = -Wall -O2 $(shell root-config --cflags) -I$(NPTOOL_HOME)/default/include
LDFLAGS += $(shell root-config --glibs) -L$(NPTOOL_HOME)/default/lib -lNPPfad

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS)
clean:
	rm -f $(TARGET) $(OBJS) *~
