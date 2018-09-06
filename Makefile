src = $(wildcard src/*/*.cc)
obj = $(src:.cc=.o)
dep = $(obj:.o=.d)  # one dependency file for each source

CXX := clang++
CC := clang++
CXXFLAGS := -std=c++1y -O3
CFLAGS := -std=c++1y -O3
LDFLAGS = -lglfw -framework CoreVideo -framework OpenGL -framework IOKit -framework Cocoa -framework Carbon

all: asper_engine

asper_engine: $(obj); $(CXX) $(CFLAGS) -o $@ $^ $(LDFLAGS)

-include $(dep)   # include all dep files in the makefile

# rule to generate a dep file by using the C preprocessor
# (see man cpp for details on the -MM and -MT options)
%.d: %.cc; @$(CXX) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:; rm -f $(obj) $(dep) asper_engine

.PHONY: cleandep
cleandep:; rm -f $(dep)