# Or, GLSLANG_BINARY_DIR = $(WHERE_PACKAGE_UNPACKED)/bin
TREES := $(HOME)/trees
GLSLANG_SOURCE_DIR     :=       $(TREES)/glslang
GLSLANG_BINARY_DIR     :=       $(GLSLANG_SOURCE_DIR)/build/StandAlone
SPIRV_TOOLS_SOURCE_DIR     :=       $(GLSLANG_SOURCE_DIR)/External/spirv-tools

OPT     := -O2
# OPT     := -g

GLSLANG_CC_OPTIONS     :=      -DAMD_EXTENSIONS -DENABLE_HLSL -DENABLE_OPT=1 -DGLSLANG_OSINCLUDE_UNIX -DNV_EXTENSIONS -DSPIRV_CHECK_CONTEXT -DSPIRV_COLOR_TERMINAL -DSPIRV_MAC -DSPIRV_TOOLS_IMPLEMENTATION -DSPIRV_TOOLS_SHAREDLIB -DSPIRV_Tools_shared_EXPORTS

CFLAGS 		:=	-Wall
CXXFLAGS        :=      $(OPT) -Wall -I$(SPIRV_TOOLS_SOURCE_DIR)/include -I$(GLSLANG_SOURCE_DIR) $(GLSLANG_CC_OPTIONS) --std=c++17

LDFLAGS         :=      $(OPT)
LDLIBS          :=      $(GLSLANG_SOURCE_DIR)/build/glslang/libglslang.a $(GLSLANG_SOURCE_DIR)/build/SPIRV/libSPIRV.a $(GLSLANG_SOURCE_DIR)/build/SPIRV/libSPVRemapper.a $(GLSLANG_SOURCE_DIR)/build/StandAlone/libglslang-default-resource-limits.a -lpthread $(GLSLANG_SOURCE_DIR)/build/glslang/libglslang.a $(GLSLANG_SOURCE_DIR)/build/OGLCompilersDLL/libOGLCompiler.a $(GLSLANG_SOURCE_DIR)/build/glslang/OSDependent/Unix/libOSDependent.a $(GLSLANG_SOURCE_DIR)/build/hlsl/libHLSL.a $(GLSLANG_SOURCE_DIR)/build/External/spirv-tools/source/opt/libSPIRV-Tools-opt.a $(GLSLANG_SOURCE_DIR)/build/External/spirv-tools/source/libSPIRV-Tools.a

DIS_OBJ 	:=	riscv-disas.o

SHADE_SRCS      =      shade.cpp program.cpp image.cpp
SHADE_OBJS      =      $(SHADE_SRCS:.cpp=.o)

DEPS            = $(SHADE_OBJS:.o=.d)

.PHONY: all
all: shade as gpuemu

-include $(DEPS)

# $(GLSLANG_SOURCE_DIR)/build/glslang/libglslang.a $(GLSLANG_SOURCE_DIR)/build/glslang/OSDependent/Unix/libOSDependent.a

%.o: %.cpp
	$(CXX) $(CXXFLAGS)  $< -c -o $@ -MMD

shade: $(SHADE_OBJS) 
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SHADE_OBJS) -o $@ $(LDLIBS)

as: as.cpp $(DIS_OBJ)
	$(CXX) --std=c++17 -Wall as.cpp $(DIS_OBJ) -o $@

gpuemu: gpuemu.cpp $(DIS_OBJ) gpuemu.h
	$(CXX) --std=c++17 -Wall gpuemu.cpp $(DIS_OBJ) -o $@

simple.spv: simple.frag
	cat preamble.frag simple.frag epilogue.frag | $(GLSLANG_BINARY_DIR)/glslangValidator -H -V100 -d -o simple.spv --stdin -S frag

# ~/trees/glslang/External/spirv-tools/external/spirv-headers/include/spirv/1.2/spirv.core.grammar.json
# ~/trees/glslang/External/spirv-tools/external/spirv-headers/include/spirv/1.2/extinst.glsl.std.450.grammar.json

.PHONY: generate
generate:
	python3 generate_ops.py $(GLSLANG_SOURCE_DIR)/External/spirv-tools/external/spirv-headers/include/spirv/1.2/spirv.core.grammar.json $(GLSLANG_SOURCE_DIR)/External/spirv-tools/external/spirv-headers/include/spirv/1.2/extinst.glsl.std.450.grammar.json

.PHONY: clean
clean:
	if [ -f simple.spv ]; then rm simple.spv; fi
	if [ -f shade ]; then rm shade; fi
	if [ -f $(DIS_OBJ) ]; then rm $(DIS_OBJ); fi

.PHONY: dis
dis: simple.spv
	$(GLSLANG_SOURCE_DIR)/build/External/spirv-tools/tools/spirv-dis simple.spv | cat
