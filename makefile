

all: sim runner


.PHONY: sim runner
sim:
	make -C sim AVR_ROOT=/home/ruize/Desktop/avr8-gnu-toolchain-linux_x86_64/bin CFLAGS="-O0 -Wall -Wextra -g -fPIC -lelf -std=gnu99 -Wno-sign-compare -Wno-unused-parameter -DHAVE_LIBELF -DCONFIG_SIMAVR_TRACE=0" RELEASE=1 
	make -C sim DESTDIR=${CURDIR}"/result" install

ARCH_FLAGS = -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10819 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR
ARCH_FLAGS_IN = -mmcu=atmega328p\ -DF_CPU=16000000L\ -DARDUINO=10819\ -DARDUINO_AVR_UNO\ -DARDUINO_ARCH_AVR

AVR_ROOT = ./bin
AVR_CC = $(AVR_ROOT)/avr-gcc
AVR_CFLAGS = -Os -gdwarf-2 -Wall $(ARCH_FLAGS) -Wl,--relax,--gc-sections -ffunction-sections -fdata-sections -Wl,--undefined=_mmcu,--section-start=.mmcu=0x910000
AVR_PKGS = -Iavr/include -Iarduino_lib/include -Lavr/lib ./arduino_lib/lib/core.a

TEST_CC = gcc
TEST_CFLAGS = -Os -Wall
TEST_PKGS = -Iresult/include/simavr -Lresult/lib -lsimavr -lelf

runner: arduino_lib data test

.PHONY: arduino_lib
arduino_lib:
	make -C arduino_lib ARCH_FLAGS=$(ARCH_FLAGS_IN)

data: main.cpp
	$(AVR_CC) -nostdinc $(AVR_CFLAGS) $< -o main.elf $(AVR_PKGS)

test: test.c
	export LD_LIBRARY_PATH=./result/lib/ #this doesn't work
	$(TEST_CC) $(TEST_CFLAGS) test.c -o test $(TEST_PKGS)
	$(TEST_CC) $(TEST_CFLAGS) -c -fPIC test.c -o test.o $(TEST_PKGS)
	$(TEST_CC) -shared test.o -o test.so $(TEST_PKGS)

package: all
	#delete the unnecessary files
	make -C arduino_lib package
	tar -cvz --to-stdout arduino_lib avr bin lib | xz -9 - -c > res
	zip out.zip -r res result begin.sh test.so load.py

clean:
	make -C sim clean
	rm -rf result
	rm main.elf test test.o test.so -f
	rm out.zip res -f 
	make -C arduino_lib clean
