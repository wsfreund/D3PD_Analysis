include $(ROOTSYS)/etc/Makefile.arch
ROOTLIBS := $(shell root-config --libs) 
DEBUG := 0
INCFLAGS := $(shell root-config --cflags) -DDEBUG=$(DEBUG)
#INCFLAGS := -pthread -m64 -DDEBUG=${DEBUG} -I/Users/wsfreund/root/include

SPACE :=
SPACE +=

include_dir_name := inc
src_dir_name := src
out_dir_name := out
out_inc_dir_name := include
lib_dir_name := lib
matlab_dir_name := matlab
matlab_out_dir_name := matlab
bin_dir_name := bin

INCFLAGS += -I$(out_inc_dir_name)

CFLAGS += -Wall -fPIC

MV := mv

directories := $(out_dir_name) $(out_inc_dir_name) $(lib_dir_name) $(bin_dir_name) $(matlab_dir_name)

# Uncomment to make GoodRunLists
#GRL_DIR := GoodRunLists
GRL_LIB_NAME := GRL
GRL_LIB := $(lib_dir_name)/lib$(GRL_LIB_NAME).so

define print
echo "$1:$($1)"
endef

# $(call source_to_header,source_file_list)
define source_to_header
$(subst $(src_dir_name),$(include_dir_name),$(subst .c,.h,$(filter %.c,$1)) \
$(subst .cxx,.h,$(filter %.cxx,$1)) \
$(subst .C,.h,$(filter %.C,$1)) \
$(subst .cpp,.h,$(filter %.cpp,$1)))
endef

# $(call source_to_header,source_file_list,source_dir)
define source_to_object
$(subst $2,$(out_dir_name),$(subst .c,.o,$(filter %.c,$1)) \
$(subst .cxx,.o,$(filter %.cxx,$1)) \
$(subst .C,.o,$(filter %.C,$1)) \
$(subst .cpp,.o,$(filter %.cpp,$1)))
endef

# $(call filter_libraries,libraries)
define filter_libraries
$(subst .so,,$(patsubst $(lib_dir_name)/lib%,-l%,$(filter lib%.so,$1))) $(filter-out lib%.so,$1)
endef

# $(call add_module,module:1,module_name:2,dir_base:3,libname:4,progname:5)
define add_module
  $(eval $(call define_module_vars,$1,$2,$3,$4,$5))
  $(eval $(call make_library,$1,$2,$4))
  ifeq ($5,)
    $(eval $(call make_executable,$1,$4,$5))
  endif
endef

