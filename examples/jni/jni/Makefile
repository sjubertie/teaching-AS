SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:src/%.c=obj/%.o)

CFLAGS=-I include -I /usr/lib/jvm/java-1.8.0-openjdk-amd64/include/ -I /usr/lib/jvm/java-1.8.0-openjdk-amd64/include/linux

../lib/libtest.so: $(OBJS)
	$(CC) -shared -o $@ $^

obj/%.o: src/%.c include/%.h
	$(CC) -fPIC -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -rf obj/*
