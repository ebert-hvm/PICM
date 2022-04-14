#include <stdlib.h> // abs()

const int x_range = 500, y_range = 500; // tamanho em milimetros da area a ser analisada
const int variacao_minima = 10; // diferenca minima pra comparar 2 distancias
const int step_delay = 100; // delay do passo em milissegundos
const int read_delay = 100; // delay de leitura da medida pela sonda

bool objeto[y_range][x_range]; //matriz que diz se a coordenada ta em cima do objeto ou nao

int height; // altura ate o objeto
int step = 5; // distancia em milimetros de um passo no plano xy (deve ser divisivel por y_range e x_range)
int h_step = 10; // distancia em milimetros de um passo em z(deve ser divisivel por y_range e x_range)
int cur_x, cur_y, cur_z; // coordenadas atuais 


void x_step(int step, int direction)
{
    // direction 1: sentido x positivo
    // direction -1: sentido x negativo
    cur_x += direction * step;

    // fazer o motor do eixo x dar um passo
    delay(step_delay); // esperar um delay de passo
}

void y_step(int step, int direction)
{
    // direction 1: sentido y positivo
    // direction -1: sentido y negativo
    cur_y += direction * step;

    // fazer o motor do eixo y dar um passo
    delay(step_delay); // esperar um delay de passo
}

void z_step(int step, int direction)
{
    // direction 1: sentido z positivo
    // direction -1: sentido z negativo
    cur_z += direction * step;

    // fazer o motor do eixo z dar um passo
    delay(step_delay); // esperar um delay de passo
}


int obter_distancia()
{
    // ler distancia atual no sensor
}

void scan()
{
    x_step(cur_x*step, -1);
    y_step(cur_y*step, -1);
    // voltando as coordenadas para a origem
    while(cur_y < y_range)
    {
        while(cur_x < x_range)
        {
            if(abs(obter_distancia() - height) <= variacao_minima) // distancia d ta mais ou menos constante
            {
                objeto[cur_y][cur_x] = true;
            }
            x_step(step, 1); // indo para a proxima coluna
        }
        x_step(cur_x*step, -1); // voltando x para o 0
        y_step(step, 1); // indo para a proxima linha
    }
    y_step(cur_y*step, -1); // voltando y para o 0
}

void start_measurement()
{
    z_step(height-h_step, -1); //colocar z na altura h_step

    while(cur_y < y_range)
    {
        while(cur_x < x_range)
        {
            if(objeto[cur_y][cur_x])
            {
                z_step(h_step, -1); // encostar no objeto
                delay(read_delay);// esperar delay de leitura
                z_step(h_step, 1); // desencostar do objeto
            }
            x_step(step, 1); // indo para a proxima coluna
        }
        x_step(cur_x*step, -1); // voltando x para o 0
        y_step(step, 1); // indo para a proxima linha
    }
    y_step(cur_y*step, -1); // voltando y para o 0
}

void setup()
{
    height = obter_distancia(); // altura ate o objeto no meio
    cur_x = x_range/2, cur_y = y_range/2, cur_z = height; // comecar do meio

    // configuracoes iniciais

    scan(); // escanear objeto
    start_measurement(); // comecar a fazer as medidas com a sonda
}


void loop()
{
    //nao tem loop
}