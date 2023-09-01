# So Long - School 42 Project

## 📋Résumé

"So Long, Et merci pour le poisson !" est un jeu 2D simple développé en C. Le jeu est conçu pour être une introduction à la bibliothèque graphique MiniLibX et à quelques éléments basiques de gameplay comme les textures et les sprites. Dans ce jeu, le joueur doit collecter tous les items et s'échapper en utilisant le moins de mouvements possible.

## 💻Technologies Utilisées

- C
- MiniLibX
- Makefile
- Bibliothèque mathématique (-lm)

## 📦Installation

1. Clonez ce dépôt GitHub
   ```bash
   git clone https://github.com/Jeanmichel7/so_long.git
   ```
2. Compilez le projet avec le Makefile
   ```bash
   cd so_long
   make
   ```

## 📜Règles du Projet

- Le projet est écrit conformément à la Norme de l'école 42.
- Aucun memory leak n'est toléré.
- Le programme prend en argument un fichier de carte avec l'extension `.ber`.

## 🛠️Utilisation

1. Lancez le programme avec une carte `.ber` en argument
   ```bash
   ./so_long maps/map1.ber
   ```

### Contrôles

- `W` pour aller en haut
- `A` pour aller à gauche
- `S` pour aller en bas
- `D` pour aller à droite
- `ESC` pour quitter le jeu

Le nombre total de mouvements est affiché dans le shell à chaque déplacement.

## Bonus

- Sprite animations
- Le nombre total de mouvements s'affiche directement dans la fenêtre du jeu
