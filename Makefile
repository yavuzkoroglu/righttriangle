include padkit/compile.mk

INCLUDE_DIRS=-Iinclude -Ipadkit/include
OBJECTS=obj/righttriangle.o obj/triangle.o

all: clean bin/righttriangle

.PHONY: all clean cleanobjects documentation libpadkit objects

bin: ; mkdir bin

bin/righttriangle:                  \
    bin                             \
    libpadkit                       \
    ${OBJECTS}                      \
	; ${COMPILE} ${OBJECTS} padkit/lib/libpadkit.a -o bin/righttriangle

clean: ; rm -rf obj bin *.gcno *.gcda *.gcov html latex

cleanobjects: ; rm -rf obj

documentation: ; doxygen

obj: ; mkdir obj

obj/righttriangle.o:                \
    obj                             \
    include/righttriangle.h         \
    include/triangle.h              \
    padkit/include/padkit/debug.h   \
    padkit/include/padkit/stack.h   \
    src/righttriangle.c             \
    ; ${COMPILE} ${INCLUDE_DIRS} src/righttriangle.c -c -o obj/righttriangle.o

obj/triangle.o:                     \
    obj                             \
    padkit/include/padkit/debug.h   \
    include/triangle.h              \
    src/triangle.c                  \
    ; ${COMPILE} ${INCLUDE_DIRS} src/triangle.c -c -o obj/triangle.o

objects: cleanobjects ${OBJECTS}

libpadkit: ; make -C padkit clean lib/libpadkit.a
