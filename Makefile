

# generate everything and run it
fullbuild:
	@echo -e "-> Wiping build directory"
	@rm -r build/* || true
	@echo -e "\n-> Setting up build files"
	@cmake -S . -B build
	@echo -e "\n-> Compiling project"
	@cmake --build build
	@echo -e "\n-> Running executable"
	@./build/main/data_structures

# update generated project
rebuild:
	@echo -e "-> Compiling project"
	@cmake --build build
	@echo -e "\n-> Running executable"
	@./build/main/data_structures

# delete build directory
wipe:
	@echo -e "-> Wiping build directory"
	@rm -r build/*

# run main executable
run:
	@echo -e "-> Running executable"
	@./build/main/data_structures


