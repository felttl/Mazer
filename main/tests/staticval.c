
// variables globales non constantes
#ifndef isdefined
#define isdefined 0
    static int lines=0, cols=0;
#endif



/**
 * 
 * permet d'utiliser la même variable a 
 * travers plusieurs fichier
 * sans avoir plusieurs fois les déclarations
 * isdefined permet de savoir si elle-même est déja crée ou non
 * si c'est pas le cas on va créer d'autres variable dans un define
 * la variable isdefined sert uniquement a savoir si un appel est déja
 * effectué dans un fichier importé
*/