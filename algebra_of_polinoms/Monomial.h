#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Monomial {
private:
    int getCoefficient(string str) {
        if (str.empty()) {
            return 0;
        }
        int position = str.find("x");
        int result = 1;
        if (position != string::npos) {
            str.erase(position);
            if (position > 1) {
                result = stoi(str);
            }
            else {
                if (str >= "0" && str <= "9") {
                    result = stoi(str);
                }
                else {
                    str += "1";
                    result = stoi(str);
                }
            }
        }
        else {
            result = stoi(str);
        }
        return result;
    }

    int getCoefficientConvolution(string str, int maxDegree, int count) {
        int* degree = new int[count]();
        for (int i = 0; i < count; i++) {
            degree[i] = 0;
        }

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == 'x') {
                i++;
                int number = 0;
                while (isdigit(str[i])) {
                    number = number * 10 + str[i] - '0';
                    i++;
                }
                int degreeValue = 0;
                if (str[i] == '^') {
                    i++;
                    while (isdigit(str[i])) {
                        degreeValue = degreeValue * 10 + str[i] - '0';
                        i++;
                    }
                }
                else {
                    degreeValue = 1;
                }
                if (degreeValue >= maxDegree) {
                    return -2;
                }
                if (number <= count) {
                    degree[number - 1] = degreeValue;
                }
                i--;
            }
        }

        int result = 0;
        int tmpCount = count - 1;
        for (int i = 0; i < count; i++) {
            result += degree[i] * pow(maxDegree, tmpCount--);
        }
        delete[] degree;
        return result;
    }

    int coefficient;
    int convolution;
    Monomial* next;

public:
    Monomial(int coefficient = 0, int convolution = -1) {
        this->coefficient = coefficient;
        this->convolution = convolution;
        next = this;
    }

    Monomial(string str, int maxDegree, int count) {
        coefficient = getCoefficient(str);
        convolution = getCoefficientConvolution(str, maxDegree, count);
        next = this;
    }

    ~Monomial() {
        next = nullptr;
    }

    Monomial(const Monomial& tmp) {
        coefficient = tmp.coefficient;
        convolution = tmp.convolution;
        next = this;
    }

    Monomial& operator =(Monomial tmp) {
        coefficient = tmp.coefficient;
        convolution = tmp.convolution;
        next = this;
        return*this;
    }

    Monomial multiply(Monomial tmp, int maxDegree, int count) const {
        int* degree = new int[count]();
        int rescoefficient = coefficient * tmp.coefficient;
        int tmpCount = count - 1;
        int result = 0;
        int conv = convolution;
        int tmpconv = tmp.convolution;
        while (conv > 0 || tmpconv > 0) {
            int degreeValue = conv % maxDegree + tmpconv % maxDegree;

            if (degreeValue >= maxDegree) {
                result = -2;
                break;
            }

            degree[tmpCount--] = degreeValue;
            conv /= maxDegree;
            tmpconv /= maxDegree;
        }

        tmpCount = count - 1;
        for (int i = 0; i < count; i++) {
            if (result != -2) {
                result += degree[i] * pow(maxDegree, tmpCount--);
            }
        }

        delete[] degree;
        Monomial res(rescoefficient, result);
        return res;
    }

    string getStringMonomial(int maxDegree, int count) {
        if (convolution == -2) {
            return "";
        }
        string result = "";
        int tmp = convolution;
        while (tmp > 0) {
            int degreeValue = tmp % maxDegree;
            if (degreeValue > 1) {
                result = "x" + to_string(count) + "^" + to_string(degreeValue) + result;
            }
            else if (degreeValue == 1) {
                result = "x" + to_string(count) + result;
            }
            count--;
            tmp /= maxDegree;
        }
        if (coefficient != 1) {
            if (coefficient == -1) {
                result = "-" + result;
            }
            else {
                result = to_string(coefficient) + result;
            }
        }
        return result;
    }

    int getCoefficient() {
        return coefficient;
    }

    int getConvolution() {
        return convolution;
    }

    Monomial* getNext() {
        return next;
    }

    void setCoefficient(int coefficient) {
        this->coefficient = coefficient;
    }

    void setConvolution(int convolution) {
        this->convolution = convolution;
    }

    void setNext(Monomial* next) {
        this->next = next;
    }
};