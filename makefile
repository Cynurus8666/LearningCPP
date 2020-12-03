#makefile
SOURCE_MAIN=main.cpp

CMD=$(CXX) $? -o $@


main: $(SOURCE_MAIN)
	$(CMD)

