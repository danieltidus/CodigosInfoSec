#include <stdio.h> 
int main(int argc, char * argv[ ]){
 
	// Cria um buffer na pilha 
 	char buf[256]; 
 	// Não verifica tamanho do buffer antes da cópia
 	strcpy(buf,argv[1]); 
 	// Imprime o conteúdo do buffer 
 	printf("%s\n",buf); 
 
 	return 1; 
}
