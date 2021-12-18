#include<iostream>
using namespace std;


int main(int argc, char *argv[]) {

    char* input = argv[1];

    int count = 0;
    bool isSeparator = true;

    if (argc < 2) {
        cout << 0 << endl;//проверка на непустой ввод
    }

    while(*input) {

        if (*input == ' ' || *input == '\t' || *input == '\n') {
            isSeparator = true; //нашли символ-разделитель
        }

        if (isSeparator) {//если нашел символ-разделитель, то прибовь слово, по умолчанию True чтобы отлавливать 1 слово
            count++;
            isSeparator = false;
        }

        input++;
    }

    cout << count << endl;

    return 0;

}