# Makefile to build posit vs float demo

CXX = g++
CXXFLAGS = -std=c++17

SRC_DIR = src
OUT_DIR = out
INCLUDE_DIRS = -I./soft-posit-cpp/include -I./eigen
LIB_DIR = -L./libs
LIBS = -lsoftposit

SRC = $(SRC_DIR)/posit_vs_float.cpp
TARGET = $(OUT_DIR)/posit_vs_float

.PHONY: all test clean

# Always rebuild on 'make'
all:
	@mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) $(LIB_DIR) $(SRC) -o $(TARGET) $(LIBS)

# Run only the binary (no rebuild)
demo:
	LD_LIBRARY_PATH=./libs ./$(TARGET)

clean:
	@rm -rf $(OUT_DIR)
