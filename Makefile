include padkit/compile.mk

INCLUDES=-Iinclude -Ipadkit/include
OBJECTS=obj/righttriangle.o obj/triangle.o

all: clean bin/righttriangle

.PHONY: all clean cleanobjects documentation libpadkit objects

bin: ; mkdir bin

bin/righttriangle:                      \
    bin                                 \
    ${OBJECTS}                          \
    padkit/lib/libpadkit.a              \
	; ${COMPILE} ${OBJECTS} padkit/lib/libpadkit.a -o bin/righttriangle

clean: ; rm -rf obj bin *.gcno *.gcda *.gcov html latex

cleanobjects: ; rm -rf obj

documentation: ; doxygen

obj: ; mkdir obj

obj/righttriangle.o: obj           		\
    include/righttriangle.h             \
    include/triangle.h                	\
    libpadkit                           \
    src/righttriangle.c                 \
    ; ${COMPILE} ${INCLUDES} src/righttriangle.c -c -o obj/righttriangle.o

obj/triangle.o: obj           			\
    padkit/include/padkit/debug.h       \
    include/triangle.h                	\
    src/triangle.c                    	\
    ; ${COMPILE} ${INCLUDES} src/triangle.c -c -o obj/triangle.o

objects: cleanobjects ${OBJECTS}

libpadkit: ; make -C padkit clean lib/libpadkit.a
