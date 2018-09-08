#include "lena.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void le(Pgm *pgm, const char *caminho)
{
	FILE *ptr;
	long inicio_cursor, final_cursor, tamanho;
	char ch;

	ptr = fopen(caminho, "r");

	if(ptr==NULL){
	        printf("Deu ruim\n");
	        exit(1);
	 }
	
	fgets(pgm->numero_magico, 4, ptr);
	
	pgm->numero_magico[(strlen(pgm->numero_magico))-1] = 0;
	
	
	inicio_cursor = ftell(ptr);
	
	while( (ch = fgetc(ptr)) != '\n'); // Apenas para mover o cursor
	
	final_cursor = ftell(ptr);
	
	tamanho = final_cursor - inicio_cursor; //Tamnho do comentario em bytes
	
	pgm->comentario = (char *) malloc(tamanho);
	
	fseek(ptr, inicio_cursor, SEEK_SET); // Voltar cursor para posição Inicio cursor
	
        fgets(pgm->comentario, tamanho, ptr);

	fscanf(ptr, "%d %d\n", &pgm->largura, &pgm->altura);
	
	fscanf(ptr, "%d\n", &pgm->maximo_cinza);
	
	pgm->pixels = (unsigned char *) malloc(pgm->altura * pgm->largura * sizeof(unsigned char));
	
	fread(pgm->pixels, sizeof(unsigned char), pgm->altura * pgm->largura, ptr);
	

	fclose(ptr);

}

extern void salva(const Pgm *pgm, const char *caminho)
{
        FILE *ptr;
        
        ptr = fopen(caminho, "wb");
        
        fprintf(ptr, "%s\n", pgm->numero_magico);
        
        fprintf(ptr, "%s\n", pgm->comentario);
        
        fprintf(ptr, "%d %d\n", pgm->altura, pgm->largura);
        
        fprintf(ptr, "%d\n", pgm->maximo_cinza);
        
        if(pgm-> pixels == NULL)
        {
                printf("Alocacao de pixels teve erro\n");
                exit(2);
        }
        
        fwrite(pgm->pixels, sizeof(unsigned char), pgm->altura * pgm->largura, ptr);
        
        
        fclose(ptr);
}
extern void negativo(Pgm *saida, const Pgm *entrada)
{
        for(int i = 0; i < entrada->altura * entrada->largura; i++)
        {
                saida->pixels[i] = 255 - entrada->pixels[i];
        }
}



























