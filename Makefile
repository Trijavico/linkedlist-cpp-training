SRC= LinkedList.cpp \
	 Node.cpp

OBJ= LinkedList.o \
	 Node.o

run: build
	@./bin/main

build: ensure_bin
	@g++ -c ${SRC}
	@g++ ${OBJ} main.cpp -o ./bin/main

ensure_bin:
	@mkdir -p ./bin
