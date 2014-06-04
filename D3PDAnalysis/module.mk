ifndef all_names_defined

D3PD_MODULE            := D3PD_
D3PD_MODULENAME        := D3PDAnalysis
D3PD_PROGNAME          := run_d3pd_analysis
D3PD_LIBNAME           := anad3pd
D3PD_DIRBASE           := $(D3PD_MODULENAME)

else

# Extra variables
D3PD_DL_DEP := $(out_dir_name)/RootDictionary.o $(CORE_DL)
D3PD_DL_FLAGS := $(ROOTLIBS)

D3PD_DP_DEP := $(CORE_DL)
D3PD_DP_FLAGS := $(ROOTLIBS)
ifdef GRL_DIR
  D3PD_EXTRACFLAGS += -DUSEGRL
  D3PD_DP_DEP += $(GRL_LIB)
endif

# Add module
$(eval $(call add_module,$(D3PD_MODULE),$(D3PD_MODULENAME),$(D3PD_DIRBASE),$(D3PD_LIBNAME),$(D3PD_PROGNAME)))

# Extra rules
$(out_dir_name)/RootDictionary.cpp: $(D3PD_DIRBASE)/$(include_dir_name)/LinkDef.h
	@echo "**"
	@echo "** Creating Root dictionary"
	@echo "**"
	rootcint -f $@ -c $<

# Hack to avoid need to re-run make file following code generation target.
$(out_dir_name)/RootDictionary.o: $(out_dir_name)/RootDictionary.cpp
	@echo "**"
	@echo "** Compiling $@" 
	@echo "**"
	$(CXX) $(CFLAGS) -c $(INCFLAGS) $< -o $@ $(D3PD_EXTRACFLAGS) 

endif

