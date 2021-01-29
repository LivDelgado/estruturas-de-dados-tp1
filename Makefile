CC := g++
SRCDIR := src
TARGET := run.out
CFLAGS := -std=c++11 -g -Wall
# TSTDIR := test
OBJDIR := build
BINDIR := bin

MAIN := main
# TESTER := program/tester.cpp

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
# TSTSOURCES := $(shell find $(TSTDIR) -type f -name *.$(SRCEXT))

CFLAGS := -g -Wall -O3 -std=c++14
INC := -I include/ -I third_party/

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BINDIR)$(TARGET) $(OBJ)

tests: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(TESTER) $(TSTSOURCES) $^ -o $(BINDIR)/tester
	$(BINDIR)/tester

all: main

run: main
	$(BINDIR)/main

clean:
	@rm -rf $(OBJDIR)* $(BINDIR)*
