# Compilation flags.
CFLAGS=-I ../libtest/include
# List of libraries.
LDLIBS=-ltest
# Linking flags.
LDFLAGS=-L ../libtest/lib

BINS=bin/main-static bin/main-dynamic bin/main-plugin

.PHONY: all clean run

all: $(BINS)

bin/main-static: obj/main.o
	$(CC) -o $@ $< ../libtest/lib/libtest.a

obj/main.o: src/main.c
	$(CC) -c -o $@ $< $(CFLAGS)

bin/main-dynamic: obj/main.o
	$(CC) -o $@ $< $(LDFLAGS) $(LDLIBS)
	
bin/main-plugin: obj/main-plugin.o
	$(CC) -rdynamic -o $@ $< -ldl
	
obj/main-plugin.o: src/main-plugin.c
	$(CC) -c -o $@ $< $(CFLAGS)

run: $(BINS)
	@echo "Static version:"
	./bin/main-static
	@echo "Dynamic version:"
	LD_LIBRARY_PATH=../libtest/lib ./bin/main-dynamic
	@echo "Plugin version:"
	LD_LIBRARY_PATH=../libtest/lib ./bin/main-plugin
clean:
	rm -f bin/* obj/*
