

# supress dialogue from recursive calls
MAKEFLAGS += --no-print-directory

# generate everything and run it
fullbuild:
	@$(MAKE) wipe
	@$(MAKE) p_setup
	@$(MAKE) p_compile
	@$(MAKE) test
	@$(MAKE) run

# update generated project
rebuild:
	@$(MAKE) p_compile
	@$(MAKE) test
	@$(MAKE) run

# delete build directory
wipe:
	@echo -e "\n-> Wiping build directory"
	@rm -r build/* || true

# run tests
test:
	@echo -e "\n-> Running tests"
	@cd build && ctest --output-on-failure
	@cd ../

# run main executable
run:
	@echo -e "\n-> Running executable"
	@./build/main/data_structures

## PRIVATE

# private function to create build structure
p_setup:
	@echo -e "\n-> Setting up build files"
	@c$(MAKE) -S . -B build

# private function to compile
p_compile:
	@echo -e "\n-> Compiling project"
	@c$(MAKE) --build build


