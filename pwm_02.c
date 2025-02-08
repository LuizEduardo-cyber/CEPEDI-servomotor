#include <stdio.h> //biblioteca padrão da linguagem C
#include "pico/stdlib.h" //subconjunto central de bibliotecas do SDK Pico
#include "hardware/pwm.h" //biblioteca para controlar o hardware de PWM

//definir os angulos
#define ang_180 6000 //0,12 * 50000 --> wrap
#define ang_90 3675  //0,0735 * 50000 --> wrap
#define ang_0 1250 //0,025 * 50000 --> wrap



#define PWM_motor 22 //pino do motor conectado a GPIO como PWM
const uint16_t WRAP_PERIOD = 50000; //valor máximo do contador - WRAP
const float PWM_DIVISER = 50.0; //divisor do clock para o PWM
const uint16_t LED_STEP = 12.5; // 5 us --> 20000 us/ 5us = 4000 --> WRAP / 4000 -> 50000/4000 -> 12.5




//função para configurar o módulo PWM
void pwm_setup()
{
    gpio_set_function(PWM_motor, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM

    uint slice = pwm_gpio_to_slice_num(PWM_motor); //obter o canal PWM da GPIO

    pwm_set_clkdiv(slice, PWM_DIVISER); //define o divisor de clock do PWM

    pwm_set_wrap(slice, WRAP_PERIOD); //definir o valor de wrap

    pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente
}


//função principal
int main()
{
    stdio_init_all(); //inicializa o sistema padrão de I/O
    
    pwm_setup(); //configura o PWM

    uint up_down = 1; //variável para controlar se o nível do LED aumenta ou diminui

    pwm_set_gpio_level(PWM_motor, ang_180); // deixa o motor no angulo 180°
    sleep_ms(5000); //pausa de 5 seg

    pwm_set_gpio_level(PWM_motor, ang_90); // deixa o motor no angulo 90°
    sleep_ms(5000); //pausa de 5 seg


    pwm_set_gpio_level(PWM_motor, ang_0); // deixa o motor no angulo 0°
    sleep_ms(5000); //pausa de 5 seg

    uint nivel_ang0 = ang_0; //foi definido para começar o loop principal no angulo 0°


    //loop principal
    while (true) {
        pwm_set_gpio_level(PWM_motor, nivel_ang0); //para setar o motor no angulo nivel_ang0
        if (up_down) 
        {
            nivel_ang0 += LED_STEP; // Incrementa para que ocorra o movimento do motor
            if (nivel_ang0 >= ang_180)
                up_down = 0; // Muda direção para diminuir quando atingir o angulo máximo que é 180°
        }
        else
        {
            nivel_ang0 -= LED_STEP; // Decrementa para que ocorra o movimento contrário do motor
            if (nivel_ang0 <= ang_0)
                up_down = 1; // Muda direção para aumentar quando atingir o mínimo qie é 0°
        }
        
        sleep_ms(10); //uma pequena pausa de 10 milissegundos

    }
}
