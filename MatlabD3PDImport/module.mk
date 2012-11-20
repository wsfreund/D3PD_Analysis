# Test if Matlab is installed:
ifneq ($(findstring matlab,$(shell which matlab)),)

  MATD3PD_MODULE            := MATD3PD_
  MATD3PD_MODULENAME        := MatlabD3PDImport
  MATD3PD_LIBNAME           := matd3pd
  MATD3PD_DIRBASE           := $(MATD3PD_MODULENAME)

  # If not cleaning:
  ifneq ($(findstring found,$(patsubst clean,found,$(patsubst distclean,found,$(patsubst veryclean,found,$(MAKECMDGOALS))))),found)
    $(shell mkdir -p $(out_dir_name))
    MATLABPATHOUTPUT := $(out_dir_name)/matlabpath.txt
    # If file doesnt exist:
    ifeq ($(wildcard $(MATLABPATHOUTPUT)),) 
      $(shell matlab -nojvm -nosplash -r "disp(matlabroot);disp(mexext);exit;" | tail -3 | head -2 > $(MATLABPATHOUTPUT))
    endif
    MEX:=$(shell cat $(MATLABPATHOUTPUT) | head -1)/bin/mex
    MEXEXT:=$(shell cat $(MATLABPATHOUTPUT) | tail -1)
  else
    MATLABPATHOUTPUT := 
    MEX:=
    MEXEXT:=*
  endif

  MATD3PD_DIRS     := $(MATD3PD_DIRBASE)/$(src_dir_name)
  MATD3PD_DIRI     := $(MATD3PD_DIRBASE)/$(include_dir_name)
  MATD3PD_DIRM     := $(MATD3PD_DIRBASE)/$(matlab_dir_name)

  MATD3PD_DL_DEP := $(CORE_DL)
  MATD3PD_DL_FLAGS := -L$(lib_dir_name) -L$(shell root-config --libdir) -lCore -lCint -lTree -lRIO

  # Extra variables
  MATD3PD_EXTRACFLAGS := $(subst -fPIC,,\
      $(subst -Wall,,\
      $(subst -pthread,,$(CFLAGS))))

  MATD3PD_INCFLAGS    := -I$(out_inc_dir_name) -I$(shell root-config --incdir)


  ifdef GRL_DIR
    MATD3PD_EXTRACFLAGS += -DUSEGRL
    MATD3PD_DL_DEP += $(GRL_LIB)
  endif

  MATD3PD_DL := $(matlab_out_dir_name)/$(MATD3PD_LIBNAME).$(MEXEXT)
  MATD3PD_DS := $(wildcard $(MATD3PD_DIRS)/*.c[xp][xp]) $(wildcard $(MATD3PD_DIRS)/*.C)
  MATD3PD_DO := $(call source_to_object,$(MATD3PD_DS),$(MATD3PD_DIRS))
  MATD3PD_DI := $(wildcard $(MATD3PD_DIRI)/*.h)
  MATD3PD_DM := $(filter %.m,$(wildcard $(MATD3PD_DIRM)/*))

  objects      += $(MATD3PD_DO)
  includes     += $(MATD3PD_DI)
  sources      += $(MATD3PD_DS)
  libraries    += $(MATD3PD_DL)
  matlab_files += $(MATD3PD_DM) 

  $(out_dir_name)/load_d3pd_dict.cpp: $(MATD3PD_DIRBASE)/$(include_dir_name)/myLinkDef.h
		@echo "**"
		@echo "** Creating Root dictionary"
		@echo "**"
		rootcint -f $@ -c $<


  $(MATD3PD_DL): $(MATD3PD_DS) $(out_dir_name)/load_d3pd_dict.cpp $(MATD3PD_DL_DEP)
		@echo "**"
		@echo "** Creating matlab mex $@"
		@echo "**"
		$(MEX) -cxx $(MATD3PD_INCFLAGS) $(MATD3PD_EXTRACFLAGS) $(MATD3PD_DL_FLAGS) $(OutPutOpt) $@ $(call filter_libraries,$^) 


endif
