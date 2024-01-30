GCC = g++
RAYLIB_DIR = D:/Lib/raylib
INCLUDE_FILES = -I ${RAYLIB_DIR}/src/include
CFLAGS = resources.rc.data -Wall -std=c++14 -D_DEFAULT_SOURCE -Wno-missing-braces -static-libgcc -static-libstdc++ -static -Wl,-Bstatic -lpthread -Wl,-R,'assets'
LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm
EXTRAFLAGS = -L ${RAYLIB_DIR}/src/lib -O3 -mwindows

run: build
	./snake-game.exe

resources:
	windres resources.rc -o resources.rc.data --target=pe-x86-64

build:
	${GCC} -o snake-game.exe src/*.cpp ${INCLUDE_FILES} ${CFLAGS} ${LDFLAGS}

release:
	${GCC} -o snake-game.exe src/*.cpp ${INCLUDE_FILES} ${CFLAGS} ${LDFLAGS} ${EXTRAFLAGS}