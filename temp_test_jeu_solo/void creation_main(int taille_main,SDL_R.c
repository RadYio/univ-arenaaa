void creation_main(int taille_main,SDL_Rect tab[]){
  int milieu = 800;
  if (taille_main == 0){
    return;
  }
  //si la main est impaire
  else if(taille_main%2==1){
    printf("impair");
    int x = milieu + 5 - (71 * (taille_main));
    for(int i=0;i<taille_main;i++){
      tab[i]=create_rectangle(x,830,144,132);
      x += 142;
    }
  }
  else{
    printf("pair");
    int x = milieu - 5 - (71 * (taille_main));
    printf("%i\n\n",x);
    for(int i=0;i<taille_main;i++){
      tab[i]=create_rectangle(x,830,144,132);
      x += 142;
    }
  }
}