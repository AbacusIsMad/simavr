

all: sim runner


.PHONY: sim runner
sim:
	make -C sim AVR_ROOT=/home/ruize/Desktop/avr8-gnu-toolchain-linux_x86_64/bin CFLAGS="-O0 -Wall -Wextra -g -fPIC -lelf -std=gnu99 -Wno-sign-compare -Wno-unused-parameter -DHAVE_LIBELF -DCONFIG_SIMAVR_TRACE=0 -DBIND_AVR_LABELS=AVRBIND_" RELEASE=1 
	make -C sim DESTDIR=${CURDIR}"/result" install

ARCH_FLAGS = -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10819 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR
ARCH_FLAGS_IN = -mmcu=atmega328p\ -DF_CPU=16000000L\ -DARDUINO=10819\ -DARDUINO_AVR_UNO\ -DARDUINO_ARCH_AVR

AVR_ROOT = ./bin
AVR_CC = $(AVR_ROOT)/avr-gcc
AVR_CFLAGS = -O0 -gdwarf-2 -Wall $(ARCH_FLAGS) -Wl,--relax,--gc-sections -ffunction-sections -fdata-sections -Wl,--undefined=_mmcu,--section-start=.mmcu=0x910000
AVR_PKGS = -Iavr/include -Iarduino_lib/include -Lavr/lib ./arduino_lib/lib/core.a

runner: arduino_lib data test_tools

.PHONY: arduino_lib test_tools
arduino_lib:
	make -C arduino_lib ARCH_FLAGS=$(ARCH_FLAGS_IN)

data: main.c vars.S
	$(AVR_CC) -nostdinc $(AVR_CFLAGS) $^ -o main.elf $(AVR_PKGS)

test_tools:
	make -C test_tools

package: all
	#delete the unnecessary files
	make -C arduino_lib package
	tar -cv --to-stdout arduino_lib avr bin lib libexec test_tools.so result | zstd -T0 -22 --ultra --single-thread - > res
	#tar -cv --to-stdout arduino_lib avr bin lib libexec test_tools.so result | ./7za a -si -t7z -m0=lzma -mx=9 -mfb=128 -md=48m -ms=on res.7z
	#zip out.zip -r res.7z begin.sh loader.py main.c
	zip out.zip -r res begin.sh loader.py tester.py main.c vars.S

clean:
	make -C sim clean
	rm -rf result
	rm main.elf $(TEST_LIB) $(TEST_LIB).o $(TEST_LIB).so -f
	rm out.zip res -f 
	make -C arduino_lib clean
	make -C test_tools clean
