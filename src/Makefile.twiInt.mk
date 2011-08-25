# Hey Emacs, this is a -*- makefile -*-

TWIINT_DEVICES = at90can32
TWIINT_DEVICES += at90can64
TWIINT_DEVICES += at90can128
TWIINT_DEVICES += at90usb646
TWIINT_DEVICES += at90usb647
TWIINT_DEVICES += at90usb1286
TWIINT_DEVICES += at90usb1287
TWIINT_DEVICES += atmega16
TWIINT_DEVICES += atmega16a
TWIINT_DEVICES += atmega32
TWIINT_DEVICES += atmega32u4
TWIINT_DEVICES += atmega32u6
TWIINT_DEVICES += atmega48
TWIINT_DEVICES += atmega48a
TWIINT_DEVICES += atmega48p
TWIINT_DEVICES += atmega64
TWIINT_DEVICES += atmega88
TWIINT_DEVICES += atmega88a
TWIINT_DEVICES += atmega88p
TWIINT_DEVICES += atmega88pa
TWIINT_DEVICES += atmega128
TWIINT_DEVICES += atmega128rfa1
TWIINT_DEVICES += atmega164p
TWIINT_DEVICES += atmega164a
TWIINT_DEVICES += atmega168
TWIINT_DEVICES += atmega168a
TWIINT_DEVICES += atmega168p
TWIINT_DEVICES += atmega324p
TWIINT_DEVICES += atmega324a
TWIINT_DEVICES += atmega324pa
TWIINT_DEVICES += atmega328
TWIINT_DEVICES += atmega328p
TWIINT_DEVICES += atmega640
TWIINT_DEVICES += atmega644
TWIINT_DEVICES += atmega644a
TWIINT_DEVICES += atmega644p
TWIINT_DEVICES += atmega644pa
TWIINT_DEVICES += atmega1280
TWIINT_DEVICES += atmega1281
TWIINT_DEVICES += atmega1284p
TWIINT_DEVICES += atmega2560
TWIINT_DEVICES += atmega2561
TWIINT_DEVICES += attiny48
TWIINT_DEVICES += attiny88

#broken
#TWIINT_DEVICES += atmega8
#TWIINT_DEVICES += atmega16hvb
#TWIINT_DEVICES += atmega32hvb
#TWIINT_DEVICES += atmega163
#TWIINT_DEVICES += atmega323
#TWIINT_DEVICES += atmega406

TWIINT_OBJS=$(TWIINT_DEVICES:%=$(OBJDIR)/%/twiInt.o)

TWIINT_TARGETS=$(TWIINT_DEVICES:%=$(OUTDIR_LIB)/%/libtwiInt.a)

TWIINT_OBJDIRS=$(TWIINT_DEVICES:%=$(OBJDIR)/%)
TWIINT_OUTDIRS=$(TWIINT_DEVICES:%=$(OUTDIR_LIB)/%)

TWIINT_HEADER = $(OUTDIR_HEADER)/twiInt.h

$(OBJDIR)/%/twiInt.o : twiInt.c twiInt.h
	$(CC) -c -mmcu=$* $(ALL_CFLAGS) $< -o $@

$(OUTDIR_LIB)/%/libtwiInt.a: $(TWIINT_OBJS)
	$(AR) $@ $(OBJDIR)/$*/twiInt.o

# Create object files directory
$(shell mkdir -p $(TWIINT_OBJDIRS))
$(shell mkdir -p $(TWIINT_OUTDIRS))
