CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -Werror -O2
PYTHON ?= python3
CLANG_FORMAT ?= clang-format-18
SOURCES := $(sort $(wildcard lab*/main.c))
HEADERS := $(wildcard include/*.h)
HARNESS := $(wildcard tests/harnesses/*.c)
BINS := $(patsubst %/main.c,build/%,$(SOURCES))

.PHONY: all test sanitize format format-check clean
all: $(BINS)

build/%: %/main.c $(HEADERS)
	@mkdir -p build
	$(CC) $(CFLAGS) $< -o $@

test:
	CC="$(CC)" CFLAGS="$(CFLAGS)" $(PYTHON) tests/test_labs.py

sanitize:
	$(MAKE) test CFLAGS="$(CFLAGS) -fsanitize=address,undefined -fno-sanitize-recover=all -fno-omit-frame-pointer -g"

format:
	$(CLANG_FORMAT) -i $(SOURCES) $(HEADERS) $(HARNESS)

format-check:
	$(CLANG_FORMAT) --dry-run --Werror $(SOURCES) $(HEADERS) $(HARNESS)

clean:
	rm -rf build
