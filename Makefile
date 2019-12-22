CFLAGS = -std=c++17 -Wall -Wextra -Iext/SDL/include -Iext/stbimage -Iext/glad/include 
LDFLAGS = `pkg-config --static --libs glfw3` -lGL -lassimp -lSDL2 -lSDL2_image -lpthread -lboost_system -lboost_filesystem

SOURCES = $(shell find pbrrenderer -name "*.cpp") ext/glad/src/glad.c
pbrrenderer_top = pbrrenderer
pbr_main = $(pbrrenderer_top)/pbr
pbr_core = $(pbrrenderer_main)/core
pbr_ui = $(pbrrenderer_main)/pbr_ui
pbr_util = $(pbrrenderer_main)/pbr_util
pbr_util_flags = $(pbr_util)/flags
pbr_util_io = $(pbr_util)/io
pbr_util_initializers = $(pbr_util)/initializers

COMPONENTS = $(pbr_main) $(pbr_core) $(pbr_ui) $(pbr_util) $(pbr_util_flags) $(pbr_util_io) $(pbr_util_initializers)

.PHONY: all install run debug clean

pbrrenderer-base: $(SOURCES)
	@$(CXX) $(CFLAGS) -o "bin/Linux/x64/pbr" $(SOURCES) $(LDFLAGS)

all: pbrrenderer-base

install:
	@sudo ./INSTALL.sh

run: pbrrenderer-base
	@cp "bin/Linux/x64/pbr" "pbr"
	@./pbr &

debug: pbrrenderer-base
	@cp "bin/Linux/x64/pbr" "pbr"
	@gdb -ex run pbr

clean:
	@rm -f "pbr" "bin/Linux/x64/pbr"