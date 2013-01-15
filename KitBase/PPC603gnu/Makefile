# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))
WRVX_COMPBASE := $(subst \,/,$(WRVX_COMPBASE))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/workspace/2012
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/KitBase



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 

IDE_DEFINES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = KitBase/$(MODE_DIR)/KitBase.out \
	 KitBase_partialImage/$(MODE_DIR)/KitBase_partialImage.o


#Rules

# KitBase
ifeq ($(DEBUG_MODE),1)
KitBase/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
KitBase/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
KitBase/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
KitBase/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
KitBase/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
KitBase/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
KitBase/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
KitBase/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
KitBase/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
KitBase/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
KitBase/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
KitBase/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
KitBase/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
KitBase/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
KitBase/$(MODE_DIR)/% : IDE_DEFINES = 
KitBase/$(MODE_DIR)/% : PROJECT_TYPE = DKM
KitBase/$(MODE_DIR)/% : DEFINES = 
KitBase/$(MODE_DIR)/% : EXPAND_DBG = 0
KitBase/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
KitBase/$(MODE_DIR)/% : CPU = PPC603
KitBase/$(MODE_DIR)/% : TOOL_FAMILY = gnu
KitBase/$(MODE_DIR)/% : TOOL = gnu
KitBase/$(MODE_DIR)/% : TOOL_PATH = 
KitBase/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
KitBase/$(MODE_DIR)/% : LIBPATH = 
KitBase/$(MODE_DIR)/% : LIBS = 
KitBase/$(MODE_DIR)/% : OBJ_DIR := KitBase/$(MODE_DIR)

OBJECTS_KitBase = KitBase_partialImage/$(MODE_DIR)/KitBase_partialImage.o

KitBase/$(MODE_DIR)/KitBase.out : $(OBJECTS_KitBase)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_KitBase) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_KitBase) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

KitBase/$(MODE_DIR)/KitBase_compile_file : $(FILE) ;

_clean :: KitBase/$(MODE_DIR)/KitBase_clean

KitBase/$(MODE_DIR)/KitBase_clean : 
	$(TRACE_FLAG)if [ -d "KitBase" ]; then cd "KitBase"; rm -rf $(MODE_DIR); fi


# KitBase_partialImage
ifeq ($(DEBUG_MODE),1)
KitBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
KitBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
KitBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
KitBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
KitBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
KitBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
KitBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
KitBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
KitBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
KitBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
KitBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
KitBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
KitBase_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
KitBase_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
KitBase_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
KitBase_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
KitBase_partialImage/$(MODE_DIR)/% : DEFINES = 
KitBase_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
KitBase_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
KitBase_partialImage/$(MODE_DIR)/% : CPU = PPC603
KitBase_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
KitBase_partialImage/$(MODE_DIR)/% : TOOL = gnu
KitBase_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
KitBase_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
KitBase_partialImage/$(MODE_DIR)/% : LIBPATH = 
KitBase_partialImage/$(MODE_DIR)/% : LIBS = 
KitBase_partialImage/$(MODE_DIR)/% : OBJ_DIR := KitBase_partialImage/$(MODE_DIR)

KitBase_partialImage/$(MODE_DIR)/Objects/KitBase/KitBase.o : $(PRJ_ROOT_DIR)/KitBase.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_KitBase_partialImage = KitBase_partialImage/$(MODE_DIR)/Objects/KitBase/KitBase.o

KitBase_partialImage/$(MODE_DIR)/KitBase_partialImage.o : $(OBJECTS_KitBase_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_KitBase_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

KitBase_partialImage/$(MODE_DIR)/KitBase_partialImage_compile_file : $(FILE) ;

_clean :: KitBase_partialImage/$(MODE_DIR)/KitBase_partialImage_clean

KitBase_partialImage/$(MODE_DIR)/KitBase_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "KitBase_partialImage" ]; then cd "KitBase_partialImage"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := KitBase_partialImage/$(MODE_DIR)/Objects/KitBase/KitBase.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

JOBS?=1
ifeq ($(JOBS),1)
main_all : external_build  $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"
else
main_all : external_build 
	@$(MAKE) -f $(MAKEFILE) --jobs $(JOBS) $(MFLAGS) $(PROJECT_TARGETS);\
	echo "make: built targets of `pwd`"
endif 

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
