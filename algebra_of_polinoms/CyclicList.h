#include "Monomial.h"

class CyclicList {
private:
	Monomial* head;
public:
	CyclicList() {
		head = new Monomial();
	}

	CyclicList(const CyclicList& other) {
		head = new Monomial(*other.head);
		Monomial* current = head;
		Monomial* other_current = other.head->getNext();
		while (other_current != other.head) {
			current->setNext(new Monomial(*other_current));
			current = current->getNext();
			other_current = other_current->getNext();
		}
		current->setNext(head);
	}

	~CyclicList() {
		Monomial* current = head->getNext();
		while (current != head) {
			Monomial* temp = current;
			current = current->getNext();
			delete temp;
		}
		delete head;
	}

	CyclicList& operator=(const CyclicList& other) {
		if (head->getNext() != head) {
			Monomial* current = head->getNext();
			while (current != head) {
				Monomial* temp = current;
				current = current->getNext();
				delete temp;
			}
		}
		head = new Monomial(*other.head);
		Monomial* current = head;
		Monomial* other_current = other.head->getNext();
		while (other_current != other.head) {
			Monomial* A = new Monomial(other_current->getCoefficient(), other_current->getConvolution());
			current->setNext(A);
			current = current->getNext();
			other_current = other_current->getNext();
		}
		current->setNext(head);
		return *this;
	}

	void add(Monomial monomial) {
		Monomial* new_monomial = new Monomial(monomial);
		int convolution = monomial.getConvolution();
		int coefficient = monomial.getCoefficient();
		Monomial* current = head;
		while (current->getNext() != head && current->getNext()->getConvolution() > convolution) {
			current = current->getNext();
		}

		if (convolution == current->getNext()->getConvolution()) {
			int k = current->getNext()->getCoefficient();
			if (k + coefficient != 0) {
				current->getNext()->setCoefficient(k + coefficient);
			}
			else {
				Monomial* A = current->getNext();
				current->setNext(current->getNext()->getNext());
				A->setNext(nullptr);
				delete A;
			}
		}
		else {
			new_monomial->setNext(current->getNext());
			current->setNext(new_monomial);
		}
	}

	void add(int coefficient, int convolution) {
		Monomial* monomial = new Monomial(coefficient, convolution);
		Monomial* current = head;
		while (current->getNext() != head && current->getNext()->getConvolution() > convolution) {
			current = current->getNext();
		}

		if (convolution == current->getNext()->getConvolution()) {
			int k = current->getNext()->getCoefficient();
			if (k + coefficient != 0) {
				current->getNext()->setCoefficient(k + coefficient);
			}
			else {
				Monomial* A = current->getNext();
				current->setNext(current->getNext()->getNext());
				A->setNext(nullptr);
				delete A;
			}
		}
		else {
			monomial->setNext(current->getNext());
			current->setNext(monomial);
		}
		/*Monomial* prev = head;
		Monomial* cur = head->getNext();
		while (cur != head && tmp->getSV() < cur->getConvolution()) {
			prev = cur;
			cur = cur->getNext();
		}
		if (tmp->getSV() == cur->getSV()) {
			int P = cur->getA() + tmp->getA();
			if (P == 0) {
				prev->setNext(cur->getNext());
				cur->setNext(nullptr);
				delete cur;
			}
			else {
				cur->setCoefficient(P);
			}
		}
		else {
			tmp->setNext(cur);
			prev->setNext(tmp);
		}*/
	}

	void erase(int coefficient, int convolution) {
		Monomial* A = head;
		while (A->getNext() != head) {
			if (A->getNext()->getCoefficient() == coefficient && A->getNext()->getConvolution() == convolution) {
				Monomial* B = A->getNext();
				A->setNext(B->getNext());
				delete B;
				break;
			}
			A = A->getNext();
		}
	}

	CyclicList operator +(const CyclicList& list) {
		Monomial* current = list.head->getNext();
		while (current != list.head) {
			this->add(*current);
			current = current->getNext();
		}
		return *this;
	}

	CyclicList operator -(const CyclicList& list) {
		CyclicList result;
		Monomial* current = this->head->getNext();
		while (current != this->head) {
			result.add(*current);
			current = current->getNext();
		}
		current = list.head->getNext();
		while (current != list.head) {
			result.add(current->getCoefficient() * (-1), current->getConvolution());
			current = current->getNext();
		}
		return result;
	}


	CyclicList operator *(int k) {
		if (k == 0) {
			CyclicList result;
			return result;
		}

		CyclicList result(*this);
		Monomial* current = result.head->getNext();
		while (current != result.head) {
			current->setCoefficient(current->getCoefficient() * k);
			current = current->getNext();
		}
		return result;
	}

	CyclicList multiply(CyclicList tmp, int maxDegree, int count) {
		CyclicList res;
		Monomial* curThis;
		Monomial* cur = tmp.head->getNext();
		while (cur != tmp.head) {
			curThis = head->getNext();
			while (curThis != head) {
				Monomial* P = new Monomial();
				(*P) = cur->multiply((*curThis), maxDegree, count);
				if (P->getConvolution() != -1) {
					res.add(P->getCoefficient(), P->getConvolution());
				}
				curThis = curThis->getNext();
			}
			cur = cur->getNext();
		}
		return res;
	}

	void printList(int maxDegree, int count) {
		Monomial* current = head->getNext();
		if (current != head) {
			cout << current->getStringMonomial(maxDegree, count);
			current = current->getNext();
		}
		while (current != head) {
			if (current->getCoefficient() > 0) {
				cout << "+" << current->getStringMonomial(maxDegree, count);
			}
			else {
				cout << current->getStringMonomial(maxDegree, count);
			}
			current = current->getNext();
		}
		cout << endl;
	}

	Monomial* getHead() {
		return head;
	}

	string getStringList(int maxDegree, int count) {
		string result = "";
		Monomial* current = head->getNext();
		if (current != head) {
			result = result + current->getStringMonomial(maxDegree, count);
			current = current->getNext();
		}
		while (current != head) {
			if (current->getCoefficient() > 0) {
				result = result + "+" + current->getStringMonomial(maxDegree, count);
			}
			else {
				result = result + current->getStringMonomial(maxDegree, count);
			}
			current = current->getNext();
		}
		return result;
	}
};
