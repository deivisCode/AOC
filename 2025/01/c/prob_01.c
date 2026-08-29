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
    int cambios = 0;
    signed int n = 50;

    // metres teñamos algunha liña pa ler
    while ( (longo = getline(&linha, &bufs, fstream)) != -1 )
    {
                                      /* furrula de milagro */
        ROT rot = { .dir = linha[0], .clicks = atoi(&linha[1]) };

        if ( rot.dir == 'L' )
        {
            printf("novo: %d\n", n);
            n = (n - rot.clicks) % 100;
            if (n == 0) { cambios++; }
        }
        else
        {
            printf("novo: %d\n", n);
            n = (n + rot.clicks) % 100;
            if (n == 0) { cambios++; }
        }

    }

    fclose(fstream);

    // RESULTADO
    printf("cambios: %i", cambios);

    if (linha) { free(linha); }
    return 0;
}
