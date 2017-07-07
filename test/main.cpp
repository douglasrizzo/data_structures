#include <iostream>
#include <random>
#include <ctime>
#include "DynamicStack.hpp"
#include "StaticQueue.hpp"
#include "StaticStack.hpp"
#include "DynamicQueue.hpp"
#include "LinkedList.hpp"
#include "OrderedList.hpp"

using namespace std;

int compare(int a, int b) {

  if (a < b)
    return - 1;
  if (a > b)
    return 1;
  return 0;
}

template<class T>
void testaPilha(Stack<T> *s, int amount) {
  cout << "Inserindo " << amount << " valores na pilha de tipo " << s->getName() << "...\n";
  try {
    for (int i = 1; i <= amount; i ++) {

      s->push(i);
      cout << i << " ";
    }

    cout << endl << "Removendo valores da pilha...\n";
    while (s->getSize() > 0) {
      if (s->getSize() % 10 == 0) {
        cout << "[" << s->peek() << "] ";
      }
      cout << s->pop() << " ";
    }
  }
  catch (const std::out_of_range &oor) {
    std::cout << "Ocorreu um erro: " << oor.what() << '\n';
  }
  cout << endl;
}

template<class T>
void testaLista(LinkedList<T> *l, int amount) {
  try {
    cout << "Inserindo " << amount << " valores na fila de tipo " << l->getName() << "...\n";
    for (int i = 1; i <= amount; i ++) {
      l->insert(i);
      cout << i << " ";
    }

    cout << endl << "Removendo valores da fila...\n";

    while (l->getSize() > 0) {
      if (l->getSize() % 10 == 0) {
        cout << "[" << l->get(l->getSize() - 1) << "] ";
      }
      cout << l->remove(0) << " ";
    }
  }
  catch (const std::out_of_range &oor) {
    std::cout << "Ocorreu um erro: " << oor.what() << '\n';
  }
  cout << endl;
}

template<class T>
void testaFila(Queue<T> *q, int amount) {
  try {
    cout << "Inserindo " << amount << " valores na fila de tipo " << q->getName() << "...\n";
    for (int i = 1; i <= amount; i ++) {
      q->enqueue(i);
      cout << i << " ";
    }

    cout << endl << "Removendo valores da fila...\n";

    while (q->getSize() > 0) {
      if (q->getSize() % 10 == 0) {
        cout << "[" << q->peek() << "] ";
      }
      cout << q->dequeue() << " ";
    }
  }
  catch (const std::out_of_range &oor) {
    std::cout << "Ocorreu um erro: " << oor.what() << '\n';
  }
  cout << endl;
}

void imprimeLista(LinkedList<int> *l) {
  Iterator<int> iter = l->iterator();
  while (iter.hasNext())
    cout << iter.next() << " ";
  cout << endl;
}

template<class T>
void testaLista(LinkedList<T> *l, bool order) {

  cout << "\nInserindo valores na lista do tipo " << l->getName() << "...\n";

  int *values = new int[8]{3, 1, 2, 8, 7, 2, 5, 2};
  int *orders = new int[8]{0, 0, 2, 1, 4, 2, 4, 5};

  if (order) {
    for (int i = 0; i < 8; i ++) {
      l->insert(values[i], orders[i]);
      imprimeLista(l);
    }
  }
  else {
    for (int i = 0; i < 8; i ++) {
      l->insert(values[i]);
      imprimeLista(l);
    }
  }

  delete [] values, orders;

  cout << "\nRemovendo valores da lista...\n";
  l->remove(4);
  imprimeLista(l);
  l->remove(1);
  imprimeLista(l);
  l->remove(3);
  imprimeLista(l);
  l->remove(1);
  imprimeLista(l);
  l->remove(1);
  imprimeLista(l);
  l->remove(0);
  imprimeLista(l);
}

