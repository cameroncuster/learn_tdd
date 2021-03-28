SOURCE = cube.cpp \
		 ellipsoid.cpp \
		 main.cpp \
		 point.cpp \
		 prism.cpp \
		 shape3d.cpp \
		 sphere.cpp

TESTS_OBJS = cube.cpp \
			cubeTest.cpp \
			cubeTestCasesCam.cpp \
			ellipsoid.cpp \
			ellipsoidTest.cpp \
			ellipsoidTestCasesCam.cpp \
			point.cpp \
			pointTest.cpp \
			pointTestCasesCam.cpp \
			prism.cpp \
			prismTest.cpp \
			prismTestCasesCam.cpp \
			shape3d.cpp \
			shape3dTest.cpp \
			sphere.cpp \
			sphereTest.cpp \
			sphereTestCasesCam.cpp \
			unitTestTools.cpp \
			testMain.cpp

OBJS = $(SOURCE:.cpp=.o)

#GNU C/C++ Compiler
GCC = g++

# GNU C/C++ Linker
LINK = g++

# Compiler flags
CFLAGS =
CXXFLAGS = $(CFLAGS)

# Fill in special libraries needed here
LIBS =

.PHONY: clean

# Targets include all, tests, clean, debug, tar

all : main

main: $(OBJS)
	$(LINK) -o $@ $^ $(LIBS)

tests: $(TESTS_OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
	rm -rf *.o *.d core main tests

debug: CXXFLAGS = -DDEBUG -g -std=c++11
debug: main

tar: clean
	tar zcvf main.tgz $(SOURCE) *.h Makefile

help:
	@echo "	make main       - same as make all"
	@echo "	make all        - builds the main target"
	@echo " make tests      - builds complete test suite"
	@echo "	make            - same as make all"
	@echo "	make clean      - remove .o .d core main tests-cam tests-ray"
	@echo "	make debug      - make all with -g and -DDEBUG"
	@echo "	make tar        - make a tarball of .cpp and .h files"
	@echo "	make help       - this message"

-include $(SOURCE:.cpp=.d)

%.d: %.cpp
	@set -e; rm -rf $@;$(GCC) -MM $< $(CXXFLAGS) > $@
