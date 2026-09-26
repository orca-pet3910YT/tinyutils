SRCS := $(wildcard src/*.c)
_OBJS := $(SRCS:.c=.o)
OBJS := $(patsubst src/%.o,build/%,$(_OBJS))

CCFLAGS := -O3 -ffunction-sections -fdata-sections

# Make cleans up .unstripped files on its own.
# I appreciate the enthusiasm, but the command
# is still shown which clutters the output.
# This makes the output look less messy.
.SILENT:

all: $(OBJS)

# Build the C code into unstripped binaries
build/%.unstripped: src/%.c
	@mkdir -p build
	@echo "    CC  $<"; $(PREFIX)gcc $(CCFLAGS) $< -o $@

# Strip them. After this target runs, all .unstripped
# files are deleted by Make itself with no user action
build/%: build/%.unstripped
	@echo " STRIP  $<"; $(PREFIX)strip $< -o $@

# You run this manually
clean:
	@rm -rf build
