################################################################
# COMPILE FLAGS

# Add additional LDFLAGS etc:



################################################################
# APP/DISK creation

SUFFIX = .prg
DISK_TASKS += .d64

.d64:
	@echo "TODO: create D64 rule in custom-c64.mk"

################################################################
# TESTING / EMULATOR

c64_EMUCMD    := $(VICE_HOME)x64sc -kernal kernal -VICIIdsize -autoload
c128_EMUCMD   := $(VICE_HOME)x128 -kernal kernal -VICIIdsize -autoload
c16_EMUCMD    := $(VICE_HOME)xvic -kernal kernal -VICdsize -autoload
pet_EMUCMD    := $(VICE_HOME)xpet -Crtcdsize -autoload
plus4_EMUCMD  := $(VICE_HOME)xplus4 -TEDdsize -autoload
x16_EMUCMD    := $(VICE_HOME)xplus4 -ramsize 16 -TEDdsize -autoload
cbm510_EMUCMD := $(VICE_HOME)xcbm2 -model 510 -VICIIdsize -autoload
cbm610_EMUCMD := $(VICE_HOME)xcbm2 -model 610 -Crtcdsize -autoload
