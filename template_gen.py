#!/usr/bin/env python3
"""
Usage:
  python gen_template.py <project_name> <program_name> "<description>"

This script creates:
- <project_name>/
  - README.md
  - Makefile
  - src/<program_name>.cpp
"""

import os
import sys
import textwrap


def make_dirs(path):
    os.makedirs(path, exist_ok=True)
    print(f"Created/verified: {path}")


def write_file(path, content):
    with open(path, "w", encoding="utf-8") as f:
        f.write(content)
    print(f"Generated: {path}")


def main():
    if len(sys.argv) != 4:
        print(
            'Usage: python gen_template.py <project_name> <program_name> "<description>"'
        )
        sys.exit(1)

    proj, prog, desc = sys.argv[1], sys.argv[2], sys.argv[3]

    root = os.path.abspath(proj)
    src = os.path.join(root, "src")
    main_cpp = os.path.join(src, f"{prog}.cpp")
    makefile = os.path.join(root, "Makefile")
    readme = os.path.join(root, "README.md")

    # 1. Create directories
    for d in [root, src]:
        make_dirs(d)

    # 2. Write CMakeLists.txt
    cmk = textwrap.dedent(
        f"""\
		CC      := x86_64-w64-mingw32-gcc
		CFLAGS  := -O2 -Wall
		SRC_DIR := src
		BUILD   := build
		OUT     := $(BUILD)/{prog}.exe

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
    """
    )
    write_file(makefile, cmk)

    # 3. Write README.md
    md = textwrap.dedent(
        f"""\
        # {proj}

        {desc}

        ## Build & Run

        ```bash
        mkdir build && cd build
        make
        .\\build\\{prog}.exe
        ```

        ## Description

        `{prog}` is the core executable of the `{proj}` project.
    """
    )
    write_file(readme, md)

    # 4. Write minimal main.cpp
    cpp = textwrap.dedent(
        f"""\
        #include <iostream>

        int main() {{
            std::cout << "Hello from {prog}!" << std::endl;
            return 0;
        }}
    """
    )
    write_file(main_cpp, cpp)

    print("\n✅ Template generation complete!")
    print(f"Project ready in: {root}")


if __name__ == "__main__":
    main()
