#include <stdio.h>
int stato;
void locked_coin(void) {
    printf("moneta inserita, sblocco\n");
    stato = 1;
}
void locked_push(void) {
    printf("moneta non inserita\n");
    stato = 0;
}

void unlocked_coin(void) {
    printf("moneta già inserita\n");
    stato = 1;
}

void unlocked_push(void) {
    printf("Inserisci moneta\n");
    stato = 0;
}

int main(){
    typedef void (*AzioneStato)(void);
    AzioneStato tabella[2][2];

    tabella[0][0] = locked_coin;
    tabella[0][1] = locked_push;
    tabella[1][0] = unlocked_coin;
    tabella[1][1] = unlocked_push;

    tabella[stato][0]();  // COIN
    printf("%d\n", stato);
    tabella[stato][1]();  // PUSH
    printf("%d\n", stato);
    tabella[stato][0]();
    printf("%d\n", stato);
    tabella[stato][1]();
    printf("%d\n", stato);
    return 0;
}