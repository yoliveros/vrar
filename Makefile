main := $(wildcard src/*.c)

dev: $(main) 
	@mkdir -p dev
	@echo 'Dev Build'
	$(CC) $(main) -o dev/vrar -g -Wall -Werror -Wextra -pedantic -std=c17

exec:
	@echo 'Running...'
	@dev/./vrar

run: dev exec

clean: 
	@rm -rf dev
	@rm -rf dist

dist: $(main)
	@mkdir -p dist
	@echo 'Prod Build'
	$(CC) $(main) -o dist/vrar -O2 -Wall -Werror -Wextra -pedantic -std=c17
