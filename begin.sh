#the path avr-gcc and friends will be extracted to
EXTRACT_PATH=/tmp/sim_tools

rm -rf $EXTRACT_PATH
mkdir $EXTRACT_PATH

#extract to there
#xz res -d -c | tar -xzf - -C $EXTRACT_PATH
zstd --decompress --stdout res | tar -xf - -C $EXTRACT_PATH

export LD_LIBRARY_PATH=$EXTRACT_PATH/result/lib:$EXTRACT_PATH:.

#write the makefile
cat << EOF > makefile
AVR_ROOT = $EXTRACT_PATH/bin
AVR_CC = avr-gcc
#WARNING: using avr-g++ is not recommended due to name mangling
#AVR_CC = avr-g++

ARCH_FLAGS = -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10819 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR
AVR_CFLAGS = -gdwarf-2 -Wall \$(ARCH_FLAGS) -Wl,--relax,--gc-sections -ffunction-sections -fdata-sections -Wl,--undefined=_mmcu,--section-start=.mmcu=0x910000

AVR_PKGS = -I$EXTRACT_PATH -I$EXTRACT_PATH/avr/include -I$EXTRACT_PATH/arduino_lib/include -L$EXTRACT_PATH/avr/lib

SRC = \$(filter-out main.c, \$(wildcard *.c)) \$(wildcard *.S)

all: \$(SRC) main.o
	\$(AVR_ROOT)/\$(AVR_CC) -nostdinc $^ -o main.elf -O0 \$(AVR_CFLAGS) \$(AVR_PKGS) $EXTRACT_PATH/arduino_lib/lib/core.a

main.o: main.c
	\$(AVR_ROOT)/\$(AVR_CC) -nostdinc -Os \$(AVR_CFLAGS) \$(AVR_PKGS) -c $< -o \$@

EOF
