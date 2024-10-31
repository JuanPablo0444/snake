run: bin/programa			 #./ para ejecutar 		Este tipo de archivos es un  build system
	./bin/programa 


bin/programa: src/main.cpp include/*.hpp #*es para ahorrar tiempo, sustituye el ir poniendo los archivos
	g++ src/main.cpp -Iinclude -o bin/programa
#-I Sirve para buscar, en este caso, dentro de include		-o es para salida
#Interfaz: De entrada, de salida, mixtas, de señal

runTest: bin/test			 
	./bin/test 

bin/test: src/test.cpp include/*.hpp 
	g++ src/test.cpp -Iinclude -o bin/test -std=c++2a -lftxui-component -lftxui-dom -lftxui-screen 