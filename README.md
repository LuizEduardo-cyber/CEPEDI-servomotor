# Projeto controle de servomotor por pwm 🚀

Esse projeto tem como objetivo controlar o servo motor, primeiro o servo motor começa no ângulo de 180°, depois para 90° e depois 0°, e logo em seguida ele se mantem em um loop infinito onde o servo motor rotacion-se entre 0° e 180°.

## Hardware 🛠️

- Microcontrolador RP2040 (Raspberry Pi Pico).
- Servo motor
- LED RGB.

## Software 💻

* **SDK do Raspberry Pi Pico:** O SDK (Software Development Kit) do Pico, que inclui as bibliotecas e ferramentas necessárias para desenvolver e compilar o código. [Instruções de instalação](https://www.raspberrypi.com/documentation/pico/getting-started/)
* **CMake:** Um sistema de construção multiplataforma usado para gerar os arquivos de construção do projeto.
* **Compilador C/C++:**  Um compilador C/C++ como o GCC (GNU Compiler Collection).
* **Git:** (Opcional) Para clonar o repositório do projeto.


### O código está dividido em vários arquivos para melhor organização:

- **`pwm_02.c`**: Código que tem como função
- **`CMakeLists.txt`:** Define a estrutura do projeto para o CMake.



## Como Compilar e Executar ⚙️

1. **Instale o SDK do Raspberry Pi Pico:** Siga as instruções no site oficial do Raspberry Pi.
2. **Clone este repositório:** https://github.com/LuizEduardo-cyber/CEPEDI-servomotor.git`
3. **Navegue até o diretório do projeto:** `cd CEPEDI-servomotor`
4. **Compile o projeto:** `cmake -B build && cmake --build build`
5. **Copie para o Pico:** Copie o conteúdo da pasta `build` (gerada após a compilação) para o Raspberry Pi Pico. O programa iniciará automaticamente.


## Funcionamento do Loop Principal 🔄 
```
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
   
  ```
O loop while (true) garante execução contínua. sleep_ms(1000) garante esse loop infinito.  void gpio_irq_handler(uint gpio, uint32_t events){ //definido manualmente para tratar eventos de interrupção.  pwm_set_gpio_level() é para setar o motor no angulo nivel_ang0.   if (up_down) é uma condição para quando up_down for igual a 1.  nivel_ang0 += LED_STEP,  Incrementa para que ocorra o movimento do motor.  if (nivel_ang0 >= ang_180)up_down = 0, Muda direção para diminuir quando atingir o angulo máximo que é 180°.  else, condição para quando up_down for igual a 0.  nivel_ang0 -= LED_STEP, Decrementa para que ocorra o movimento contrário do motor.    if (nivel_ang0 <= ang_0) up_down = 1,  Muda direção para aumentar quando atingir o mínimo qie é 0°.     sleep_ms(10), uma pequena pausa de 10 milissegundos.

## Configuração do pwm.
```
void pwm_setup()
{
    gpio_set_function(PWM_motor, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM

    uint slice = pwm_gpio_to_slice_num(PWM_motor); //obter o canal PWM da GPIO

    pwm_set_clkdiv(slice, PWM_DIVISER); //define o divisor de clock do PWM

    pwm_set_wrap(slice, WRAP_PERIOD); //definir o valor de wrap

    pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente
}

  ```
 gpio_set_function(PWM_motor, GPIO_FUNC_PWM), habilitar o pino GPIO como PWM.   uint slice = pwm_gpio_to_slice_num, obter o canal PWM da GPIO.   pwm_set_clkdiv, define o divisor de clock do PWM.   pwm_set_wrap, definir o valor de wrap.    pwm_set_enabled, habilita o pwm no slice correspondente.
## Diagrama de Conexões 💡:

https://drive.google.com/file/d/1u0X9xw7-6uIE6u2lQMcIoT7aXsAzwbFQ/view?usp=sharing

## Próximo Passos ➡️

- fazer o servo motor rotacionar com uma fluidez maior.
  
 ## 🔗 Link do Vídeo de Funcionamento:
 https://drive.google.com/file/d/1OJPM9WZ1L2_AfELuWRJ2WBmkdfB9j5mP/view?usp=drivesdk

 ## Contribuições 🤝

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests.

## 📞 Contato

- 👤 **Autor**: Luiz Eduardo Soares Ferreira.
 
- 📧 **E-mail**: luizeduardosoaresferreira942@gmail.com 

--- 
