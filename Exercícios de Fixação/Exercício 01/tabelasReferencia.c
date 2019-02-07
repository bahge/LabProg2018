float tabelaPreco(int codigo){
    if ( codigo > 0 && codigo < 11) {
        return 10;
    } else if ( codigo > 10 && codigo < 21 ) {
        return 15;
    } else if ( codigo > 20 && codigo < 31 ) {
        return 20;
    } else if ( codigo > 30 && codigo < 41 ) {
        return 25;
    } else {
        return -1;
    }
}

float tabelaDesconto(int valor){
    if ( valor > 500) {
        return 15;
    } else if ( valor > 250 && valor <= 500 ) {
        return 10;
    } else if ( valor <= 250 ) {
        return 5;
    } else {
        return 0;
    }
}
