#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
void calculatePayroll(int logs[10][7], int bonusList[10], int &totalAbsences, double &averageWeeklyHours) {
    int total=0;
    totalAbsences=0;
    for (int i=0; i<10; i++) {
        int weeklyTotal = 0;
        for (int j=0; j<7; j++) {
            if (logs[i][j]>12)
                logs[i][j]=12;
            if (logs[i][j]==0)
                totalAbsences++;
            weeklyTotal+=logs[i][j]; }
        if (weeklyTotal>40)
            bonusList[i]=weeklyTotal*5;
        else
            bonusList[i]=0;
        total+=weeklyTotal; }
    averageWeeklyHours=(double)total/10.0;
}
int main() {
    int attendance[10][7], bonusList[10];
    int totalAbsences=0;
    double averageWeeklyHours=0.0;
    cout<<"--- TechFlow Solutions: Weekly Payroll Report ---\n"<<endl;
    for (int i=0; i<10; i++) {
        for (int j=0; j<7; j++){
            attendance[i][j]=rand()%13;
            if (attendance[i][j]<0)
                attendance[i][j]=0; } }
    calculatePayroll(attendance, bonusList, totalAbsences, averageWeeklyHours);
    cout<<"Processing Attendance Grid (with 12-hr Overtime Cap)...\n"<<endl;
    for (int i=0; i<10; i++) {
        int total=0;
        for (int j=0; j<7; j++)
            total+=attendance[i][j];
        cout<<"Employee "<<(i+1)<<": Total "<<total<<" hrs"<<" | Bonus: "<<bonusList[i]<<endl; }
    cout<<fixed << setprecision(5)<<"Total Company Absences (0-hr days): "<<totalAbsences<<endl;
    cout<<"Company Wide Average Weekly Hours : "<<averageWeeklyHours<<endl;
    return 0;
}
