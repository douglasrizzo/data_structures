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
void testStack(Stack<T> *s, int amount) {
  cout << "Inserting " << amount << " values in the " << s->getName() << "...\n";
  try {
    for (int i = 1; i <= amount; i ++) {

      s->push(i);
      cout << i << " ";
    }

    cout << endl << "Removing values from the stack...\n";
    while (s->getSize() > 0) {
      if (s->getSize() % 10 == 0) {
        cout << "[" << s->peek() << "] ";
      }
      cout << s->pop() << " ";
    }
  }
  catch (const std::out_of_range &oor) {
    std::cout << "An error occurred: " << oor.what() << '\n';
  }
  cout << endl;
}

template<class T>
void testQueue(Queue<T> *q, int amount) {
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
    std::cout << "An error has occurred: " << oor.what() << '\n';
  }
  cout << endl;
}

void printList(LinkedList<int> *l) {
  Iterator<int> iter = l->iterator();
  while (iter.hasNext())
    cout << iter.next() << " ";
  cout << endl;
}

template<class T>
void testList(LinkedList<T> *l, bool order) {

  cout << "\nInserindo valores na lista do tipo " << l->getName() << "...\n";

  int *values = new int[8]{3, 1, 2, 8, 7, 2, 5, 2};
  int *orders = new int[8]{0, 0, 2, 1, 4, 2, 4, 5};

  if (order) {
    for (int i = 0; i < 8; i ++) {
      l->insert(values[i], orders[i]);
      printList(l);
    }
  }
  else {
    for (int i = 0; i < 8; i ++) {
      l->insert(values[i]);
      printList(l);
    }
  }

  delete[] values, orders;

  cout << "\nRemovendo valores da lista...\n";
  l->remove(4);
  printList(l);
  l->remove(1);
  printList(l);
  l->remove(3);
  printList(l);
  l->remove(1);
  printList(l);
  l->remove(1);
  printList(l);
  l->remove(0);
  printList(l);
}

void testUnderflow() {
  cout << "===============================================\n"
       << "= Testing underflow in static-size structures =\n"
       << "===============================================\n";

  int iters = 6;
  try {
    StaticStack<int> s1 = StaticStack<int>(new int[3]{3, 1, 2});
    for (int i = 0; i < iters; i ++)
      s1.pop();
  }
  catch (const std::out_of_range &oor) {
    std::cout << "An error has occurred: " << oor.what() << '\n';
  }

  try {
    DynamicStack<int> s2 = DynamicStack<int>(new int[3]{3, 1, 2});
    for (int i = 0; i < iters; i ++)
      s2.pop();
  }
  catch (const std::out_of_range &oor) {
    std::cout << "An error has occurred: " << oor.what() << '\n';
  }

  try {
    StaticQueue<int> q1 = StaticQueue<int>(new int[3]{3, 1, 2});
    for (int i = 0; i < iters; i ++)
      q1.dequeue();
  }
  catch (const std::out_of_range &oor) {
    std::cout << "An error has occurred: " << oor.what() << '\n';
  }

  try {
    DynamicQueue<int> q2 = DynamicQueue<int>(new int[3]{3, 1, 2});
    for (int i = 0; i < iters; i ++)
      q2.dequeue();
  }
  catch (const std::out_of_range &oor) {
    std::cout << "An error has occurred: " << oor.what() << '\n';
  }

  try {
    LinkedList<int> l1 = LinkedList<int>(new int[3]{3, 1, 2});
    for (int i = 0; i < iters; i ++)
      l1.remove(0);
  }
  catch (const std::out_of_range &oor) {
    std::cout << "An error has occurred: " << oor.what() << '\n';
  }

  try {
    OrderedList<int> l2 = OrderedList<int>(new int[3]{3, 1, 2}, compare);
    for (int i = 0; i < iters; i ++)
      l2.remove(0);
  }
  catch (const std::out_of_range &oor) {
    std::cout << "An error has occurred: " << oor.what() << '\n';
  }
}

void testOverflow() {
  cout << "==============================================\n"
       << "= Testing overflow in static-size structures =\n"
       << "==============================================\n";
  testStack(new StaticStack<int>(17), 18);
  testQueue(new StaticQueue<int>(17), 18);
}

void testProlongedUse() {
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
    if (i % (max_iters / 1000) == 0) {
      cout << "Structure\tS\t\t\tQ\t\t\tLL\t\t\tOL\n"
           << "Size\t\t" << s.getSize() << "\t\t\t" << q.getSize() << "\t\t\t" << l.getSize() << "\t\t\t"
           << o.getSize() << "\n"
           << "Insertions\t" << si << "\t\t\t" << qi << "\t\t\t" << li << "\t\t\t" << oi << "\n"
           << "Removals\t" << so << "\t\t\t" << qo << "\t\t\t" << lo << "\t\t\t" << oo << "\n\n";
    }

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
  cout << "END!";
}

int main() {
  cout
      << "************************\n" << "Data structure test\n"
      << "Values in brackets represent peeks, without removals"
      << "\n*********************\n\n";

  testStack(new StaticStack<int>(17), 15);
  testQueue(new StaticQueue<int>(17), 15);
  testStack(new DynamicStack<int>(), 40);
  testQueue(new DynamicQueue<int>(), 40);
  testList(new LinkedList<int>(), true);
  testList(new OrderedList<int>(compare), false);
  testList(new OrderedList<int>(compare), true);

  testOverflow();
  testUnderflow();

  testProlongedUse();

  return 0;
}
