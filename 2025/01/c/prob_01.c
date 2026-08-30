#include <stdio.h>
#include <stdlib.h>

// Por vicio e fornicio uso unha estrutura
typedef struct ROTACION
{
    char dir;
    int  clicks;
} ROT;

int main()
{

    // Stream ca información do problema
    FILE* fstream = fopen("input.txt", "r");
    if (fstream == NULL)
    {
        perror("Erro abrindo o ficheiro");
        return 1;
    }

    // varias varibles para despois
    char *linha = NULL;
    size_t bufs = 0; /* :FACER: por que 0? (saqueino de stackoverflow...) */
    size_t longo;

    signed int novo = 50;
    signed int pases = 0;
    signed int d_0;

    // metres teñamos algunha liña pa ler
    while ( (longo = getline(&linha, &bufs, fstream)) != -1 )
    {
                                      /* furrula de milagro */
        ROT rot = { .dir = linha[0], .clicks = atoi(&linha[1]) };

        if ( rot.dir == 'L' )
        {
            d_0 =  (novo != 0) * novo + (novo == 0) * 100;
            printf("N: %d, d_0: %d, pases: %d", novo, d_0, pases);
            novo = (novo + (100 - (rot.clicks % 100))) % 100;
            if (rot.clicks >= d_0) {
                pases = pases + 1 + ((rot.clicks - d_0) / 100);
            }
        }
        else if ( rot.dir == 'R')
        {
            d_0 = (100 - novo);
            printf("N: %d, d_0: %d, pases: %d", novo, d_0, pases);
            novo = (novo + rot.clicks) % 100;
            if (rot.clicks >= d_0) {
                pases = pases + 1 + ((rot.clicks - d_0) / 100);
            }
        }
        printf("\n");

    }

    fclose(fstream);

    // RESULTADO
    printf("cambios: %i\n", pases);

    if (linha) { free(linha); }
    return 0;
}
