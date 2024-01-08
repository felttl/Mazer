// see : https://www.youtube.com/watch?v=R0qIYWo8igs&t=643s
// fonction de récupération de texte d'un fichier mais ayant moins de performances
// (contraites de heap suppllémentaires)
char * read_file_char_by_char_notmine(char * filename){
    // récupération du nb de lignes et colonnes
    FILE *fp=fopen(filename,"r");
    if (fp!=NULL){    
        fseek(fp, 0, SEEK_END);// récupère le nombre de caractères dans le fichier
        int length=ftell(fp);
        fseek(fp, 0, SEEK_SET); // déplace a nouveau le pointeur au début du fichier pour lecture
        char*sortie_donnee=malloc((length+1)*sizeof(char));
        char c;
        int i=0;
        while((c=fgetc(fp))!=EOF){
            sortie_donnee[i] = c;
            i++;
        }
        sortie_donnee[i]='\0';
        fclose(fp);
        return sortie_donnee;        
    } else {
        printf("problème d'ouverture\n\n");
        exit(EXIT_FAILURE);
    }

}