#include<stdio.h>
#include<stdlib.h>

typedef int dado;

struct Node {

    dado valor;
    Node* prox;

    Node() {
        prox = NULL;
    }

    Node(dado _valor) {
        valor = _valor;
        prox = NULL;
    }

    void print() {
        printf("%d -> ", valor);
    }

};

struct List {

    Node* cabeca, * cauda;
    int size;

    List() {
        cabeca = NULL;
        cauda = NULL;
        size = 0;
    }

    /*
        empty = testa se a lista está vazia ou não
        size = retorna o tamanho da lista
        pushFront = insere no inicio
        pushBack = insere no final
        popFront = remove no inicio
        popBack = remove no final
    */

    bool empty() { //O(1)
        return (cabeca == NULL) && (cauda == NULL);
    }

    Node* pushBack(dado valor) { //O(1)
        Node* novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        }
        else {
            cauda->prox = novo;
            cauda = novo;
        }
        size++;
        return cauda;
    }

    Node* pushFront(dado valor) { //O(1)
        Node* novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        }
        else {
            novo->prox = cabeca;
            cabeca = novo;
        }
        size++;
        return cabeca;
    }

    /*int size() { //O(n) //função inutil! uso de size++--
        int s = 0;
        Node *tmp = cabeca;
        while (tmp != NULL) {
            s++;
            tmp = tmp->prox;
        }
        return s;
    }*/

    void print() { //O(n)
        Node* tmp = cabeca;
        while (tmp != NULL) {
            tmp->print();
            tmp = tmp->prox;
        }
        printf("\n");
    }

    Node* popFront() { //O(1)
        if (!empty()) {
            if (cabeca == cauda) { // Apenas 1 elemento
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            }
            else {
                Node* tmp = cabeca;
                cabeca = cabeca->prox;
                delete(tmp);
            }
            size--;
        }
        return cabeca;
    }

    Node* popBack() { //O(n)
        if (!empty()) {
            if (cabeca == cauda) {
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            }
            else {
                Node* penultimo = cabeca;
                while (penultimo->prox != cauda) {
                    penultimo = penultimo->prox;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->prox = NULL;
            }
            size--;
        }
        return cauda;
    }

    Node* find(dado x) { //O(n)
        Node* tmp = cabeca;
        while (tmp != NULL) {
            if (tmp->valor == x) {
                return tmp;
            }
            tmp = tmp->prox;
        }
        return NULL;
    }

    Node* clear() { //Limpa toda a lista e zera o tamanho.
        int cont = 0;
        while (cont != size) {
            Node* tmp = cabeca;
            cabeca = cabeca->prox;
            delete(tmp);
            cont++;
        }
        size = 0;
        return cabeca;
    }

    Node* popBackN(dado valor) { //apaga os N valores do fim da lista.
        if (!empty()) {
            if (size < valor) {
                clear();
            }
            else {
                int cont = 0;
                while (cont != valor) {
                    Node* penultimo = cabeca;
                    while (penultimo->prox != cauda) {
                        penultimo = penultimo->prox;
                    }
                    delete(cauda);
                    cauda = penultimo;
                    cauda->prox = NULL;
                    cont++;
                    size--;
                }

            }

        }
        return cauda;
    }

    Node* popSecond() { //apaga o segundo elemento da lista.
        if (cauda == cabeca) {
            NULL;
        }
        else {
            Node* oldCabeca = cabeca;
            oldCabeca = cabeca;
            cabeca = cabeca->prox;
            popFront();
            oldCabeca->prox = cabeca;
            cabeca = oldCabeca;
        }
        return cabeca;
    }

    Node* pushBackS() { //Insere o tamanho da lista no final da mesma.
        pushBack(size);
        return cauda;
    }

    Node* pushBackN(dado valor) { //Insere no final da lista valores de 1 até N.
        int cont = 1;
        while (cont <= valor) {
            pushBack(cont);
            cont++;
        }
        return cauda;
    }

    Node* pushPenul(dado valor) { //Insere valor na peltima posição da lista.
        Node* novoValor = new Node(valor);
        Node* penultimo = cabeca;
        while (penultimo->prox != cauda) {
            penultimo = penultimo->prox;
        }
        penultimo->prox = novoValor;
        novoValor->prox = cauda;
        size++;
        return cauda;
        
    }

    Node* PopN(dado valor) { //Apaga valor N da lista.
        if (size < valor) {
            NULL;
        }
        else {
            
            Node* posicao = cabeca;
            int cont = 0;
            while (cont > valor) {
                posicao = posicao->prox;
                cont++;
            }
            Node* tmp = cabeca;
            tmp = posicao;
            Node* tmp2 = posicao->prox;
            Node* tmp3 = tmp2->prox;
            delete(tmp2);
            size--;
            tmp->prox = tmp3;
        }
        return cabeca;
    }
};

int main() {
    List l;
    /* l.pushBack(50);
     l.pushBack(30);
     l.pushBack(10);*/
    l.pushFront(20);
    l.pushFront(10);
    l.pushFront(100);
    l.pushFront(62);
    l.pushFront(12);
    //l.popBackN(3);
    //l.popSecond();
    //l.pushBackS();
    //l.pushBackN(5);
    //l.pushPenul(59);
    l.PopN(2);
    l.print();
    printf("Tamanho da lista: %d\n", l.size);
    return 0;
}
