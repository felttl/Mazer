#!/bin/sh -e

clear

# installation des modules nécessaires si ils ne sont pas installés :
# installation idempotente
# si mot de passe nécessaire entrer mot de passe



# const only var are in functs
first=$1
second=$2
third=$3
fourth=$4
testparam=$5

unknowparam=$n
globalparam=$@
numberofparam=$#

declare -a effet=() 
declare -a texte=()
declare -a fond=()

colorformat="\033[$effet;3$texte;$fond0m element_message \033]$effet;3$texte;$fond0m"
#("\033[0;32;40m elements \033]0;32;40m")

# my builtins
abs () {
	local number=$1
	if [[ $number -lt 0 ]] ; then
		echo $((-1*$number))
	else	
		echo $number
	fi
}


get_index_list () {
	local liste=$1  # ( 0 0 0 0 0 )
	local element=$2 # 1 or 0 by example
	local compteur=0
	result=-1 # defaut non found
	while compteur != ; do
		if [[ $element == $i ]]; then
			result=0
		fi
	done 
}

colors () {
	declare -a namecolors=( "noir" "rouge" "vert" "orange" "bleu" "rose" "cyan" "blanc" )
	local text=$1	
	local coloruser={1..$#}
	# not bg required becuase same colors just not in same
	# zone in unicode
	for i in $coloruser; do echo $i; done
	printf "\033[0;32;40m $text \033]0;32;40m"

}
#colors 4 6 9 66 9 6  # test

boolean_for_code_error () {
	local returner=false
	if [[ $1 == 0 ]]; then
		returner=true
	fi
	return $returner
}

decompte () { 	# decompte
  	local a=$1  # numberof decompte
	local msg=$2  	# msg package decompte
	for (( i=$a; i>0; i-- )); do
		sleep 1	
		printf "$i $msg \r"					
	done	
}
#decompte $first #récupère l'entrée 1 de l'appel du fichier et les passes
# dans la fonction exemple : sh TD* 4 atttendra 4 secondes 




check_sys () {
	# create folder for testing which sys we are
	temporary=$(mktemp verifi.XXXXXXX)
	echo "#!bin/bash" > $temporary
	yum >> $temporary
	testerror_yum=$(echo $?)
	clear
	apt >> $temporary
	testerror_apt=$(echo $?)
	clear
	rm "$temporary"
	local becarefull_msg="s'il vous plaît installez Ubuntu"
	if [[ $testerror_apt == 0 ]] ; then
		echo "tout est bon il manque la vérification des modules linux pour les modules"
	elif [[ $testerror_yum == 0 ]] ; then
		echo -e "\nj'aime aussi Almalinux mais, pour lancer la
conversation veuillez utilisez Ubuntu afin de lancer le programe
avec facilité et faciliter l'utilisation des modules requis"
	elif [[ $testerror_yum == 0 && $testerror_apt == 0 ]] ; then
		echo -e "quel système utilisez vous ? \n $becarefull_msg "
	else
		echo $becarefull_msg
	fi
	echo	#empty space
	echo
}
    

choose_module_to_install () {
	# default is one
	local norepeat=false
	for mod in $@ ; do
		case $mod in
			"eyes") 
				# eyes command
				sudo apt install x11-apps;;
			"talk") 
				# talking command(3:)
				sudo apt install cowsay;;
			"tchat") 
				sudo apt install cowsay;;
			"discussion") 
				sudo apt install cowsay;;
			"train") 
				# train moving command
				sudo apt install sl;;
			"rain") 
				# random rain command
				sudo apt install cmatrix;;
			"fortune") 
				# random test appears command (with fortune keyword)
				sudo apt install fortune-mod;;
			"all") 
				for module in "x11-apps" "cowsay" "sl" "cmatrix" "fortune-mod" ; do
					sudo apt install $module
				done
				norepeat=true;;
			*) local clear; echo "module(s) installés"
		esac
		if [[ $norepeat == true ]] ; then
			break
		fi
	done
}

##########################################################################
welcome () {
	echo "---------------------------------------------------"
	echo "------- Bienvenu dans la discussion shell ---------"
	echo -e "---------------------------------------------------\n"
}

