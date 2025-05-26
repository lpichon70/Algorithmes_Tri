# 🔢 Algorithmes de Tri en C

Ce projet pédagogique propose une implémentation de 10 algorithmes de tri différents en langage C, avec un comparatif des performances basé sur le temps d'exécution.

## 📦 Contenu du projet

- 10 algorithmes de tri implémentés :
  - Bubble Sort
  - Selection Sort
  - Insertion Sort
  - Shell Sort
  - Heap Sort
  - Merge Sort
  - Quick Sort
  - Counting Sort
  - Radix Sort
  - Bucket Sort
- Un système de menu pour sélectionner le fichier de données et l’algorithme à utiliser
- Des fichiers `.txt` contenant des tableaux de différentes tailles dans le dossier `Storage/`
- Un chronomètre intégré pour mesurer le temps de tri
- Un fichier `utils.c` pour les fonctions utilitaires (lecture de fichier, affichage, chronométrage…)

## 🖥️ Prérequis

- [Visual Studio Code](https://code.visualstudio.com/)
- L’extension **C/C++ (ms-vscode.cpptools)**
- Le compilateur **GCC** (recommandé : via MSYS2 ou MinGW sous Windows)

## 📁 Structure du projet

```
.
├── main.c
├── .vscode/
│   ├── tasks.json
│   └── launch.json
├── src/
│   ├── 1_Bubble_Sort/
│   ├── 2_Selection_Sort/
│   ├── ...
│   ├── 10_Bucket_Sort/
│   └── Utils/
├── Storage/
│   ├── tabToSortExtraShort.txt
│   ├── tabToSortShort.txt
│   ├── tabToSortLong.txt
│   └── tabToSortVeryLong.txt
└── README.md
```

## ⚙️ Installation

1. Clone le projet :

```bash
git clone https://github.com/ton-pseudo/tri-algorithmes-c.git
cd tri-algorithmes-c
```

2. Ouvre le dossier dans Visual Studio Code.

3. Assure-toi d’avoir GCC installé (par exemple avec MSYS2).

4. Compile le projet avec `Ctrl + Maj + B` ou via le menu `Terminal > Run Build Task`.

5. Lance le programme avec `F5` (débogage) ou `Ctrl + F5` (exécution simple).

✅ Le fichier exécutable sera généré sous le nom `main.exe`.

## ▶️ Utilisation

Au lancement, le programme te demandera de :

1. Choisir un fichier de tableau à trier (10 à 50 000 entiers)
2. Choisir un algorithme de tri
3. Le programme affiche le tableau avant/après tri, ainsi que le temps de tri en millisecondes.

## 📈 Exemple de sortie

```
Quel tableau veux-tu trier ?
  1. tabToSortExtraShort.txt (10 valeurs)
  2. tabToSortShort.txt (50 valeurs)
  3. tabToSortLong.txt (300 valeurs)
  4. tabToSortVeryLong.txt (50000 valeurs)
Ton choix : 4

Quel algorithme de tri veux-tu utiliser ?
  a. Bubble Sort
  b. Selection Sort
  ...
  j. Bucket Sort
Ton choix : g

Temps de tri : 18.52 ms
```

## 🛠️ Personnalisation

- Tu peux ajouter tes propres tableaux dans le dossier `Storage/`
- Tu peux intégrer de nouveaux algorithmes dans `src/`

## 📜 Licence

Ce projet est libre d'utilisation à des fins pédagogiques.

---

> Ce projet a été développé dans le cadre d’un apprentissage des algorithmes et de la programmation bas niveau.
