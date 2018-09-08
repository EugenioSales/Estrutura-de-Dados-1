#include "lena.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>     

int main()
{
	Pgm img;

	le(&img, "lena.pgm");
        
	//printf("Numero Magico: %s\n", ob.numero_magico);
	//printf("Tamanho Numero Magico: %ld\n", sizeof(ob->numero_magico));
	
	//printf("%s\n", ob.comentario);
	//printf("Altura: %d e Largura: %d\n", ob.altura, ob.largura);
	//printf("Maximo de cinza: %d\n", ob.maximo_cinza);
	
	negativo(&img, &img);
	
	salva(&img, "copia.pgm");
	
	

	
	return 0;
}


