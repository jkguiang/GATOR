# Simple makefile

EXE=./bin/run

SOURCES=$(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)
HEADERS=$(SOURCES:.cc=.h)

CC          = g++
CXX         = g++
CXXFLAGS    = -g -O2 -Wall -fPIC -Wshadow -Woverloaded-virtual
LD          = g++
LDFLAGS     = -g -O2
SOFLAGS     = -g -shared
CXXFLAGS    = -g -O2 -Wall -fPIC -Wshadow -Woverloaded-virtual
LDFLAGS     = -g -O2
ROOTLIBS    = $(shell root-config --libs)
ROOTCFLAGS  = $(shell root-config --cflags)
CXXFLAGS   += $(ROOTCFLAGS)
CFLAGS      = $(ROOTCFLAGS) -Wall -Wno-unused-function -g -O2 -fPIC -fno-var-tracking -DLorentzVectorPtEtaPhiM4D -Icppitertools
EXTRACFLAGS = $(shell rooutil-config)
EXTRAFLAGS  = -fPIC -ITMultiDrawTreePlayer -Wunused-variable -lTMVA -lEG -lGenVector -lXMLIO -lMLP -lTreePlayer $(shell rooutil-config)

all: $(ROOUTILDIR) $(EXE)

$(EXE): $(OBJECTS) LSTTree.o trktree.o gnntree.o
	$(LD) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) $(ROOTLIBS) $(EXTRAFLAGS) -o $@

%.o: %.cc
	$(CC) $(CFLAGS) $(EXTRACFLAGS) $< -c -o $@

clean:
	rm -f $(OBJECTS) $(EXE)

cleanall: clean
	$(MAKE) -C $(ROOUTILDIR) clean

$(ROOUTILDIR):
	$(MAKE) -C $(ROOUTILDIR)

.PHONY: $(ROOUTILDIR)
