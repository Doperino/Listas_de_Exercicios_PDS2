#include <iostream>
#include <string>

using namespace std;

void initVector (int *v) {
    for (int i = 0; i < 10; i++) {
        v[i] = 0;
    }
}

void readLetters (char *v, int qtt) {
    for (int i = 0; i < qtt; i++) {
        cin >> v[i];
    }   
}

void modifyString (string &phrase, char *letters, int *count, int qtt) {
    for (int i = 0; i < (int)phrase.length() ; i++) {
        for (int j = 0; j < qtt; j++) {
            if(phrase[i] == letters[j]) {
                phrase[i] = '#';
                count[j]++;
            }
        }
    } 
}

void printing (char *letters, int *count, int qtt) {
    for (int i = 0; i < qtt; i++) {
        cout << letters[i] << ' ' << count[i] << endl;
    }
}

int main () {

    //Declaração de variáveis
    int qtt_letters = 0;
    char letters[10];      
    int count[10];                     
    string phrase;

    //inicializando vetor zerado
    initVector(count);

    //Recebe quantidade  de letras
    cin >> qtt_letters;

    //Realiza a atribuição das letras ao vetor
    readLetters(letters, qtt_letters);
    
    //Recebe a frase
    getline(cin >> ws, phrase);

    //Faz a alteração da string e contagem dos caracteres alterados
    modifyString(phrase, letters, count, qtt_letters);

    //Imprimindo frase alterada
    cout << phrase << endl;

    //Imprimindo quantidade de palavras alteradas
    printing(letters, count, qtt_letters);
    
    return 0;
}