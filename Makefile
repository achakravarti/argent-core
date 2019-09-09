DIR_INSTALL = /usr/local/include/argent

install:
	sudo mkdir -p $(DIR_INSTALL)
	sudo cp src/core.h $(DIR_INSTALL)


uninstall:
	sudo rm -rf $(DIR_INSTALL)

