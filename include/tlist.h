#include <iostream>

template <class T>

class tlist {
	struct Node {
		T data;
		Node* next;
		Node(T val = T(), Node* n = nullptr) {
			data = val;  
			next = n;
		}
		Node& operator = (const Node other) {
			this->data = other.data;
			delete next;
			this->next = other.next
		}
	};
	Node* first;
	public:
		tlist(): first(nullptr){}
		tlist(int n) {
			if (n < 0) throw "can create list with negative length";
			T val = 0;
			first = new Node(val, nullptr);
			Node* current = first;
			for (int i = 1; i < n; ++i) {
				Node* tmp = new Node(val, nullptr);
				current->next = tmp;
				current = current->next;
			}
		}
		tlist(int n, T value) {
			if (n < 0) throw "can create list with negative length";
			T val = value;
			first = new Node(val, nullptr);
			Node* current = first;
			for (int i = 1; i < n; ++i) {
				Node* tmp = new Node(val, nullptr);
				current->next = tmp;
				current = current->next;
			}
		}

		~tlist() {
			while (first) {
				Node* second = first->next;
				delete first;
				first = second;
			}
		}
		size_t sz() {
			int size = 0;
			Node* current = first;
			while (current) {
				size++;
				current = current->next;
			}
			return size;
		};

		tlist(const tlist& other) {
			if (!other.first) throw "no values in list";
			this->first = new Node(other.first->data, nullptr);
			Node* current = first;
			Node* current_copy = other.first;
			while (current_copy->next) {
				current->next = new Node(current_copy->next->data, nullptr);
				current = current->next;
				current_copy = current_copy->next;
			}

		}; 
		Node* get_first() {
			return first;
		}

		T& operator [](int index) {
			if (index < 0 || index >= this->sz()) throw "wrong index";
			Node* current = first;
			for (int i = 0; i < index; ++i) {
				current = current->next;
			}
			return current->data;

		}


		tlist& operator =(const tlist other) {
			if (&other == this) return (*this);
			while (first) {
				Node* tmp = first->next;
				delete first;
				first = tmp;
			}
			if (!other.first) {
				first = nullptr;
				return *this;

			}
			first = new Node;
			first->data = other.first->data;
			Node* current = first;
			Node* cur_copy = other.first->next;
			while (cur_copy) {
				current->next = new Node;
				current = current->next;
				current->data = cur_copy->data;
				cur_copy = cur_copy->next;
			}
			current->next = nullptr;


			return *this;

		};



		void print() {
			Node* current = first;
			while (current) {
				std::cout << current->data << " ";
				current = current->next;
			}
		};

		 Node* insert_front(T val) {
			Node* first_first = new Node();
			first_first->next = first;
			first_first->data = val;
			first = first_first;
			return first;

		};
		
		Node* insert(T val, Node *prev) {
			if (!prev) throw "wrong prev";
			Node* tmp = new Node;
			tmp->next = prev->next;
			tmp->data = val;
			prev->next = *tmp;


		};

		Node* erase_front() {
			Node* tmp = first;
			first = tmp->next;
			delete tmp;
			return first;
		};
		Node* erase(Node* prev) {
			Node* tmp = prev->next;
			prev->next = tmp->next;
			delete tmp;
			return prev->next;

		}

		Node* find(T val) {
			Node* current = first;
			while (current) {
				if (current->data == val) return current;
				current = current->next;
			}
			return nullptr;

		};




};
