// https://www.beecrowd.com.br/judge/pt/problems/view/1242
// Pilha, string

#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <iostream>

using namespace std;

bool fazLigacao(char baseASerDobrada, char baseAtual)
{
    if (baseASerDobrada == 'C')
        return baseAtual == 'F';
    if (baseASerDobrada == 'F')
        return baseAtual == 'C';

    if (baseASerDobrada == 'B')
        return baseAtual == 'S';
    if (baseASerDobrada == 'S')
        return baseAtual == 'B';
}

int main()
{
    string fita;

    while (cin >> fita)
    {

        int cont = 0;
        stack<char> pilha;

        // cout << resp << endl;
        for (int i = 0; i < fita.size(); i++)
        { // puts("entrou F");
            // Uma pilha é utilizada para que o caso da imagem
            // possa ser contemplado (F ligando com C)
            if (pilha.empty() || !fazLigacao(pilha.top(), fita[i]))
            {
                pilha.push(fita[i]);
            } // puts("colocou");}
            else
            {
                while (true)
                { // puts("entrou W");

                    if (pilha.empty())
                    {
                        // Aqui eu decremento o i para que quando o for incrementar siga o fluxo normalmente
                        // Se eu não decrementar ele acaba pulando dois, porque no elseif ele já deu i++
                        i--; // puts("saiu");
                        break;
                    }
                    else if (fazLigacao(pilha.top(), fita[i]))
                    {
                        cont++; // puts("tirou");
                        pilha.pop();
                        i++;
                        // puts("AQUI!!");
                    }

                    // F B B S C C
                    // Esse caso da 1 ligacao
                    // B e S se ligam, mas como B e C nao, F e C da ponta
                    // Nao conseguem se ligar
                    if (!pilha.empty() && !fazLigacao(pilha.top(), fita[i]))
                    {

                        i--; // puts("saiu");
                        break;
                    }

                    if (i >= fita.size())
                    {
                        i--; // puts("saiu I");
                        break;
                    }
                }
            }
        }

        printf("%d\n", cont);
    }

    return 0;
}