# schema :
# cowsay -f /usr/share/cowsay/cows/ANIMAL_NAME.cow MESSAGE  
conversation () {
	echo -e "début de conversation : \n
	avant de commencer je vous conseil de dézoomer un peu votre fenêtre \n"
	local bon_imc=$(echo "(18.5 + 25)/2" | bc -l)
	local nom_ane="pony"
	local link="/usr/share/cowsay/cows"	# text shortcut (minimize size of script)
	local pass="passer->->->"
	local declare -a age=()
	local current_home=$(ls /home)

	cowthink -f "$link/pony.cow" "quel est le nom de la tortue ?"
	sleep 1
	cowsay -f "$link/turtle.cow" "mon nom est :"
	echo -n " --> "
	read nom_tortue	# turtle input name
  	bloc_ane="$(echo -e "$nom_ane \n quel est mon répertoire /home actuel ?")"
	cowthink -f "$link/pony.cow" "$bloc_ane"
	echo "appuyez sur entrer pour passer $passer"
	read
	bloc_tortue="$(echo -e "$nom_tortue \n ton chemin /home $nom_ane est : \n $current_home")"
	cowsay -f "$link/turtle.cow" "$bloc_tortue"
	echo $pass
	read
  	bloc_ane="$(echo -e "$nom_ane \n quel est mon répertoire courant alors ?")"	
	cowsay -f "$link/pony.cow" "$bloc_ane"
	echo $pass
	read
  	bloc_tortue="$(echo -e "$nom_tortue \n ton répertoire courant $nom_ane est : $(pwd)")" ;
  	cowsay -f "$link/turtle.cow" "$bloc_tortue"
	echo $pass
	read

	# continuer de coder cette partie (on demande les valeurs aux deux pour comparer leurs imc entre eux)
	# il faut ensuite comparer les imcd des deux individu et proposer des solutions pour améliorer leur imc si (nécessaire)

  	bloc_ane="$(echo -e "$nom_ane \n peux tu me créer un répertoire avec la taille l'Age et le poids ? $nom_tortue ?")"
  	cowsay -f "$link/pony.cow" "$bloc_ane"
	sleep 3
  	bloc_tortue="$(echo -e "$nom_tortue \n bien sûr donne moi juste ton âge $nom_ane : ")" ;
  	cowsay -f "$link/turtle.cow" "$bloc_tortue"
	nom=$nom_ane
	read age
	bloc_tortue="$(echo -e "$nom_tortue \n ta taille en mètres (. a la place de virgules) $nom_ane : ")" ;
  	cowsay -f "$link/turtle.cow" "$bloc_tortue"	
	read taille
	echo $pass
	read 		
	bloc_tortue="$(echo -e "$nom_tortue \n et enfin ton poids  (valeur avec . comme précédemment) $nom_ane : ")" ;
  	cowsay -f "$link/turtle.cow" "$bloc_tortue"		
	read poids
	echo $pass
	read 	
	bloc_ane="$(echo -e "$nom_ane \n et voila j'ai fini et tu fais comment pour mettre dans un fichier ? $nom_tortue : ")" ;
  	cowsay -f "$link/pony.cow" "$bloc_ane"	
	sleep 1
	bloc_tortue="$(echo -e "$nom_tortue \n C'est trés simple $nom_ane il suffit d'utiliser la commande qui 
	contient t'es entrées avec > et un nom de fichier déja créé ou 
	non pour créeer un nouveau fichier permettant d'ajouter les 
	nouvelles données dans le fichier imc.txt que tu m'as demandé 
	pour récupérer les valeurs on utilise $(elems) avec elems des 
	éléments interpréter ou complilé c'est comme si on lançais le code
	qui se trouve a l'intèrieur dirrectement dans le terminal ")" ;
  	cowsay -f "$link/turtle.cow" "$bloc_tortue"		
	sleep 20
	echo $pass
	read 	
	bloc_ane="$(echo -e "$nom_ane \n Ah d'accord. $nom_tortue ")" ;
  	cowsay -f "$link/pony.cow" "$bloc_ane"		
	# création des informations et afffectation dans un fichier créé à la volée
	k=" nom = $nom \n age = $age \n taille = $taille \n poids = $poids \n" 
	#calcul de l'imc
	immc=$(echo "$poids/($taille)^2" | bc -l)
	echo -e "$k \n imc = $immc " > imc.txt # mais écrase le fichier d'origine si existait déja
	echo $pass
	read 
	bloc_tortue="$(echo -e "$nom_tortue \n voila le fichier est 
	créé avec les données dedans et je t'ai ajouté $nom_ane ton IMC dedans")" ;
  	cowsay -f "$link/turtle.cow" "$bloc_tortue"	
	echo $pass
	read 	
	bloc_ane="$(echo -e "$nom_ane \n Parfait merci $nom_tortue ")" ;
  	cowsay -f "$link/pony.cow" "$bloc_ane"	
	#					#
	#	partie finale	#
	#					#
	bloc_shaun_sheep="$(echo -e _______ \n "bonjour !" $nom_tortue $nom_ane: )"
  	cowsay -f "$link/sheep.cow" "$bloc_shaun_sheep"		
	sleep 1
	bloc_shaun_sheep="$(echo -e _______ \n "tu crois $nom_tortue que tu peux me faire 
	un fichier contenant les mêmes types d'informations que $nom_ane mais avec mes propres informations ?"  )"
  	cowsay -f "$link/sheep.cow" "$bloc_shaun_sheep"	
	sleep 1
	bloc_tortue="$(echo -e "$nom_tortue \n Oui il me faut juste un peut de temps
	... donc donnes moi les informations, ton nom d'abord :")" ;
  	cowsay -f "$link/turtle.cow" "$bloc_tortue"	
	read nom_mouton
	bloc_tortue="$(echo -e "$nom_tortue \n ton Âge ensuite $nom_mouton")" ;
  	cowsay -f "$link/turtle.cow" "$bloc_tortue"	
	declare -a meilleur_imc=( $immc )
	read age
	bloc_tortue="$(echo -e "$nom_tortue \n ta taille ensuite $nom_mouton")" ;
  	cowsay -f "$link/turtle.cow" "$bloc_tortue"	
	read taille
	bloc_tortue="$(echo -e "$nom_tortue \n et pour finir ton poids $nom_mouton")" ;
  	cowsay -f "$link/turtle.cow" "$bloc_tortue"	
	read poids	
	bloc_tortue="$(echo -e "$nom_tortue \n et C'est bon j'ai tout et je te 
	fais un fichier nommé imcmouton.txt $nom_mouton")" ;
  	cowsay -f "$link/turtle.cow" "$bloc_tortue"	
	k=" nom = $nom \n age = $age \n taille = $taille \n poids = $poids \n" 
	#calcul de l'imc
	immc=$(echo "$poids/($taille)^2" | bc -l)  # cette expression est juste et j'ai passsé des jours dessus pour que ça marche
	meilleur_imc=( ${meilleur_imc[@]} $immc )
	echo -e "$k \n imc = $immc " > imcmouton.txt 	
	# éventuellement faire une liste pour pouvoir ajouter 
	# des données et garder les anciennes intactes
	signe="" 
	result=""
	msg_conseil=""




	imc_compare () {
		local personne=$1
		local imc=$2
		min="-3.12964876033057851239"
		max="3.37035123966942148761"
		if [[ $(echo "$imc-$bon_imc" | bc -l) -gt $max ]]; then
			signe=">"
			msg_conseil="pour avoir un meilleur imc $personne doit faire plus de sport et manger moins gras"
		elif [[ $( echo "$imc-$bon_imc" | bc -l) -lt $min ]]; then
			signe="<"
			msg_conseil="$personne doit prendre du poids et manger plus"		
		else
			signe="="
			result="$personne a une bonne imc garde la ligne !"
		fi
	}

	if [[ $(abs $( echo "${meilleur_imc[0]}-$bon_imc" | bc -l)) -gt $(abs $( echo "${meilleur_imc[1]}-$bon_imc" | bc -l)) ]]; then
		result="$nom_ane à un meilleur imc"
	elif [[ signe == ">" ]]; then
		result="$nom_mouton à un meilleur imc"
	else
		result="$nom_mouton et $nom_ane ont tous les deux des bons imc"
	fi
	imc_compare $nom_ane ${meilleur_imc[0]}
	echo $msg_conseil
	imc_compare $nom_mouton ${meilleur_imc[1]}
	echo $msg_conseil
	#imc_compare "julien" ${meilleur_imc[0]}


	bloc_tortue="$(echo -e "$nom_tortue \n l'imc de $nom_ane est $signe à l'imc de $nom_mouton
	$nom_ane \n imc de  $nom_mouton est de ${meilleur_imc[0]} et celle de $mouton est de ${meilleur_imc[1]} donc $result ")" ;
  	cowsay -f "$link/turtle.cow" "$bloc_tortue"
	# bloc a 4 -
	sleep 2
	bloc_tortue="$(echo -e "$nom_tortue \n au revoir $nom_ane, $nom_mouton \n merci $(ls /home )")" ;
  	cowsay -f "$link/turtle.cow" "$bloc_tortue"

}