void testaUnderflow() {
  cout << "=====================================\n"
       << "= Testando underflow nas estruturas =\n"
       << "=====================================\n";

  int iters = 6;
  try {
    StaticStack<int> s1 = StaticStack<int>(new int[3]{3, 1, 2});
    for (int i = 0; i < iters; i ++)
      s1.pop();
  }
  catch (const std::out_of_range &oor) {
    std::cout << "Ocorreu um erro: " << oor.what() << '\n';
  }

  try {
    DynamicStack<int> s2 = DynamicStack<int>(new int[3]{3, 1, 2});
    for (int i = 0; i < iters; i ++)
      s2.pop();
  }
  catch (const std::out_of_range &oor) {
    std::cout << "Ocorreu um erro: " << oor.what() << '\n';
  }

  try {
    StaticQueue<int> q1 = StaticQueue<int>(new int[3]{3, 1, 2});
    for (int i = 0; i < iters; i ++)
      q1.dequeue();
  }
  catch (const std::out_of_range &oor) {
    std::cout << "Ocorreu um erro: " << oor.what() << '\n';
  }

  try {
    DynamicQueue<int> q2 = DynamicQueue<int>(new int[3]{3, 1, 2});
    for (int i = 0; i < iters; i ++)
      q2.dequeue();
  }
  catch (const std::out_of_range &oor) {
    std::cout << "Ocorreu um erro: " << oor.what() << '\n';
  }

  try {
    LinkedList<int> l1 = LinkedList<int>(new int[3]{3, 1, 2});
    for (int i = 0; i < iters; i ++)
      l1.remove(0);
  }
  catch (const std::out_of_range &oor) {
    std::cout << "Ocorreu um erro: " << oor.what() << '\n';
  }

  try {
    OrderedList<int> l2 = OrderedList<int>(new int[3]{3, 1, 2}, compare);
    for (int i = 0; i < iters; i ++)
      l2.remove(0);
  }
  catch (const std::out_of_range &oor) {
    std::cout << "Ocorreu um erro: " << oor.what() << '\n';
  }
}

void testaOverflow() {
  cout << "=============================================================\n"
       << "= Testando overflow nas estruturas de tamanho pré-definido =\n"
       << "=============================================================\n";
  testaPilha(new StaticStack<int>(17), 18);
  testaFila(new StaticQueue<int>(17), 18);
}

void testaUsoSatanico() {
  time_t result = time(nullptr);
  mt19937_64 orelha;
  orelha.seed((unsigned long) std::localtime(&result));

  DynamicStack<int> s;
  DynamicQueue<int> q;
  LinkedList<int> l;
  OrderedList<int> o = OrderedList<int>(compare);

  int si = 0, qi = 0, li = 0, oi = 0;
  int so = 0, qo = 0, lo = 0, oo = 0;

  unsigned int max_iters = (unsigned int) orelha() % 10000;

  cout << max_iters << endl;

  for (int i = 0; i < max_iters; i ++) {
//        if (i % (max_iters / 1000) == 0) {
//            cout << "Estrutura\tS\t\t\t\tQ\t\t\t\tLL\t\t\t\tOL\n"
//                 << "Tamanho\t\t" << s.getSize() << "\t\t\t\t" << q.getSize() << "\t\t\t\t" << l.getSize() << "\t\t\t\t"
//                 << o.getSize() << "\n"
//                 << "Inserções\t" << si << "\t\t\t\t" << qi << "\t\t\t\t" << li << "\t\t\t\t" << oi << "\n"
//                 << "Remoções\t" << so << "\t\t\t\t" << qo << "\t\t\t\t" << lo << "\t\t\t\t" << oo << "\n\n";
//        }
    int tmp;
    if ((tmp = (int) orelha()) % 2 == 0 && ! s.isEmpty()) {
      so ++;
      s.pop();
    }
    else {
      si ++;
      s.push(tmp);
    }
    if ((tmp = (int) orelha()) % 2 == 0 && ! q.isEmpty()) {
      qo ++;
      q.dequeue();
    }
    else {
      qi ++;
      q.enqueue(tmp);
    }
    if ((tmp = (int) orelha()) % 2 == 0 && ! l.isEmpty()) {
      lo ++;
      l.remove(0);
    }
    else {
      li ++;
      l.insert(tmp);
    }
    if ((tmp = (int) orelha()) % 2 == 0 && ! o.isEmpty()) {
      oo ++;
      o.remove(0);
    }
    else {
      oi ++;
      o.insert(tmp);
    }
  }
  cout << "FIM!";
}

int main() {
//    cout
//            << "************************\n" << "Teste de estruturas de dados\n"
//            << "Valores entre colchetes representam consultas sem remoção"
//            << "\n*********************\n\n";
//
//    testaPilha(new StaticStack<int>(17), 15);
//    testaFila(new StaticQueue<int>(17), 15);
//    testaPilha(new DynamicStack<int>(), 40);
//    testaFila(new DynamicQueue<int>(), 40);
//    testaLista(new LinkedList<int>(), true);
  testaLista(new OrderedList<int>(compare), false);
  testaLista(new OrderedList<int>(compare), true);
//
//    testaOverflow();
//    testaUnderflow();

//    testaUsoSatanico();

  return 0;
}
