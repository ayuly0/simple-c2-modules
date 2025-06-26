CC = x86_64-w64-mingw32-g++
CFLAGS = -O2 -Wall
SRC = src/PEB-based-API-Resolver.cpp
OUT = build/PEB-based-API-Resolver.exe

all: $(OUT)

$(OUT): $(SRC)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf build/
