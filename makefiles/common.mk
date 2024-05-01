# no fujinet in the project yet, but this is where it would be included typically
#-include makefiles/fujinet-lib.mk

VERSION_FILE := src/version.txt
VERSION_STRING := $(file < $(VERSION_FILE))

CFLAGS += -DVERSION_STRING=\"$(VERSION_STRING)\"
CFLAGS += -Osir
