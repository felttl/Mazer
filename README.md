
<img class="mainimg" src="./displayable/Capture d&apos;écran 2024-01-12 192730.png"
     alt="Markdown Monster icon"
     style="margin: auto;width: 100%;height: 50%;object-fit: contain;object-position: 90% 0%;resize:none;"
     />
# Mazer
<h6>
autor : felix TTL<br>
date : 24/12/2023 - 9/1/2024 (official)
</h6>

#### fonctionnalités principales

- charger un labyrinthe a partir d'un fichier txt
- algorithme de parcours du labyrinthe pour trouver la sortie



#### fonctionnalités supplémentaires

- génération de labyrinthe aléatoirement avec l'algorithe DFS
- ecrire et enregistrer les données dans un fichier txt de sortie


#### test

- les fichiers de test sont toujours des fichiers *.c
- les ficiers de test doivent toujours utiliser un fichier externe en *.h pour faire le test 
  ce qui permet de pouvoir utiliser les méthodes ou fonctions a l'extérieur du fichier de test
  sans géner les fichier de tests


# Attention :

  - lorsque le nombre de cases est supèrieur a 9 le numéro des cases sera décalé par rapport
    a la colonne qui sera affiché (pour résoudre le probème il faudrait passer a un affichage sur 2 caractère
    mais rajouterait des contraintes sur les conditions d'affichage (affichage double))

##### Tasks :
<h6>
     outils terminés
</h6>

  -    [x] display
  -    [ ] generate
  -    [x] load
  -    [x] save
  -    [x] pion chainée
  -    [x] get_borders
  -    [ ] DFS

###### fonctions annexes

methodes/fonctions de gestion des pions

  -    [x] create pion
  -    [x] forward right
       -    [ ] debugg
  -    [X] shorterst_vect
       -    [ ] debugg
  -    [ ] DFS
       -    [ ] debugg
  -    [x] add_path
  -    [x] insert
  -    [x] remove_at
  -    [x] free_pion_chain

</h6>