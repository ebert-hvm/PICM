
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

void setup()
{

}

void loop()
{
    
}