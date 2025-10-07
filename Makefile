mkdir:
	@mkdir -p build

all: mkdir
	g++ -O3 -fPIC -shared -o build/librapl.so rapl.cpp
