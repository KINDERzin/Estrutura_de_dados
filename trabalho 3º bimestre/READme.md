# 🦁 Akinator dos Animais

> Jogo de adivinhação em C: pense em um animal e a árvore de decisão tenta descobrir qual é — e aprende um novo animal toda vez que erra!

![C](https://img.shields.io/badge/linguagem-C-00599C)
![Status](https://img.shields.io/badge/status-%20concluído-green)

## 🎮 Sobre

Inspirado no clássico Akinator, esse jogo usa uma **árvore binária de decisão** para tentar adivinhar em qual animal você está pensando, através de perguntas de sim/não.

O diferencial: quando o programa erra, ele **aprende** — pede o animal certo e uma pergunta que diferencie os dois, e reorganiza a árvore automaticamente para acertar da próxima vez.

## ✨ Funcionalidades

- 🌳 Árvore de decisão binária (perguntas nos nós internos, animais nas folhas)
- 🧠 Aprendizado dinâmico: a árvore cresce a cada erro
- 🔁 Suporte a múltiplas rodadas seguidas
- ✅ Validação de entradas (respostas s/n)

## 🕹️ Como jogar

1. Pense em um animal
2. Responda as perguntas com `s` (sim) ou `n` (não)
3. Se o programa acertar: 🎉
4. Se errar: digite o animal correto e uma pergunta que o diferencie do palpite errado — assim ele aprende pra próxima vez!

## 🛠️ Tecnologias

- **Linguagem:** C
- **Estrutura de dados:** Árvore binária (struct `No` / `Arvore`)

## ▶️ Como rodar

```bash
git clone https://github.com/KINDERzin/Estrutura_de_dados.git
cd Estrutura_de_dados
gcc akinator.c -o akinator
./akinator
```

## 👤 Autor

[**Erick Matheus Frias**](https://github.com/KINDERzin) — estudante de Ciência da Computação (UNESPAR)

---

*Projeto pessoal de estudo com estruturas de dados em C.*