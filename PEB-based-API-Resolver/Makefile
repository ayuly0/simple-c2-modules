CC      := x86_64-w64-mingw32-gcc
CFLAGS  := -Os -fno-asynchronous-unwind-tables -masm=intel -fno-ident -fpack-struct=8 -falign-functions=1 -s -ffunction-sections -fdata-sections -falign-jumps=1 -w -falign-labels=1 -fPIC -Wl,-s,--no-seh,--enable-stdcall-fixup,--gc-sections -mwindows
SRC_DIR := src
BUILD   := build
OUT     := $(BUILD)/PEB-based-API-Resolver.exe

C_SRCS  := $(wildcard $(SRC_DIR)/*.c)
CPP_SRCS:= $(wildcard $(SRC_DIR)/*.cpp)

C_OBJS   := $(patsubst $(SRC_DIR)/%.c, $(BUILD)/%.o, $(C_SRCS))
CPP_OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD)/%.o, $(CPP_SRCS))
OBJS     := $(C_OBJS) $(CPP_OBJS)

.PHONY: all clean
all: $(OUT)

$(OUT): $(OBJS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)
