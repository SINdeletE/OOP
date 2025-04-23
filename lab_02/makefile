CC := g++

INC_DIR := inc
OUT_DIR := out
SRC_DIR := src

vpath %.cpp $(SRC_DIR)

CFLAGS := -std=c++20 -Wall -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -Wvla -I$(INC_DIR)
LFLAGS := -lm

DEBUG_CFLAGS := -O0 -g

BUILD_SRCS := $(shell find $(SRC_DIR) -type f -regex .*\.cpp -printf "%P\n")
NO_MAIN_BUILD_SRCS := $(shell find $(SRC_DIR) -type f -not -name "*main*" -regex .*\.cpp -printf "%P\n")

BUILD_OBJS := $(foreach OBJ, $(BUILD_SRCS:.cpp=.o), $(OUT_DIR)/$(OBJ))
NO_MAIN_BUILD_OBJS := $(foreach OBJ, $(NO_MAIN_BUILD_SRCS:.cpp=.o), $(OUT_DIR)/$(OBJ))

debug: CFLAGS += $(DEBUG_CFLAGS)

# -----

$(OUT_DIR)/%.o: %.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

# -----

app.exe: out_dir_check | $(BUILD_OBJS)
	$(CC) $(LFLAGS) -o "$@" $(BUILD_OBJS)

.PHONY: debug
debug: out_dir_check | $(BUILD_OBJS)
	$(CC) $(LFLAGS) -o "app.exe" $(BUILD_OBJS) 

# -----

.PHONY: out_dir_check
out_dir_check:
	@if ! [ -d $(OUT_DIR) ]; then mkdir $(OUT_DIR); fi

.PHONY: clean
clean:
	rm -rf out
	rm -rf app.exe
	rm -rf ./*.gcno
	rm -rf ./*.gcda
	rm -rf ./*.cpp.gcov
	rm -f ./func_tests/scripts/*.txt