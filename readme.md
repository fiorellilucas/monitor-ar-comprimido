# Monitor de Pressão de Ar Comprimido

Projeto embarcado de um sistema para monitoramento remoto de pressão de ar comprimido em linha de produção, utilizando o microcontrolador ESP32.

![Protótipo feito com placa perfurada, conectores, sensor de pressão, componentes eletrônicos e microcontrolador.](./static/IMG_2096.JPEG "Protótipo da placa do projeto")

## Principais componentes de Hardware
- Placa perfurada 10cm x 5cm;
- Microcontrolador ESP32 com USB-C;
- Sensor de pressão de 145 PSI (transdutor de saída analógica);
- Fonte de alimentação de 5V;

O circuito todo é alimentado por uma fonte chaveada de 5V, que alimenta o microcontrolador e o sensor de pressão. Em seguida, a saída analógica do sensor passa por um divisor de tensão (5V → 3,3V) e entra no Conversor Analógico-Digital (ADC) do microcontrolador, o microcontrolador então envia esse sinal via Wi-Fi para um [servidor rodando em uma rede local](https://github.com/fiorellilucas/monitor-ar-comprimido-backend).
