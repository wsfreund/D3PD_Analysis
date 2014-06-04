# Test if Matlab is installed:
ifneq ($(findstring matlab,$(shell which matlab)),)

ifndef all_names_defined
  MATRINGTRAIN_MODULE            := MATRINGTRAIN_
  MATRINGTRAIN_MODULENAME        := MatlabRingerTrain
  MATRINGTRAIN_DIRBASE           := $(MATRINGTRAIN_MODULENAME)
else

  MATRINGTRAIN_DIRM     := $(MATRINGTRAIN_DIRBASE)/$(matlab_dir_name)
  MATRINGTRAIN_DM := $(filter %.m,$(wildcard $(MATRINGTRAIN_DIRM)/*))

  matlab_files += $(MATRINGTRAIN_DM) 

endif

endif
