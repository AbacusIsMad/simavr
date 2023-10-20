This is designed for the GNU x86_64 system, the same one as EdStem.

# Build + "Install"
you can download `out.zip` or build it yourself from `make clean package`.
Drag the zip file to the EdStem workspace. it should extract itself.
Every time you need to run/test a program, you should do:
```
source begin.sh #to extract avr-gcc and other libraries
make #to compile changes in the source code
python3 tester.py #to run tests.
```

