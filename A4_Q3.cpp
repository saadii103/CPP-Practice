#include<iostream>
using namespace std;
bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i=2; i*i<=n; i++) {
        if (n%i==0)
            return false; }
    return true; }
int nextPrime(int n) {
    int num=n+1;
    while (!isPrime(num))
        num++;
    return num; }
void processReadings(int arr[], int size) {
    for (int i=0; i<size; i++)
        if (arr[i]%2==0)
            arr[i]=nextPrime(arr[i]); }
int main() {
    const int size=10;
    int tempReading[size];
    int arrayCopy[size];
    for (int i=0; i<size; i++) {
        cout<<"Enter reading "<<i+1<<": ";
        cin>>tempReading[i];
        arrayCopy[i]=tempReading[i]; }
    processReadings(arrayCopy, size);
    cout<<"\nOriginal readings:\n";
    for (int i=0; i<size; i++) {
        cout<<tempReading[i]<<" "; }
    cout<<"\nUpdated readings:\n";
    for (int i=0; i<size;i++)
        cout<<arrayCopy[i]<<" ";
    return 0;
}
