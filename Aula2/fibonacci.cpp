#include <iostream>
using namespace std;

int fibonacci(int n){
    
    if (n <= 1){
        return n;}

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
    int n;
    
    cout << "Quantos termos da sequência de Fibonacci deseja: ";
    cin >> n;

    cout << "Sequência de Fibonacci:\n";
    for(int i = 0; i < n; i++){
        cout << fibonacci(i) << " ";
    }
    cout << endl;
    return 0;
}