
<img class="mainimg" src="./displayable/Capture d&apos;écran 2024-01-12 192730.png"
     alt="data illustration"
     style="margin: auto;width: 100%;height: 50%;object-fit: contain;object-position: 90% 0%;resize:none;"
     />
# Mazer

<h6>
autor : felix TTL<br>
date : 24/12/2023 - 9/1/2024 (official)<br>
version : v2 (dec 2025)
</h6>

#### requirements 

<details> 
<summary>1. gcovr, googletest, CTest installation</summary>

```bash
brew install cmake gcovr googletest
xcode-select --install
# install cmake, if not installed it's needed
brew install cmake
```

</details>

1. ❌ Clang must be installed on your device

- macos : Apple clang version 17.0.0 (clang-1700.0.13.5)
- linux : soon
- windows : maybe soon


#### fonctionnalités

- v1 charger un labyrinthe a partir d'un fichier txt
- v1 algorithme de parcours du labyrinthe pour trouver la sortie (créer le chemin solution)

- v2 maze generation with (DFS or others)
- v2 use renforcement learning ti found the exit

- v1 ecrire et enregistrer les données dans un fichier txt de sortie


#### test

- v2 CTest et googletest pour la réalisation de tests proprement (y compris les tests intrinseques au langage)

# Attention :

  - lorsque le nombre de cases est supèrieur a 9 le numéro des cases sera décalé par rapport
    a la colonne qui sera affiché (pour résoudre le probème il faudrait passer a un affichage sur 2 caractère
    mais rajouterait des contraintes sur les conditions d'affichage (affichage double))


run file with sh presets with settings (be carefull you can only compile
with all parameters with the file that include all things we need)

## to run the project

in `mazer/main/`

```bash
./run # to execute the programm
./test # compile tests
./run_test # run compiled tests
./gcovr # run gcovr using specific settings in the project
```

## technical choice

### StackTrace in C

comparison

- libunwind [CROSS 1 CODE]
- glib (GLib) (GTK) [CROSS 1 CODE]
- Boost.Stacktrace [CROSS 1 CODE]
- addr2line + backtrace (POSIX)



> [!note]
> we will compare only the code that doesn't change 
> across platforms for the dedicated Library used
> (except if it change just a bit with minor changes)
> $\rightarrow$ that's our constraint


- Boost.StackTrace

Boost.StackTrace : https://www.boost.org/doc/libs/master/doc/html/stacktrace/getting_started.html


- eazy to understand, to use
- good, clear documentation with examples

$\rightarrow$ taken for the project

---

Solution|unique code|Portable|Précision (lines/files)|Complexity
|--|--|--|--|--|
Boost.Stacktrace|yes|★★★★★|★★★★★|weak
libunwind + wrapper|yes*|★★★★★|★★★★★|Average
GLib|yes|★★★★☆|★★★☆☆|weak
addr2line + backtrace|no|★★★☆☆|★★★★☆|High
Cpptrace|yes|★★★★★|★★★★☆|weak

\* : his API and his implementation change a bit depending on the platform

<!-- end page -->
