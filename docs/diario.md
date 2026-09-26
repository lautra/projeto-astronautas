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


OPENCODE:
usei o OpenCode Zen e o modelo MiMo-V2.6-Flash Free


## Parte 1: uso de IA para entender algo

- O que perguntei (ou "não usei"):
//
eu não sabia que precisava separar a declaração de uma classe (.h) da implementação (.cpp). perguntei como fazer e separar corretamente.


- O que aprendi:

//
entendi que é porque cada arquivo é compilado separadamente, e o .h funciona como um contrato que outros arquivos podem usar sem ver o código completo.

## Primeiro contato: revisão sem editar

- As três melhorias que a IA sugeriu, em uma linha cada:
// 
1) Não usar "texto mágico" para o estado do voo
2) Adicionar const aos getters de Astronauta e Voo
3) Juntar as validações repetidas num método auxiliar

- A que escolhi e por quê:

Escolhi a opção 2, pois o compilador vira um ajudante, ele impede na hora de compilar que alguém altere um dado que deveria ser só leitura. Sem o const, esse erro só apareceria em tempo de execução (ou nunca, e causaria bug)

- O que mudou no código, e se os seis testes continuaram passando:

Adicionou const em dez métodos, da classe Astronauta e da classe Voo; getCpf, getNOme, getIdade, estaVivo, estaDisponivel, getVooPArticipados, getCodigo, getEStado, getQuanyidadeAstronautas, getCpf.

OS seis testes continuaram passando.


- O que entendi que não sabia antes:

Eu não sabia que o uso do const impede alterações e permite uso em objetos const.


## Missão 1: LISTAR_ASTRONAUTAS e HISTORICO

- Primeira mensagem (o pedido do plano): 
//
Pedi os comandos LISTAR_ASTRONAUTAS e HISTORICO cpf, com a saída exata do enunciado, avisando para não mudar comandos existentes e para me dizer o plano antes de editar.
- O plano que a IA apresentou, resumido:
//
Editar só o src/main.cpp: criar um método privado vooEmCursoDe(cpf) na Agencia (para achar o voo em curso do astronauta), e dois métodos públicos novos, listarAstronautas() e historico(cpf), além de dois "else if" novos no main() para os comandos.

- Mudei algo no plano antes de liberar?
// Não

- Resultado de `testar.sh missao1` e de `testar.sh parte1`:
//
Os 2 testes da missão 1 passaram (OK 01_listar_astronautas, OK 02_historico), e os 6 testes da parte 1 continuaram passando também.
- Precisei refazer? O que mudou no pedido:
//
Não precisei, funcionou sem precisar ajustar nada.

## Missão 2: SALVAR e CARREGAR

- Primeira mensagem: 
// 
  Pedi os comandos SALVAR e CARREGAR, explicando o que cada um deve fazer, os erros esperados, e pedindo que ela mostrasse o formato do arquivo com um exemplo e explicasse como reconstrói os objetos, antes de editar qualquer arquivo.  

- O plano, resumido:
//
  Editar só o src/main.cpp, incluindo <fstream> e <sstream>.
  Dois métodos novos na Agencia: salvar(arquivo) e carregar(arquivo), usando só
  os getters que já existem. No carregar, ela lê tudo para vetores temporários
  e só troca pelos dados reais no final (com swap), para não perder dados caso
  o arquivo esteja corrompido no meio da leitura. Reconstrói o astronauta
  chamando morrer() ou embarcar() conforme os campos "vivo" e "disponivel"
  lidos, em vez de criar setters novos.

- O formato do arquivo (cole cinco linhas do `dados_teste.txt`):
//
  ASTRONAUTAS 3
  111 30 1 1 1 10 Ana Maria
  222 35 0 0 1 20 Bruno Costa
  333 28 1 1 1 30 Carla Souza
  VOOS 3
- Resultado de `testar.sh missao2` e de `testar.sh parte1`:
//
  Os 3 testes da missão 2 passaram (01_salvar, 02_carregar,03_arquivo_inexistente), e os 6 testes da parte 1 continuaram passando. A missão 1 também continuou passando (2 de 2).
- Precisei refazer? O que mudou no pedido:
//
Não precisei, funcionou de primeira.

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
