#use -DFANCY_UART to have cool output
make clean
make AVR_ROOT=/home/ruize/Desktop/avr8-gnu-toolchain-linux_x86_64/bin CFLAGS="-O0 -Wall -Wextra -g -fPIC -lelf \
-std=gnu99 -Wno-sign-compare -Wno-unused-parameter -DHAVE_LIBELF" RELEASE=1
make DESTDIR="./result/" install