countdown () {
	# if one arg > 0
	local a=$1
	if [ $1 == "" ]; then
		$a=1	# defaut value for non input	
	elif [ "$1" -it "0" ]; then
		a=$( abs $a )
	fi
	echo "les données construite vont être détruites dans :"	
	decompte $a "seconde(s)"
}


	

del_data () {
	echo -e "les données vont être supprimées"
	countdown 30
	# clean (supprime tout ce qui a été créé pour ne pas surcharger l'ordinateur)
	unset immc poids taille nom nom_ane nom_mouton nom_tortue bloc_ane bloc_tortue bloc_shaun_sheep
	rm imc.txt imcmouton.txt 
	echo "données effacées"
}


# l'environnement doit etre stable pour aviter les interactions parasites qui pourrait modifier ce que fait le code
# les varables ne doivent pas déja avoir étées créé sinon il est possible d'avoir des beugs
main () {
	echo "veuillez utiliser la commande 'bash' pour lancer le fichier au lieu de 'sh'
car il pourrait avoir des fonctionnalités non prises en charge notamment 
a causes des versions différentes des GNU

le fichier se charge du reste..."
	check_sys
	choose_module_to_install "all"
	welcome

	conversation

	del_data # clear data

}
#main

#printf "\e[32mmmm \e]32\n"
main




#fixed end page
