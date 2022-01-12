#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T value;
	Node* next;
	Node* prev;
};

template <typename T>
class List {
private:
	Node<T>* head;
	Node<T>* tail;
	unsigned long long size;
public:

	List()
	{
		this->head = nullptr;
		this->tail = nullptr;
		size = 0;
	}

	void add(int num) {

		if (head == nullptr) {
			this->head = new Node<T>;

			this->head->next = nullptr;
			this->head->value = num;
			this->head->prev = nullptr;

			//так как это первый элемент то он и является последним
			this->tail = this->head;
		}
		else {
			Node<T>* tmp = this->head;

			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = new Node<T>;

			tmp->next->prev = tmp;
			tmp->next->next = nullptr;
			tmp->next->value = num;
		}
		this->size++;
	}


	void show() {
		Node<T>* tmp = this->head;

		while (tmp != nullptr) {
			cout << "\nprev: " << tmp->prev << "\tthis: " << tmp << "\tTnext: " << tmp->next << "\tvalue: " << tmp->value;
			tmp = tmp->next;
		}


	}

	void remove(int num) {

	}

	bool isIn(int num) {

	}
	unsigned long long getsize() {
		return size;
	}

};
int main()
{
	List<int> MyTestList;

	MyTestList.add(1);
	MyTestList.add(2);
	MyTestList.add(3);

	MyTestList.show();


}

