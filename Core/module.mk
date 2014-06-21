ifndef all_names_defined

CORE_MODULE            := CORE_
CORE_MODULENAME        := Core
CORE_PROGNAME          := 
CORE_LIBNAME           := cored3pd
CORE_DIRBASE           := $(CORE_MODULENAME)

ifneq ($(call is_makeclean),yes)
$(info Defining $(CORE_MODULENAME) names...)
endif

$(eval $(call define_module_vars,$(CORE_MODULE),$(CORE_MODULENAME),$(CORE_DIRBASE),$(CORE_LIBNAME),$(CORE_PROGNAME)))


else

ifneq ($(call is_makeclean),yes)
$(info Defining $(CORE_MODULENAME) rules...)
endif

CORE_DL_DEP := 
CORE_DL_FLAGS := -L$(shell root-config --libdir) -lCore -lMathCore -lTree -lRIO

# Add module rules
$(eval $(call define_module_rules,$(CORE_MODULE),$(CORE_MODULENAME),$(CORE_DIRBASE),$(CORE_LIBNAME),$(CORE_PROGNAME)))


endif
