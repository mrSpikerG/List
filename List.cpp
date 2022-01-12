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

			this->tail = tmp->next;
		}
		this->size++;
	}


	void show() {
		if (size != 0) {
			Node<T>* tmp = this->head;

			while (tmp != nullptr) {
				cout << "prev: " << tmp->prev << "\tthis: " << tmp << "\tTnext: " << tmp->next << "\tvalue: " << tmp->value << "\n";
				tmp = tmp->next;
			}
		}
		else {
			cout << "\n\nNULL\n\n";
		}
	}

	void remove(int num) {

		if (isIn(num) == true) {
			Node<T>* tmp = this->head;
			if (this->head->value == num) {
				this->head->next->prev = nullptr;
				this->head = this->head->next;
			}
			else {
				if (this->tail->value == num) {
					this->tail->prev->next = nullptr;
					this->tail = this->tail->prev;
				}
				else {
					while (tmp->next != nullptr) {

						if (tmp->value == num) {
							break;
						}
						tmp = tmp->next;
					}
					tmp->next->prev = tmp->prev;
					tmp->prev->next = tmp->next;
				}
			}
			this->size--;
		}
	}

	bool isIn(int num) {
		Node<T>* tmp = this->head;
		bool checker = false;
		while (tmp != nullptr) {
			if (tmp->value == num) {
				checker = true;
			}
			tmp = tmp->next;
		}
		return checker;
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
	MyTestList.add(4);
	MyTestList.add(5);

	MyTestList.remove(5);

	MyTestList.show();

	//cout << "\n" << MyTestList.isIn(3)<<"\n";

}

