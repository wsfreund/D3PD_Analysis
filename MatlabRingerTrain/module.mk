# Test if Matlab is installed:
ifneq ($(findstring matlab,$(shell which matlab)),)

  MATRINGTRAIN_MODULE            := MATRINGTRAIN_
  MATRINGTRAIN_MODULENAME        := MatlabRingerTrain
  MATRINGTRAIN_DIRBASE           := $(MATRINGTRAIN_MODULENAME)

  MATRINGTRAIN_DIRM     := $(MATRINGTRAIN_DIRBASE)/$(matlab_dir_name)
  MATRINGTRAIN_DM := $(filter %.m,$(wildcard $(MATRINGTRAIN_DIRM)/*))

  matlab_files += $(MATRINGTRAIN_DM) 

endif
