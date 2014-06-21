ifndef all_names_defined

RUN_NEURAL_MODULE            := RUN_NEURAL_
RUN_NEURAL_MODULENAME        := RunNeural
RUN_NEURAL_PROGNAME          := run_neural_d3pd
RUN_NEURAL_LIBNAME           := neurald3pd
RUN_NEURAL_DIRBASE           := $(RUN_NEURAL_MODULENAME)

ifneq ($(call is_makeclean),yes)
$(info Defining $(RUN_NEURAL_MODULENAME) names...)
endif

$(eval $(call define_module_vars,$(RUN_NEURAL_MODULE),$(RUN_NEURAL_MODULENAME),$(RUN_NEURAL_DIRBASE),$(RUN_NEURAL_LIBNAME),$(RUN_NEURAL_PROGNAME)))


else
ifneq ($(call is_makeclean),yes)
$(info Defining $(RUN_NEURAL_MODULENAME) rules...)
endif

# Extra variables
RUN_NEURAL_DL_DEP := $(out_dir_name)/RootDictionary.o
RUN_NEURAL_DL_FLAGS := $(ROOTLIBS)

RUN_NEURAL_DP_DEP := $(CORE_DL)
RUN_NEURAL_DP_FLAGS := $(ROOTLIBS)

# Add module
$(eval $(call define_module_rules,$(RUN_NEURAL_MODULE),$(RUN_NEURAL_MODULENAME),$(RUN_NEURAL_DIRBASE),$(RUN_NEURAL_LIBNAME),$(RUN_NEURAL_PROGNAME)))


endif
