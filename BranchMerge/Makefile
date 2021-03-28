SOURCE = cube.cpp \
		 ellipsoid.cpp \
		 main.cpp \
		 point.cpp \
		 prism.cpp \
		 shape3d.cpp \
		 sphere.cpp

SOURCE_APPROXIMATE_SPHERE = ApproximateSphere.cpp \
							shape3d.cpp \
							point.cpp \
							sphere.cpp

SOURCE_APPROXIMATE_ELLIPSOID = ApproximateEllipsoid.cpp \
							   shape3d.cpp \
							   point.cpp \
							   ellipsoid.cpp

SOURCE_TEST = testMain.cpp \
			  unitTestTools.cpp \
			  testCasesBaseClass.cpp \
			  testCasesPoint.cpp \
			  testCasesCube.cpp \
			  testCasesPrism.cpp \
			  testCasesSphere.cpp \
			  testCasesEllipsoid.cpp \
			  shape3d.cpp \
			  shape3dTest.cpp \
			  cube.cpp \
			  cubeTest.cpp \
			  ellipsoid.cpp \
			  point.cpp \
			  pointTest.cpp \
			  prism.cpp \
			  sphere.cpp

OBJS = $(SOURCE:.cpp=.o)

APPROX_SPHERE_OBJS = $(SOURCE_APPROXIMATE_SPHERE:.cpp=.o)

APPROX_ELLIPSOID_OBJS = $(SOURCE_APPROXIMATE_ELLIPSOID:.cpp=.o)

TEST_OBJS = $(SOURCE_TEST:.cpp=.o)

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

# Targets include all, approxSphere, approxEllipsoid, tests, clean, debug, tar

all : main

main: $(OBJS)
	$(LINK) -o $@ $^ $(LIBS)

approxSphere: $(APPROX_SPHERE_OBJS)
	$(LINK) -o $@ $^ $(LIBS)

approxEllipsoid: $(APPROX_ELLIPSOID_OBJS)
	$(LINK) -o $@ $^ $(LIBS)

tests: $(TEST_OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
	rm -rf *.o *.d core main approxSphere approxEllipsoid tests

debug: CXXFLAGS = -DDEBUG -g -std=c++11
debug: main

tar: clean
	tar zcvf main.tgz $(SOURCE) *.h Makefile

help:
	@echo "	make main            - same as make all"
	@echo "	make all             - builds the main target"
	@echo "	make approxSphere    - builds the approximate sphere target"
	@echo "	make approxEllipsoid - builds the approximate ellipsoid target"
	@echo "	make tests           - builds complete test suite"
	@echo "	make                 - same as make all"
	@echo "	make clean           - remove .o .d core main tests-cam tests-ray"
	@echo "	make debug           - make all with -g and -DDEBUG"
	@echo "	make tar             - make a tarball of .cpp and .h files"
	@echo "	make help            - this message"

-include $(SOURCE:.cpp=.d)

%.d: %.cpp
	@set -e; rm -rf $@;$(GCC) -MM $< $(CXXFLAGS) > $@
