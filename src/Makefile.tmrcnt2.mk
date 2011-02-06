# Hey Emacs, this is a -*- makefile -*-

TMRCNT2_DEVICES = at90usb646
TMRCNT2_DEVICES += at90usb647
TMRCNT2_DEVICES += at90usb1286
TMRCNT2_DEVICES += at90usb1287
TMRCNT2_DEVICES += atmega32u6
TMRCNT2_DEVICES += atmega48
TMRCNT2_DEVICES += atmega48a
TMRCNT2_DEVICES += atmega48p
TMRCNT2_DEVICES += atmega88
TMRCNT2_DEVICES += atmega88a
TMRCNT2_DEVICES += atmega88p
TMRCNT2_DEVICES += atmega88pa
TMRCNT2_DEVICES += atmega164p
TMRCNT2_DEVICES += atmega164a
TMRCNT2_DEVICES += atmega168
TMRCNT2_DEVICES += atmega168a
TMRCNT2_DEVICES += atmega168p
TMRCNT2_DEVICES += atmega324p
TMRCNT2_DEVICES += atmega324a
TMRCNT2_DEVICES += atmega324pa
TMRCNT2_DEVICES += atmega328
TMRCNT2_DEVICES += atmega328p
TMRCNT2_DEVICES += atmega640
TMRCNT2_DEVICES += atmega644
TMRCNT2_DEVICES += atmega644a
TMRCNT2_DEVICES += atmega644p
TMRCNT2_DEVICES += atmega644pa
TMRCNT2_DEVICES += atmega1280
TMRCNT2_DEVICES += atmega1284p
TMRCNT2_DEVICES += atmega2560

#Broken device
#TMRCNT2_DEVICES = at90can32
#TMRCNT2_DEVICES += at90can64
#TMRCNT2_DEVICES += at90can128
#TMRCNT2_DEVICES += atmega8
#TMRCNT2_DEVICES += atmega8u2
#TMRCNT2_DEVICES += atmega16
#TMRCNT2_DEVICES += atmega16a
#TMRCNT2_DEVICES += atmega16hva2
#TMRCNT2_DEVICES += atmega16hvb
#TMRCNT2_DEVICES += atmega16m1
#TMRCNT2_DEVICES += atmega16u
#TMRCNT2_DEVICES += atmega16u4
#TMRCNT2_DEVICES += atmega32
#TMRCNT2_DEVICES += atmega32c1
#TMRCNT2_DEVICES += atmega32hvb
#TMRCNT2_DEVICES += atmega32m1
#TMRCNT2_DEVICES += atmega32u2
#TMRCNT2_DEVICES += atmega32u4
#TMRCNT2_DEVICES += atmega64
#TMRCNT2_DEVICES += atmega64c1
#TMRCNT2_DEVICES += atmega64hve
#TMRCNT2_DEVICES += atmega64m1
#TMRCNT2_DEVICES += atmega103
#TMRCNT2_DEVICES += atmega128
#TMRCNT2_DEVICES += atmega128rfa1
#TMRCNT2_DEVICES += atmega161
#TMRCNT2_DEVICES += atmega162
#TMRCNT2_DEVICES += atmega163
#TMRCNT2_DEVICES += atmega165
#TMRCNT2_DEVICES += atmega165p
#TMRCNT2_DEVICES += atmega169
#TMRCNT2_DEVICES += atmega169a
#TMRCNT2_DEVICES += atmega169p
#TMRCNT2_DEVICES += atmega169pa
#TMRCNT2_DEVICES += atmega323
#TMRCNT2_DEVICES += atmega325
#TMRCNT2_DEVICES += atmega325p
#TMRCNT2_DEVICES += atmega329
#TMRCNT2_DEVICES += atmega329p
#TMRCNT2_DEVICES += atmega329pa
#TMRCNT2_DEVICES += atmega406
#TMRCNT2_DEVICES += atmega645
#TMRCNT2_DEVICES += atmega645a
#TMRCNT2_DEVICES += atmega645p
#TMRCNT2_DEVICES += atmega649
#TMRCNT2_DEVICES += atmega649a
#TMRCNT2_DEVICES += atmega649p
#TMRCNT2_DEVICES += atmega1281
#TMRCNT2_DEVICES += atmega2561
#TMRCNT2_DEVICES += atmega3250
#TMRCNT2_DEVICES += atmega3250p
#TMRCNT2_DEVICES += atmega3290
#TMRCNT2_DEVICES += atmega3290p
#TMRCNT2_DEVICES += atmega6450
#TMRCNT2_DEVICES += atmega6450a
#TMRCNT2_DEVICES += atmega6450p
#TMRCNT2_DEVICES += atmega6490
#TMRCNT2_DEVICES += atmega6490a
#TMRCNT2_DEVICES += atmega6490p
#TMRCNT2_DEVICES += atmega8535

TMRCNT2_OBJS=$(TMRCNT2_DEVICES:%=$(OBJDIR)/%/tmrcnt2.o)

TMRCNT2_TARGETS=$(TMRCNT2_DEVICES:%=$(OUTDIR)/%/tmrcnt2.a)

TMRCNT2_OBJDIRS=$(TMRCNT2_DEVICES:%=$(OBJDIR)/%)
TMRCNT2_OUTDIRS=$(TMRCNT2_DEVICES:%=$(OUTDIR)/%)

$(OBJDIR)/%/tmrcnt2.o : tmrcnt2.c tmrcnt2.h
	$(CC) -c -mmcu=$* $(ALL_CFLAGS) $< -o $@

$(OUTDIR)/%/tmrcnt2.a: $(TMRCNT2_OBJS)
	$(AR) $@ $(OBJDIR)/$*/tmrcnt2.o

# Create object files directory
$(shell mkdir -p $(TMRCNT2_OBJDIRS))
$(shell mkdir -p $(TMRCNT2_OUTDIRS))
