

# supress dialogue from recursive calls
MAKEFLAGS += --no-print-directory

# generate everything and run it
fullbuild:
	@make wipe
	@make p_setup
	@make p_compile
	@make run

# update generated project
rebuild:
	@make p_compile
	@make run

# delete build directory
wipe:
	@echo -e "\n-> Wiping build directory"
	@rm -r build/* || true

# run main executable
run:
	@echo -e "\n-> Running executable"
	@./build/main/data_structures

## PRIVATE

# private function to create build structure
p_setup:
	@echo -e "\n-> Setting up build files"
	@cmake -S . -B build

# private function to compile
p_compile:
	@echo -e "\n-> Compiling project"
	@cmake --build build


