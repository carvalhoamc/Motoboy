#include <iostream>
#include <vector>

using namespace std;

int maximo(int x, int y)
{
    return (x > y)? x : y;
}

int Calcula01(int capacidade, vector<int> pesos, vector<int> itens, int n)
{
    int i, j;
    int matriz[n+1][capacidade+1]; //Padrao C99

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= capacidade; j++)
        {
            //se a capacidade ou o numero de itens for zero valor ótimo é zero.
            // Nao se pode por nada na mochila
            if (i==0 || j==0)
                matriz[i][j] = 0;
                //Se peso for menor que a capacidade cabe mais um item na mochila

                //decide se vai colocar mais um item na mochila ou não.
                // Se o que está lá for maior que o novo item, não há mudanças.
                //caso contrario acrecenta um item
            else if (pesos[i-1] <= j)
                matriz[i][j] = maximo(itens[i-1] + matriz[i-1][j-pesos[i-1]], matriz[i-1][j]);
            else
                //Não cabe novo item e passa o estado anterior da
                //mochila para o próximo passo iterativo
                matriz[i][j] = matriz[i-1][j];
        }
    }
    //retorna o valor ótimo que é a crista da matriz do CLRS capt 15, pag, 275
    return matriz[n][capacidade];
}



void Calcula02(int capacidade, vector<int> pesos, vector<int> itens, int n) {
    int i, j;
    int matriz[n + 1][capacidade + 1]; //Padrao C99

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= capacidade; j++) {
            if (i == 0 || j ==
                          0) //se a capacidade ou o numero de itens for zero valor ótimo é zero. Nao se pode por nada na mochila
                matriz[i][j] = 0;
            else if (pesos[i - 1] <= j) //Se peso for menor que a capacidade cabe mais um item na mochila
//decide se vai colocar mais um item na mochila ou não. Se o que está lá for maior que o novo item, não há mudanças.
//caso contrario acrecenta um item
                matriz[i][j] = maximo(itens[i - 1] + matriz[i - 1][j - pesos[i - 1]], matriz[i - 1][j]);
            else
//Não cabe novo item e passa o estado anterior da mochila para o próximo passo iterativo
                matriz[i][j] = matriz[i - 1][j];
        }
    }
//retorna o valor ótimo que é a crista da matriz do CLRS capt 15, pag, 275
    matriz[n][capacidade];

    int linha = n;
    i = capacidade;
    vector<int> itensSelecionados;

    while (i > 0) {
        if (matriz[linha][i] - matriz[linha - 1][i - 1] == itens[linha - 1]) {
            //O elemento i está na mochila
            if(linha > 0){
                itensSelecionados.push_back(linha);
            }

            i--;
            linha = linha - 1;
        } else if (matriz[linha][i] > matriz[linha][i - 1]) {
            linha--;
        } else {
            i--;
        }
    }

    cout << "itens: ";
    for (i = 0; i < itensSelecionados.size(); i++) {
        cout << itensSelecionados[i] << ", ";
    }
    cout << "\n";
}

int main(){

    int N = 0;                      //numero de itens
    int P = 0;                      //capacidade
    int t = 0;
    int q = 0;

    vector<int> tempo;              //peso
    vector<int> quantidade;         //valor do item

    for(;;){

        cin >> N;
        cin >> P;

        if(N == 0) exit(0);

        tempo.clear();
        quantidade.clear();

        for(int i = 0; i < N; i++){

            cin >> t >> q;
            tempo.push_back(t);
            quantidade.push_back(q);

        }


        Calcula02(P,quantidade,tempo, N);
        //cout << " min." << endl;
    }

    return 0;
}

//for (i = 0; i <= n; i++) {
//    cout << endl;
//    for (j = 0; j <= capacidade; j++) {
//        cout << matriz[i][j] << "  ";
//    }
//}