include padkit/compile.mk

INCLUDE_DIRS=-Iinclude -Ipadkit/include
OBJECTS=obj/righttriangle.o obj/triangle.o

default: bin/righttriangle

.FORCE:

.PHONY: .FORCE clean

bin: ; mkdir bin

bin/righttriangle: .FORCE           \
    bin                             \
    padkit/lib/libpadkit.a          \
    ${OBJECTS}                      \
	; ${COMPILE} ${OBJECTS} padkit/lib/libpadkit.a -o bin/righttriangle

clean: ; rm -rf obj bin *.gcno *.gcda *.gcov html latex

obj: ; mkdir obj

obj/righttriangle.o: .FORCE         \
    obj                             \
    include/righttriangle.h         \
    include/triangle.h              \
    padkit/include/padkit/stack.h   \
    src/righttriangle.c             \
    ; ${COMPILE} ${INCLUDE_DIRS} src/righttriangle.c -c -o obj/righttriangle.o

obj/triangle.o: .FORCE              \
    obj                             \
    include/triangle.h              \
    padkit/include/padkit/overlap.h \
    src/triangle.c                  \
    ; ${COMPILE} ${INCLUDE_DIRS} src/triangle.c -c -o obj/triangle.o

padkit/lib/libpadkit.a: .FORCE      \
    ; make -C padkit clean lib/libpadkit.a
