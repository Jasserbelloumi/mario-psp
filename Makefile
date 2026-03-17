TARGET = mario
OBJS = main.c

CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBS = -lpspdebug -lpspgu -lpspctrl -lpspge -lpsprtc -lpsppower -lpspaudiolib -lpspaudio -lpsphttp -lpspssl -lpspwlan

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
