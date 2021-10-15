SRCS=$(wildcard *.c)

EXECS=$(SRCS:.c=)

LDLIBS=-lGL -lGLU -lglut -lm

all: $(EXECS)

clean:
	rm -rf $(EXECS) *~
