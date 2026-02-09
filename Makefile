initBuild:
	mkdir -p build && cd build && cmake .. && cmake --build .

build:
	cd build && cmake --build .

run:
	cd build && ./app

.PHONY: initBuild build run