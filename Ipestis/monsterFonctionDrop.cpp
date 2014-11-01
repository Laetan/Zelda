void Monstre::drop()
{
    int itemDrop = Qrand() % 100 + 1;

    if( itemDrop <= 40) return 0;
    if( itemDrop >40 && itemDrop <= 60){
        new Objets(map, "rubisG", getPosX, getPosY);
    }
    if( itemDrop >60 && itemDrop <= 80){
        new Objets(map, "coeur", getPosX, getPosY);
    }
    if( itemDrop >80 && itemDrop <= 90){
        new Objets(map, "rubisB", getPosX, getPosY);
    }
    if( itemDrop >90 && itemDrop <= 95){
        new Objets(map, "rubisR", getPosX, getPosY);
    }
    if( itemDrop >95 && itemDrop <= 100){
        new Objets(map, "fee", getPosX, getPosY);
    }
}
