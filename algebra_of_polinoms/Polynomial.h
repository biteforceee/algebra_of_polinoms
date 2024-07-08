#include "CyclicList.h"

class Polynomial {

private:
    void splitString(string str, int& k, string* w) {
        string zn = "+-";
        k = 0;
        str += " ";
        for (int i = 0; i < str.length(); i++) {
            int l = zn.find(str[i]);
            if (l >= 0 && l < zn.length()) {
                if (w[k].length() > 0) {
                    k++;
                }
                w[k] = str[i];
                w[++k] = "";
            }
            else {
                if (str[i] == ' ') {
                    if (w[k].length() > 0) {
                        w[++k] = "";
                    }
                }
                else {
                    w[k] = w[k] + str[i];
                }
            }
        }
    }

    CyclicList memory;
    int maxDegree;
    int count;

public:

    Polynomial(string str, int maxDegree, int count) {
        int flag = 0;
        this->maxDegree = maxDegree + 1;
        this->count = count;
        string* stringMemory = new string[str.length()];
        string* stringMemoryTmp = new string[str.length()];
        int k = 0;
        int newK = 0;
        splitString(str, k, stringMemoryTmp);
        for (int i = 0; i < k; i++) {
            if (stringMemoryTmp[i] != "+") {
                if (stringMemoryTmp[i] == "-") {
                    i++;
                    stringMemory[newK++] = "-" + stringMemoryTmp[i];
                }
                else {
                    stringMemory[newK++] = stringMemoryTmp[i];
                }
            }
        }
        for (int i = 0; i < newK; i++) {
            Monomial tmp(stringMemory[i], this->maxDegree, this->count);
            memory.add(tmp);
        }
    }

    Polynomial() {
    }

    Polynomial(const Polynomial& tmp) {
        maxDegree = tmp.maxDegree;
        count = tmp.count;
        memory = *new CyclicList(tmp.memory);
    }

    Polynomial& operator=(Polynomial tmp) {
        maxDegree = tmp.maxDegree;
        count = tmp.count;
        memory = *new CyclicList(tmp.memory);
        return*this;
    }

    void add(string str) {
        string* stringMemory = new string[str.length()];
        int k = 0;
        splitString(str, k, stringMemory);
        for (int i = 0; i < k; i++) {
            Monomial tmp(stringMemory[i], maxDegree, count);
            memory.add(tmp);
        }
    }

    Polynomial operator +(const Polynomial& tmp) {
        Polynomial A(*this);
        if (maxDegree == tmp.maxDegree && count == tmp.count) {
            A.memory = A.memory + tmp.memory;
        }
        return A;
    }

    Polynomial operator -(const Polynomial& tmp) {
        Polynomial A(*this);
        if (maxDegree == tmp.maxDegree && count == tmp.count) {
            A.memory = A.memory - tmp.memory;
        }
        return A;
    }

    Polynomial operator *(int k) {
        Polynomial A(*this);
        A.memory = A.memory * k;
        return A;
    }

    Polynomial operator *(const Polynomial& tmp) {
        Polynomial A(*this);
        if (maxDegree == tmp.maxDegree && count == tmp.count) {
            A.memory = A.memory.multiply(tmp.memory, maxDegree, count);
        }
        return A;
    }

    int getMaxDegree() {
        return maxDegree;
    }

    int getCount() {
        return count;
    }

    void printPolynomial() {
        memory.printList(maxDegree, count);
    }

    bool isMaximumDegreeExceeded() {
        Monomial* current = memory.getHead()->getNext();
        while (current != memory.getHead()) {
            if (current->getConvolution() == -2) {
                return true;
            }
        }
        return false;
    }

    string getStringPolynomial() {
        return memory.getStringList(maxDegree, count);
    }
};