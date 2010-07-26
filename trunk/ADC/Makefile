# Hey Emacs, this is a -*- makefile -*-

TARGET_LIST = at90can32 \
at90can64 \
at90can128 \
at90pwm1 \
at90pwm2 \
at90pwm2B \
at90pwm3 \
at90pwm3B \
at90pwm81 \
at90pwm216 \
at90pwm316 \
at90usb82 \
at90usb162 \
at90usb646 \
at90usb647 \
at90usb1286 \
at90usb1287 \
atmega8 \
atmega8hva \
atmega8u2 \
atmega16 \
atmega16a \
atmega16hva \
atmega16hva2 \
atmega16hvb \
atmega16m1 \
atmega16u2 \
atmega16u4 \
atmega32 \
atmega32c1 \
atmega32hvb \
atmega32m1 \
atmega32u2 \
atmega32u4 \
atmega32u6 \
atmega48 \
atmega48a \
atmega48p \
atmega64 \
atmega64c1 \
atmega64hve \
atmega64m1 \
atmega88 \
atmega88a \
atmega88p \
atmega88pa \
atmega103 \
atmega128 \
atmega161 \
atmega162 \
atmega163 \
atmega164p \
atmega164a \
atmega165 \
atmega165a \
atmega165p \
atmega168 \
atmega168a \
atmega168p \
atmega169 \
atmega169a \
atmega169p \
atmega169pa \
atmega323 \
atmega324p \
atmega324a \
atmega324pa \
atmega325 \
atmega325a \
atmega325p \
atmega328p \
atmega328 \
atmega329 \
atmega329a \
atmega329p \
atmega329pa \
atmega406 \
atmega640 \
atmega644 \
atmega644a \
atmega644p \
atmega644pa \
atmega645 \
atmega645a \
atmega645p \
atmega649 \
atmega649a \
atmega649p \
atmega1280 \
atmega1281 \
atmega1284p \
atmega128RFA1 \
atmega2560 \
atmega2561 \
atmega3250 \
atmega3250a \
atmega3250p \
atmega3290 \
atmega3290a \
atmega3290p \
atmega6450 \
atmega6450a \
atmega6450p \
atmega6490 \
atmega6490a \
atmega6490p \
atmega8515 \
atmega8535 \
attiny4 \
attiny5 \
attiny9 \
attiny10 \
attiny13 \
attiny13a \
attiny20 \
attiny22 \
attiny24 \
attiny24a \
attiny25 \
attiny26 \
attiny40 \
attiny43u \
attiny44 \
attiny44a \
attiny45 \
attiny48 \
attiny84 \
attiny84a \
attiny85 \
attiny88 \
attiny87 \
attiny167 \
attiny261 \
attiny261a \
attiny461 \
attiny461a \
attiny861 \
attiny861a \
attiny2313 \
attiny2313a \
attiny4313


# Optimization level, can be [0, 1, 2, 3, s]. 
#     0 = turn off optimization. s = optimize for size.
#     (Note: 3 is not always the best optimization level. See avr-libc FAQ.)
OPT = s


# Debugging format.
#     Native formats for AVR-GCC's -g are dwarf-2 [default] or stabs.
#     AVR Studio 4.10 requires dwarf-2.
#     AVR [Extended] COFF format requires stabs, plus an avr-objcopy run.
DEBUG = dwarf-2

# Compiler flag to set the C Standard level.
#     c89   = "ANSI" C
#     gnu89 = c89 plus GCC extensions
#     c99   = ISO C99 standard (not yet fully implemented)
#     gnu99 = c99 plus GCC extensions
CSTANDARD = -std=gnu99


#---------------- Compiler Options C ----------------
#  -g*:          generate debugging information
#  -O*:          optimization level
#  -f...:        tuning, see GCC manual and avr-libc documentation
#  -Wall...:     warning level
#  -Wa,...:      tell GCC to pass this to the assembler.
#    -adhlns...: create assembler listing
CFLAGS = -g$(DEBUG)
CFLAGS += -O$(OPT)
CFLAGS += -funsigned-char
CFLAGS += -funsigned-bitfields
CFLAGS += -fpack-struct
CFLAGS += -fshort-enums
CFLAGS += -Wall
CFLAGS += -Wstrict-prototypes
#CFLAGS += -mshort-calls
#CFLAGS += -fno-unit-at-a-time
#CFLAGS += -Wundef
#CFLAGS += -Wunreachable-code
#CFLAGS += -Wsign-compare
CFLAGS += $(CSTANDARD)

# Define programs and commands.
SHELL = sh
CC = avr-gcc
SIZE = avr-size
AR = avr-ar rcs

ALL_CFLAGS = -mmcu=$(MCU) -I. $(CFLAGS) $(GENDEPFLAGS)


all: $(TARGET_LIST)
	@echo Making all

$(TARGET_LIST):
	@echo "Making:" $@
	@mkdir -p ../deliver/$@/lib
	@mkdir -p ../deliver/$@/include
	@mkdir -p ../deliver/$@/obj
	@$(CC) -c -mmcu=$@ -I. $(CFLAGS) adc.c -o ../deliver/$@/obj/adc.o >> /tmp/avr-dvr-adc.log
	@$(AR) ../deliver/$@/lib/libadc.a ../deliver/$@/obj/adc.o
	@cp adc.h ../deliver/$@/include


