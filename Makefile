TARGET = pfad_data_filter


SRCS  = $(wildcard *.cc)
OBJS  = $(notdir $(SRCS:.cc=.o))

CXXFLAGS = -Wall -O2 $(shell root-config --cflags)
LDFLAGS += $(shell root-config --glibs)

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS)
clean:
	rm -f $(TARGET) $(OBJS) *~
