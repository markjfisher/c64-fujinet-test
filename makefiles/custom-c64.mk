################################################################
# COMPILE FLAGS

# Add additional LDFLAGS etc:


################################################################
# APP/DISK creation

SUFFIX = .prg
DISK_TASKS += .create-d64

DISK_FILE = $(DIST_DIR)/$(PROGRAM).d64

# already relies on release
.create-d64:
	@echo "creating $(DISK_FILE)"
	c1541 -format "$(PROGRAM),01" d64 $(DISK_FILE)
	@echo "copying $(DIST_DIR)/$(PROGRAM_TGT)$(SUFFIX) as $(PROGRAM_TGT)$(SUFFIX)"
	c1541 -attach $(DISK_FILE) -write $(DIST_DIR)/$(PROGRAM_TGT)$(SUFFIX) $(PROGRAM_TGT)$(SUFFIX)

################################################################
# TESTING / EMULATOR

c64_EMUCMD    := $(VICE_HOME)x64sc
c128_EMUCMD   := $(VICE_HOME)x128 -kernal kernal -VICIIdsize -autoload
c16_EMUCMD    := $(VICE_HOME)xvic -kernal kernal -VICdsize -autoload
pet_EMUCMD    := $(VICE_HOME)xpet -Crtcdsize -autoload
plus4_EMUCMD  := $(VICE_HOME)xplus4 -TEDdsize -autoload
x16_EMUCMD    := $(VICE_HOME)xplus4 -ramsize 16 -TEDdsize -autoload
cbm510_EMUCMD := $(VICE_HOME)xcbm2 -model 510 -VICIIdsize -autoload
cbm610_EMUCMD := $(VICE_HOME)xcbm2 -model 610 -Crtcdsize -autoload
