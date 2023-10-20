#for separating commands
define \n


endef

AVR_ROOT = ../bin
AVR_INCLUDE = -I../avr/include

SRC_DIR = ./include
ASM_SRC = wiring_pulse.S
GCC_SRC = WInterrupts.c hooks.c wiring.c wiring_digital.c wiring_shift.c wiring_pulse.c wiring_analog.c
G++_SRC = HardwareSerial0.cpp HardwareSerial.cpp CDC.cpp PluggableUSB.cpp HardwareSerial1.cpp HardwareSerial2.cpp IPAddress.cpp HardwareSerial3.cpp Print.cpp Stream.cpp Tone.cpp USBCore.cpp WMath.cpp WString.cpp abi.cpp main.cpp new.cpp

ASM_FLAGS = -nostdinc -c -g -x assembler-with-cpp -flto -MMD $(ARCH_FLAGS) $(AVR_INCLUDE)
GCC_FLAGS = -nostdinc -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects $(ARCH_FLAGS) $(AVR_INCLUDE)
G++_FLAGS = -nostdinc -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto $(ARCH_FLAGS) $(AVR_INCLUDE)

TARGET_DIR = ./lib
TARGET = $(TARGET_DIR)/core.a

ASM_TARGET = $(foreach item,$(ASM_SRC),$(item).o)
GCC_TARGET = $(foreach item,$(GCC_SRC),$(item).o)
G++_TARGET = $(foreach item,$(G++_SRC),$(item).o)

all: $(TARGET)

package:
	rm -f *.S.o *.S.d *.c.o *.c.d *.cpp.o *.cpp.d

clean: package
	rm -f $(TARGET_DIR)/*

list_targets:
	@echo $(TARGET)
	@echo $(ASM_TARGET)
	@echo $(GCC_TARGET)
	@echo $(G++_TARGET)

$(TARGET): $(ASM_TARGET) $(GCC_TARGET) $(G++_TARGET)
	$(foreach item,$(ASM_TARGET), $(AVR_ROOT)/avr-gcc-ar rcs $(TARGET) $(item)${\n})
	$(foreach item,$(GCC_TARGET), $(AVR_ROOT)/avr-gcc-ar rcs $(TARGET) $(item)${\n})
	$(foreach item,$(G++_TARGET), $(AVR_ROOT)/avr-gcc-ar rcs $(TARGET) $(item)${\n})

%.S.o: $(SRC_DIR)/%.S
	$(AVR_ROOT)/avr-gcc $(ASM_FLAGS) $< -o $@

%.c.o: $(SRC_DIR)/%.c
	$(AVR_ROOT)/avr-gcc $(GCC_FLAGS) $< -o $@

%.cpp.o: $(SRC_DIR)/%.cpp
	$(AVR_ROOT)/avr-g++ $(G++_FLAGS) $< -o $@
