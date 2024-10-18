run: bin/programa			 #./ para ejecutar 		Este tipo de archivos es un  build system
	./bin/programa 


bin/programa: main.cpp include/*.hpp #*es para ahorrar tiempo, sustituye el ir poniendo los archivos
	g++ main.cpp -Iinclude -o bin/programa
#-I Sirve para buscar, en este caso, dentro de include		-o es para salida
#Interfaz: De entrada, de salida, mixtas, de señal