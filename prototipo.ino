#include <stdlib.h> // abs()

const int x_range = 500, y_range = 500; // tamanho em milimetros da area a ser analisada
const int variacao_minima = 10; // diferenca minima pra comparar 2 distancias

bool objeto[y_range][x_range]; //matriz que diz se a coordenada ta em cima do objeto ou nao

int height; // altura ate o objeto
int step = 1; // distancia em milimetros de um passo (deve ser divisivel por y_range e x_range)
int cur_x, cur_y; // coordenadas atuais 


void x_step(int direction)
{
    // direction 1: sentido x positivo
    // direction -1: sentido x negativo
    cur_x += direction * step;

    // fazer o motor do eixo x dar um passo
}

void y_step(int direction)
{
    // direction 1: sentido y positivo
    // direction -1: sentido y negativo
    cur_y += direction * step;

    // fazer o motor do eixo y dar um passo
}

int obter_distancia()
{
    // ler distancia atual no sensor
}

void scan()
{
    while(cur_x) x_step(-1);
    while(cur_y) y_step(-1);
    // voltando as coordenadas para a origem
    while(cur_y < y_range)
    {
        while(cur_x < x_range)
        {
            if(abs(obter_distancia() - height) <= variacao_minima) // distancia d ta mais ou menos constante
            {
                objeto[cur_y][cur_x] = true;
            }
            x_step(1); // indo para a proxima coluna
        }
        while(cur_x) x_step(-1); // voltando x para o 0
        y_step(1); // indo para a proxima linha
    }
    while(cur_y) y_step(-1); // voltando y para o 0
}

void setup()
{
    cur_x = x_range/2, cur_y = y_range/2; // comecar do meio
    height = obter_distancia(); // altura ate o objeto no meio

    // configuracoes iniciais

    scan(); // escanear objeto
}


void loop()
{

}