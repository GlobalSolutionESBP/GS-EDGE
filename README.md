<div align='center'>
    <br>
    <h1>  Sistema de Medicação com Compartimento Automático e Alerta Sonoro </h1>
</div>

<br> 
<table>
    <tr>
        <td>
            <div> 
                <table>
                    <tr>
                        <th> Alunas </th>
                        <th> RMs </th>
                    </tr>
                    <tr>
                        <th> Giovanna Franco G Rodrigues</th>
                        <th> RM 553701 </th>
                    </tr>
                    <tr>
                        <th> Isabela Barcellos Freire </th>
                        <th> RM 553746 </th>
                    </tr>
                </table>
            </div>
        </td>
        <td>
            <div>
                <b> Global Solution <br> Edge Computing & Computer Systems </b>
                <td><b> Objetivo Monitorar e alertar com precisão a hora de tomar rémedios </b></td>
            </div>
        </td>
    </tr>
</table>


<details open>
<summary> Problema Identificado </summary>
<p>
O esquecimento na administração de medicamentos emerge como um desafio significativo, afetando a eficácia dos tratamentos e a qualidade de vida dos pacientes. Este problema se manifesta em diversas populações, desde idosos gerenciando várias prescrições até pessoas com condições crônicas que demandam uma rotina de medicamentos. 
</p>
<p>
Os impactos do esquecimento vão além da eficácia do tratamento, estendendo-se para questões financeiras e a carga sobre os sistemas de saúde. Tratamentos interrompidos ou inconsistentes podem levar a complicações de saúde, resultando em visitas hospitalares adicionais e custos crescentes.
A implementação de um Sistema de Medicação com Compartimento Automático e Alerta Sonoro oferece várias vantagens, especialmente para pessoas que precisam seguir uma rotina regular de medicação. 
</p>
</details>

<details>
<summary> Descrição Geral</summary>
<p>
Este código implementa um sistema de medicação automatizado com um compartimento que se abre no horário programado e emite um alerta sonoro. O usuário deve pressionar um botão para confirmar a administração do medicamento. O próximo alerta é programado após a confirmação, e o tempo restante até a próxima dose é exibido em um display LCD.
</p>
</details>

<details>
<summary> Hardware</summary>
<div align="center">
<b> Tabela com o hardware do circuito completo </b>

| Quantidade | Descrição                     |
| ---------- | ----------------------------- |
| 1          | Arduino Uno R3                |
| 1          | Piezo (buzzer)                |
| 1          | Botão                         |
| 1          | LCD 16x2                      |
| 1          | 250kΩ Potenciômetro           |
| 1          | Servo Motor                   |
| 1          | 220Ω Resistor                 |
| 1          | 10kΩ Resistor                 |
| 1          | 1kΩ Resistor                  |
</div>
</details>

<details>
<summary> Circuito </summary>
<img height="385em" align="center" src="https://github.com/GlobalSolutionESBP/GS-EDGE/blob/main/SimuladorMedicamentos.png">
</details>

<details>
<summary> Link TinkerCad</summary>
<ul>
    <li><a href="https://www.tinkercad.com/things/3QawV0w2AQ2-simulador-para-aviso-de-remedio-/editel?returnTo=%2Fdashboard%3Ftype%3Dcircuits%26collection%3Ddesigns"> Circuito para aviso de Medicamentos </a> </li>
</ul>
</details>

<details>
<summary>Documentação Código</summary>
<p>
    <h3> Componentes Necessários: </h3>
    Servo motor para controlar a abertura e fechamento do compartimento.
    Display LCD para mostrar informações ao usuário.
    LED para indicar visualmente o status do sistema.
    Buzzer para o alerta sonoro.
    Botão para a confirmação da administração do medicamento.
</p>
<p>
    <h3> Pins de Conexão:</h3>
    <p> Pino 9: Conectado ao servo motor.</P>
    <p> Pinos 12, 11, 5, 4, 3, 2: Conectados ao display LCD.</p>
    <p> Pino 8: Conectado ao LED indicador.</p>
    <p> Pino 10: Conectado ao buzzer. </p>
    <p> Pino 7: Conectado ao botão de confirmação.</p>
</p>
<p>
    <h3> Constantes: </h3>
    intervaloMedicamento: Intervalo entre doses de medicamento (8 horas).
    intervaloMedicamento2: Intervalo inicial para começar a simulação (7 segundos).
    intervaloAlerta: Intervalo entre alertas sonoros (3 segundos).
</p>
<p>
    <h3> Variáveis: </h3>
    proximaDose: Armazena o tempo em milissegundos da próxima dose.
    proximoAlerta: Armazena o tempo em milissegundos do próximo alerta sonoro.
    alertaAtivo: Indica se o alerta sonoro está ativo.
</p>
<p>
    <h3> Função Setup: </h3>
    Inicializa o display LCD, o servo motor e os pinos de entrada/saída.
    Configura os tempos iniciais para a próxima dose e próximo alerta.
    Posiciona o servo motor na posição inicial (compartimento fechado).
</p>
<p>
    <h3> Função Loop: </h3>
    Verifica se é hora de administrar o medicamento chamando a função medicamentoProgramado.
    Se for hora, chama as funções alertaSonoro, aguardarConfirmacao e fecharCompartimento.
    Atualiza as informações no display LCD chamando a função atualizarLCD.
</p>
<p>
    <h3> Função medicamentoProgramado: </h3>
    Verifica se o tempo atual é maior ou igual ao tempo programado para a próxima dose.
    Se verdadeiro, atualiza o tempo da próxima dose, ativa o alerta e programa o próximo alerta.
</p>
<p>
    <h3>Função abrirCompartimento:</h3>
    Abre o compartimento movendo o servo motor para a posição de abertura.
</p>
<p>
    <h3>Função alertaSonoro:</h3>
    Exibe a mensagem "HORA DO MEDICAMENTO" no display LCD.
    Ativa o alerta sonoro e aguarda 3 segundos antes de desativar.
</p>
<p>
    <h3>Função aguardarConfirmacao: </h3>
    Exibe a mensagem "Pressione o botao" no display LCD.
    Aguarda a confirmação do botão para prosseguir.
    Durante a espera, programa o próximo alerta se o tempo atual for maior ou igual ao próximo alerta.
</p>
<p>
    <h3> Função fecharCompartimento: </h3>
    Fecha o compartimento movendo o servo motor para a posição de fechamento.
</p>
<p>
    <h3> Função atualizarLCD: </h3>
    Atualiza o display LCD com o tempo restante até a próxima dose.
    Calcula horas e minutos com base no tempo restante.
</p>
<h1> Notas Importantes: </h1>

Certifique-se de conectar os componentes aos pinos corretos conforme definido no código.
O buzzer é ativado durante a espera pelo botão e também após cada confirmação.
O sistema continuará operando em um loop, administrando medicamentos e emitindo alertas até ser desligado.
Observações:
Este código é projetado para fins educacionais e de simulação. Sempre siga as orientações médicas ao administrar medicamentos. Certifique-se de que os tempos de intervalo e doses se adequam às necessidades específicas de saúde do usuário.
</p>
</details>

<details>
<summary>Link Youtube</summary>
<li><a href="https://youtu.be/3e1_I_sgo6U"> Vídeo Explicativo </a</li>
</details>


