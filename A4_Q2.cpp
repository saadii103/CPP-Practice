#include<iostream>
using namespace std;
void sanitizeStudentName(char name[], char filterChar, int maxLimit) {
    int length=0, removed=0, i=0;
    while (name[length] != '\0')
        length++;
    while (i<length) {
        if (name[i]==filterChar) {
            for (int j=i; j<length-1; j++)
                name[j]=name[j+1];
            name[length-1]='\0';
            length--;
            removed++;
        } else
            i++;
        }
    for (int i=0; i<length; i++) {
        if (name[i]>='a' && name[i]<='z')
            name[i]=name[i]-32;
    }
    if (length>maxLimit)
        name[maxLimit]='\0';
    cout<<"Characters Removed : "<<removed<<endl;
}
int main() {
    char name[100];
    char filterChar;
    int maxLimit;
    cout<<"----- NU Name Sanitizer -----\n"<<endl;
    cout<<"Enter student name: ";
    cin.getline(name, 100);
    char original[100];
    int k=0;
    while (name[k]!='\0') {
        original[k]=name[k];
        k++; }
    original[k]='\0';
    cout <<"Filter character: ";
    cin>>filterChar;
    cout<<"Enter max limit: ";
    cin >> maxLimit;
    cout<<"\nProcessing! Please Wait...\n" << endl;
    cout<<"Filtered name : " << original << endl;
    sanitizeStudentName(name, filterChar, maxLimit);
    cout<<"Final ID card name: " << name << endl;
    return 0;
}
