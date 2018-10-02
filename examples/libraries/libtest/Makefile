SRCS=$(wildcard src/*.c)            # List of all the source files in src.
OBJS=$(SRCS:src/%.c=obj/%.o)        # List of all the object files required
                                    # to produce the static library,
                                    # obtained from the sources list.
OBJSPIC=$(SRCS:src/%.c=obj/%.pic.o) # Same as above but to produce the shared library.

CFLAGS=-I include										# Compilation flags, only required to produce object files.

# Main rule: create libtest libraries in lib/.
all: lib/libtest.a lib/libtest.so

# libtest.a is obtained by linking together object files in OBJS using ar.
lib/libtest.a: $(OBJS)
	$(AR) -cr $@ $^

# Each object file is obtained by compiling a source file.
obj/%.o: src/%.c include/%.h
	$(CC) -c -o $@ $< $(CFLAGS)

# libtest.so is obtained by linking together object files in OBJSPIC using gcc.
lib/libtest.so: $(OBJSPIC)
	$(CC) --shared -o $@ $^

# Each object file is obtained by compiling a source file with the -fPIC compile flag.
obj/%.pic.o: src/%.c include/%.h
	$(CC) -fPIC -c -o $@ $< $(CFLAGS)

# Clean everything.
clean:
	rm -f lib/* obj/*

# .PHONY contains the list of targets which are not files.
.PHONY: all clean
