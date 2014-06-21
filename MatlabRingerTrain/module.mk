# Test if Matlab is installed:
ifneq ($(findstring matlab,$(shell which matlab)),)

ifndef all_names_defined


  MATRINGTRAIN_MODULE            := MATRINGTRAIN_
  MATRINGTRAIN_MODULENAME        := MatlabRingerTrain
  MATRINGTRAIN_DIRBASE           := $(MATRINGTRAIN_MODULENAME)

ifneq ($(call is_makeclean),yes)
$(info Defining $(MATRINGTRAIN_MODULENAME) names...)
endif

  MATRINGTRAIN_DIRM     := $(MATRINGTRAIN_DIRBASE)/$(matlab_dir_name)
  MATRINGTRAIN_DM := $(filter %.m,$(wildcard $(MATRINGTRAIN_DIRM)/*))

  matlab_files += $(MATRINGTRAIN_DM) 


else

ifneq ($(call is_makeclean),yes)
$(info Defining $(MATRINGTRAIN_MODULENAME) rules...)
endif

endif

endif
