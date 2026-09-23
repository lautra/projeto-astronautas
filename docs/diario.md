# Diário da atividade

Escreva com as suas palavras. Frases curtas bastam. Não cole a conversa inteira
com a IA. Cole só os pedidos que você enviou.

## Ambiente

- Versão do OpenCode (`opencode --version`): ainda não instalei
- Modelo usado: vou definir seguindo as instruções do professor quando for pra parte 2

## Parte 1: antes de programar

- O que cada classe guarda: 
//

  astronauta guarda CPF, nome, idade, se está vivo e se está disponível, também uma lista dos códigos dos voos em que já participou. 

  voo guarda o código, o estado atual e uma lista de CPFs dos astronautasa a bordo, ele não conhece os objetos Astronautas, só os CPFs.

  agencia guarda a lista de todos os astronautas e todos os voos cadastrados, e é ela quem decide se uma operação pode acontecer, fazendo as verificações antes de mandar o Voo ou Astronauta mudarem de estado.



- O que acontece em `LANCAR_VOO`, em palavras:

//
  a Agencia procura voo pelo código, se não existir, ou não tiver planejado, ou estiver sem astronautas, vai dá erro.

  depois ela percorre todos os astronautas a bordo, na ordem em que foram adicionados, conferindo se algum está morto ou indisponivel, se estiver, para ali e mostra o erro, sem mudar nada.

  só se todos passarem é que a Agencia manda cada Astronauta embarcar e regstrar a participação dele naquele voo, e muda o estado do voo para "em curso".


- Uma dúvida que eu tinha antes de começar:
//



## Parte 1: uso de IA para entender algo

- O que perguntei (ou "não usei"):
//
eu não sabia que precisava separar a declaração de uma classe (.h) da implementação (.cpp). perguntei como fazer e separar corretamente.


- O que aprendi:

//
entendi que é porque cada arquivo é compilado separadamente, e o .h funciona como um contrato que outros arquivos podem usar sem ver o código completo.

## Primeiro contato: revisão sem editar

- As três melhorias que a IA sugeriu, em uma linha cada:
- A que escolhi e por quê:
- O que mudou no código, e se os seis testes continuaram passando:
- O que entendi que não sabia antes:

## Missão 1: LISTAR_ASTRONAUTAS e HISTORICO

- Primeira mensagem (o pedido do plano):
- O plano que a IA apresentou, resumido:
- Mudei algo no plano antes de liberar?
- Resultado de `testar.sh missao1` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 2: SALVAR e CARREGAR

- Primeira mensagem:
- O plano, resumido:
- O formato do arquivo (cole cinco linhas do `dados_teste.txt`):
- Resultado de `testar.sh missao2` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 3: RELATORIO

- Primeira mensagem:
- O plano, resumido:
- Resultado de `testar.sh missao3` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 4: livre

- O que escolhi e por quê:
- O comando novo, a saída que eu esperava e o nome do meu arquivo de comandos
  (escritos antes de pedir):
- Primeira mensagem:
- O que veio, comparado com o que eu esperava:
- `testar.sh parte1` continuou passando?
- Aceitei, ajustei ou descartei? Por quê:

## Fechamento

- O que a IA fez que eu não conseguiria fazer sozinho nesse prazo:
- Onde ela errou ou fez algo que eu não pedi:
- O que eu faria diferente da próxima vez:
