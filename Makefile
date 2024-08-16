include padkit/compile.mk

INCLUDES=-Iinclude -Ipadkit/include
OBJECTS=obj/righttriangle.o obj/triangle.o

all: bin/righttriangle

.PHONY: all clean cleanobjects cleanpadkit documentation objects

bin: ; mkdir bin

bin/righttriangle:                      \
    bin                                 \
    objects                             \
    padkit/compile.mk                   \
    padkit/lib/libpadkit.a              \
	; ${COMPILE} ${OBJECTS} padkit/lib/libpadkit.a -o bin/righttriangle

clean: ; rm -rf obj bin padkit *.gcno *.gcda *.gcov html latex

cleanlibpadkit: ; rm -rf padkit/obj padkit/lib/libpadkit.a

cleanobjects: ; rm -rf obj

documentation: ; doxygen

obj: ; mkdir obj

obj/righttriangle.o: obj           		\
    padkit/include/padkit/debug.h       \
    padkit/include/padkit/memalloc.h    \
    padkit/include/padkit/reallocate.h  \
    padkit/include/padkit/stack.h       \
    include/righttriangle.h             \
    include/triangle.h                	\
    src/righttriangle.c                 \
    ; ${COMPILE} ${INCLUDES} src/righttriangle.c -c -o obj/righttriangle.o

obj/triangle.o: obj           			\
    padkit/include/padkit/debug.h       \
    include/triangle.h                	\
    src/triangle.c                    	\
    ; ${COMPILE} ${INCLUDES} src/triangle.c -c -o obj/triangle.o

objects: cleanobjects ${OBJECTS}

padkit: ; git clone https://github.com/yavuzkoroglu/padkit.git

padkit/compile.mk: padkit; $(make padkit/compile.mk)

padkit/include/padkit.h: padkit; make -C padkit include/padkit.h

padkit/lib/libpadkit.a: cleanlibpadkit padkit; make -C padkit lib/libpadkit.a
