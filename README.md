# Trabalho Final de POO - 2024

<a href="https://www.asciiart.eu/mythology">Link para as artes em ASCII</a>
## Ideia Principal
Sendo um rpg simples a ideia se baseia em uma party (equipe) de quatro membros controlados pelo jogador de maneira a lutarem contra diversos monstros, recebendo recompensas no final de cada batalha até vencer todos e terminar o jogo.

### Party

Os quatro membros disponíveis para o jogo são:

- Barbáro
- Paladino
- Bardo
- Mago

### Inimigos

Os inimigos são dividos em seu tipo de ataque e outras características como:

- Dano Físico (centauro, dragão,grifo)
- Dano Mágico (fada, fantasma)
- Dano psicológico (sereia)

### Batalha

Será dada por turnos, com "dados" para decidir a sorte nos ataques ou defesas tanto do player quanto dos inimigos. Além de ataques básicos existem efeitos auxiliares e itens que podem ser usados no decorrer da batalha, assim sendo possível utilizar de várias estratégias.

### Itens

Os itens para ajuda podem tanto auxiliar com o buff de algumas propriedades como armadura, sorte, ferramenta, agilidade, entre outros, assim como curar personagens machucados.

## Organização das Classes

### Personagem

Classe "mãe" que comanda os tipos especificos dos membros da equipe. Reúne métodos virtuais que são sobrecarregados nas classes Bárbaro, Paladino, Bardo e Mago.

Também dessa classe derivam os monstros por terem métodos e funções parecidos com os dos membros da equipe.

### Itens

Os itens são feitos de uma maneira "universal", isto é, suas propriedades de cura ou buffs são definidos através de propriedades da classe de forma a não ser necessário diversas classe como nos personagens, mantendo uma estrutura mais flexível.

### Controller

Essa classse une as demais e monta a estrutura de batalha, coordenando o inicial e final do jogo, além de distribuir os itens recebidos após vencer algum monstro.

### Print File

Responsável por ler e imprimir arquivos .txt que estão tanto com as imagens dos monstros assim como textos de introdução ou de vitória/derrota.
