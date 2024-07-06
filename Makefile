include padkit/compile.mk

INCLUDES=-Iinclude -Ipadkit/include
OBJECTS=obj/righttriangle.o obj/triangle.o

all: objects

.PHONY: all clean cleanobjects cleanpadkit documentation objects

bin: ; mkdir bin

clean: ; rm -rf obj bin padkit *.gcno *.gcda *.gcov html latex

cleanlibpadkit: ; rm -rf padkit/obj padkit/lib/libpadkit.a

cleanobjects: ; rm -rf obj

documentation: ; doxygen

obj: ; mkdir obj

obj/righttriangle.o: obj           		\
    padkit/include/padkit/debug.h       \
    include/righttriangle.h             \
    include/triangle.h                	\
    src/triangle.c                    	\
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
