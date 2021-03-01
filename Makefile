# dataStructures Makefile

# libs
LIBS = gtest
LIBS += pthread # required for gtest

# avoid any issues w/ shell inheritance
SHELL = /bin/sh

# includes
INCV = ./inc
INCV += /usr/local/include

CC = g++
CFLAGS = -Wall -O2 -std=c++11 -g
CFLAGS += $(foreach inc, $(INCV), -iquote $(inc))
LDFLAGS = -L /usr/local/lib
LDFLAGS += $(foreach name, $(LIBS), -l $(name))

# libs
LIB_PATH = ./lib
CPP_LIB_SRC = $(realpath $(wildcard $(LIB_PATH)/*.cc)) # match *.cpp

# gtest fixtures
SRC_PATH = ./src
SRC_TESTS_PATH = $(SRC_PATH)/tests
CPP_LIB_SRC += $(realpath $(wildcard $(SRC_PATH)/*.cc)) # match *.cpp
CPP_LIB_SRC += $(realpath $(wildcard $(SRC_TESTS_PATH)/*.cc)) # match *.cpp

BUILD_PATH = ./build
TARGET = ./bin/tests
main: GTEST_MAIN = ./main.cc
gtest: GTEST_MAIN = ./tests.cc
GTEST_OBJ = $(BUILD_PATH)/$(patsubst %.cc,%.o,$(notdir $(GTEST_MAIN)))

# create list of objects
OBJECTS = $(foreach obj,$(basename $(notdir $(CPP_LIB_SRC))), $(BUILD_PATH)/$(obj).o)

# dirs to be created & also cleaned
CREATE_DIRS = $(dir $(TARGET))
CREATE_DIRS += $(BUILD_PATH)

.PHONY: clean main $(TARGET) $(CREATE_DIRS) $(OBJECTS) $(CPP_LIB_SRC)

main: $(TARGET)
gtest: $(TARGET)

$(TARGET): $(CREATE_DIRS) $(CPP_LIB_SRC)
	# build main test object
	$(CC) $(CFLAGS) -c $(GTEST_MAIN) -o $(GTEST_OBJ)

	# build main test
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(GTEST_OBJ) $(LDFLAGS)

# create dirs
$(CREATE_DIRS):
	mkdir -p $@

$(CPP_LIB_SRC):
	$(CC) $(CFLAGS) -c $@ -o $(BUILD_PATH)/$(patsubst %.cc,%.o,$(notdir $@))

clean:
	rm -r $(CREATE_DIRS)