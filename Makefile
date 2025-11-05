

# generate everything and run it
fullbuild:
	rm -r build/* || true
	cmake -S . -B build
	cmake --build build
	./build/main/data_structures

# update generated project
rebuild:
	cmake --build build
	./build/main/data_structures

# delete build directory
wipe:
	rm -r build/*

# run main executable
run:
	./build/main/data_structures