# $(call define_module_vars,module:1,module_name:2,dirbase:3,libname:4,progname:5)
define define_module_vars
  $1LIBNAME     = $4
  $1DL          = $(lib_dir_name)/lib$4.so
  $1DIRS        = $3/$(src_dir_name)
  $1DIRI        = $3/$(include_dir_name)
  $1ALLSRCFILES = $$(wildcard $$($1DIRS)/*.c[xp][xp]) $$(wildcard $$($1DIRS)/*.C)
  ifneq ($5,)
    $1DS = $$(filter-out $$($1DIRS)/$5%,$$($1ALLSRCFILES))
  else
    $1DS = $$($1ALLSRCFILES)
  endif
  $1DI          = $$(wildcard $$($1DIRI)/*.h)
  $1DO          = $$(call source_to_object,$$($1DS),$$($1DIRS))
  ifneq ($5,)
    $1DP      = $(bin_dir_name)/$5
    objects   += $(out_dir_name)/$$($1PROGNAME).o
    programs  += $$($1DP)
    $1DP_FLAGS += -L$(lib_dir_name)
  endif

  libraries += $$($1DL)
  sources   += $$($1DS)
  includes  += $$($1DI)
  objects   += $$($1DO)
endef


# $(call make_library,module:1,module_name:2,libname:3)
define make_library

$(out_dir_name)/%.o: $$($1DIRS)/%.C $$(includes)
	@echo "**"
	@echo "** Compiling $$@"
	@echo "**"
	$(CXX) $(INCFLAGS) $(CFLAGS) $$($1EXTRACFLAGS) -c $$< -o $$@
	
$(out_dir_name)/%.o: $$($(1)DIRS)/%.cxx $$(includes)
	@echo "**"
	@echo "** Compiling $$@"
	@echo "**"
	$(CXX) $(INCFLAGS) $(CFLAGS) $$($1EXTRACFLAGS) -c $$< -o $$@

ifeq ($(PLATFORM),macosx)
  $1_SOFLAGS=$(SOFLAGS)$(subst $2/,,$$($1DL))
  $1_SOFLAGS+=-L$(lib_dir_name)
else
  $1_SOFLAGS=$(SOFLAGS) -L$(lib_dir_name)
endif

$$($1DL): $$($1DO) $$($1DL_DEP)
	@echo "**"
	@echo "** Generating library $3..."
	@echo "**"
	$(LD) $$($1_SOFLAGS) $$($1DL_FLAGS) $$(call filter_libraries,$$^) $(OutPutOpt) $$($1DL)
endef

# $(call make_program,module:1,lib_name:2,prog_name:3)
define make_executable
$$($1DP): $$($1DL) $(out_dir_name)/$3.o $$($1DP_DEP) 
	@echo "**"
	@echo "** Generating executable $$@"
	@echo "**"
	$(CXX) $(CFLAGS) $$($1EXTRACFLAGS) $$($1DP_FLAGS) $$(call filter_libraries,$$^) $(OutPutOpt) $$@
endef


# Collect information from each module in these four variables.
# Initialize them here as simple variables.

modules      := $(subst /module.mk,,$(shell find . -name module.mk))
programs     := 
libraries    :=
sources      :=
objects      :=
includes     :=
matlab_files :=


# First rule is default rule
all:

include $(addsuffix /module.mk,$(modules))

.PHONY: all
all: directories includes $(programs) $(libraries) matlab

# Special rule for GoodRunList make
ifdef GRL_DIR
libraries += $(GRL_LIB)
$(GRL_LIB):
	@echo "**"
	@echo "** Making GoodRunLists"
	@echo "**"
	@$(MAKE) --directory=$(GRL_DIR) $(MAKEFLAGS)
	@mv $(GRL_DIR)/lib$(GRL_LIB_NAME).so $(lib_dir_name)
endif

.PHONY: programs
programs: $(programs) includes

.PHONY: D3PDAnalysis MatlabRingerTrain MatlabD3PDImport RunNeural
D3PDAnalysis MatlabRingerTrain MatlabD3PDImport RunNeural: Core


.PHONY: libraries
libraries: $(libraries) includes directories

.PHONY: includes
includes: $(includes)
	@cp $^ $(out_inc_dir_name)

.PHONY: matlab 
matlab: $(matlab_files)
	@cp $^ $(matlab_out_dir_name)

.PHONY: directories
directories:
	@mkdir -p $(directories)

.PHONY: clean
clean:
	@$(RM) -r $(objects) $(programs) $(libraries) $(out_inc_dir_name)

ifdef GRL_DIR
.PHONY: distclean
distclean: clean
	@$(RM) $(out_dir_name)/*.cpp $(out_dir_name)/*.h $(out_dir_name)/*.cxx
	@$(RM) $(matlab_dir_name)/*
	@$(RM) $(lib_dir_name)/*
	@$(RM) $(bin_dir_name)/*
	@$(MAKE) --directory=$(GRL_DIR) clean
else
.PHONY: distclean
distclean: clean
	@$(RM) $(out_dir_name)/*.cpp $(out_dir_name)/*.h $(out_dir_name)/*.cxx
	@$(RM) $(matlab_dir_name)/*
	@$(RM) $(lib_dir_name)/*
	@$(RM) $(bin_dir_name)/*
endif

.PHONY: veryclean
veryclean: distclean
	@$(RM) -r $(directories)

# It was necessary to change matlab libfreetype to ln -s /usr/X11/lib/libfreetype.6.dylib  $MATLABPATH/bin/lib/libfreetype.6.dylib
