# 🚦 Projeto: Temporização com Pico SDK (BitDogLab)

Este repositório contém duas atividades de temporização utilizando a **Raspberry Pi Pico SDK** na ferramenta **BitDogLab**. As atividades envolvem controle de LEDs usando **temporizadores de software** (`add_repeating_timer_ms()` e `add_alarm_in_ms()`).  

## 📌 Atividades Implementadas  

### **🟢 Atividade 1: Semáforo com Temporização**  
- Simula um semáforo utilizando **3 LEDs (RGB)** conectados às **GPIOs 11, 12 e 13**.  
- A cada **3 segundos**, os LEDs mudam de cor na sequência: **Vermelho → Amarelo → Verde → Vermelho**.  
- Usa a função **`add_repeating_timer_ms()`** para manter a temporização constante.  

### **🔴 Atividade 2: Acionamento de LEDs com Botão**  
- Um botão (GPIO **5**) inicia a sequência de LEDs.  
- Todos os LEDs ligam simultaneamente e depois vão apagando um por um, a cada **3 segundos**.  
- O botão **não pode interromper a sequência em andamento**.  
- Usa a função **`add_alarm_in_ms()`** para gerenciar os estados.  

---

## 🚀 Como Rodar no BitDogLab  

### **Passo 1: Configurar o Ambiente**  
1. Instale o **Pico SDK** seguindo a documentação oficial.  
2. Clone este repositório:  
   ```bash
   git clone https://github.com/KayleKylian/Clock-U4C5.git
   cd Clock-U4C5
3. Compile o código e carregue-o na Raspberry Pi Pico ou BitDogLab.

### Passo 2: Simulação no Wokwi
1. Crie um projeto usando a Raspberry Pi Pico W (Pico SDK)
2. Conecte os LEDs às GPIOs 11, 12 e 13 e o botão à GPIO 5.
3. Compile e rode o código!

---

## 🔧 Tecnologias Utilizadas
- Linguagem: C
- SDK: Pico SDK
- Plataforma de Simulação: BitDogLab
- Microcontrolador: Raspberry Pi Pico