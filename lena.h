#ifndef LENA_H
#define lENA_H

typedef struct _Pgm
{
	char numero_magico[4], *comentario;
	int altura, largura, maximo_cinza;
	unsigned char *pixels;
	
}Pgm;

extern void le(Pgm *pgm, const char *caminho);
extern void salva(const Pgm *pgm, const char *caminho);
extern void negativo(Pgm *saida, const Pgm *entrada); 





#endif
