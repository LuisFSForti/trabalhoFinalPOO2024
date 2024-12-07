# Trabalho Final de POO - 2024

<a href="https://www.asciiart.eu/mythology">Link para as artes em ASCII</a>
## Ideia Principal
Construir um rpg simples. O player poderá escolher entre diversas classes com diferentes atributos para avançar na briga contra alguns inimigos mágicos com suas próprias características. O tipo de batalha ocorrerá por turnos.

### Player
O jogador poderá escolher entre 4 classes principais de jogabilidade:

- Mago
- Barbáro
- Bardo
- Paladino

### Inimigos
Os inimigos são dividos em seu tipo de ataque e outras características como:

- Dano Físico (centauro, dragões)
- Dano Mágico (fadas, grifos)
- Dano psicológico (sereias, fantasmas)

### Batalha

Será dada por turnos, com "dados" para decidir a sorte nos ataques ou defesas tanto do player quanto dos inimigos. Como o jogo é apenas um "demo" curto seriam feitas batalhas em sequência enquanto o player se mantivesse vivo, como em uma dungeon, tentando chegar até o final. Os inimigos aparecem de forma aleatória.

## Organização das Classes

### Player Principal
Classe principal do jogador com as propriedades e métodos relevantes tais quais:

- Propriedades:
  - Sorte;
  - Vida total;
  - Vida atual;
  - Velocidade;
  - Defesa física;
  - Defesa mágica;
  - Defesa Psicológica;

- Métodos:
  - Atacar;
  - Rolar Sorte;
  - Receber Ataque;

