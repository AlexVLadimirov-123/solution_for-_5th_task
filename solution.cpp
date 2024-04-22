#include <iostream>
using namespace std;

class CircularQueue {
 private:
  int front, rear, size;
  int* arr;

 public:
  CircularQueue(int s) {
    front = -1;
    rear = -1;
    size = s;
    arr = new int[size];
  }
  ~CircularQueue() { delete[] arr; }
  bool isFull() {
    if (rear == front) {
      return true;
    }
    return false;
  }

  bool isEmpty() {
    if (front == -1) {
      return true;
    }
    return false;
  }

  void enterqueue(int value) {
    if (isFull()) {
      cout << "Queue is full" << endl;
    } else {
      if (front == -1) front = 0;
      rear = (rear + 1) % size;
      arr[rear] = value;
      cout << value << "Entered to queue" << endl;
    }
  }
};

int main() {
  CircularQueue q(5);

  q.enterqueue(1);
  q.enterqueue(2);
  q.enterqueue(3);
  q.enterqueue(4);
  q.enterqueue(5);
}
