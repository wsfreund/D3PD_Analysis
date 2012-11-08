CORE_MODULE            := CORE_
CORE_MODULENAME        := Core
CORE_PROGNAME          := 
CORE_LIBNAME           := cored3pd
CORE_DIRBASE           := $(CORE_MODULENAME)

CORE_DL_DEP := 
CORE_DL_FLAGS := -L$(shell root-config --libdir) -lCore -lMathCore -lTree -lRIO

# Add module
$(eval $(call add_module,$(CORE_MODULE),$(CORE_MODULENAME),$(CORE_DIRBASE),$(CORE_LIBNAME),$(CORE_PROGNAME)))
