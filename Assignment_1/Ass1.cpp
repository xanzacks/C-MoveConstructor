//  Zeyu Zhao
//  Assignment_1
//  Xcode on Mac

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int findmin(int []);
int sum(int[]);
int getpts(int [], int [], int &);
int getpct(int [], int );
string getGr(int);
int max(int []);
void getarr(int [], int [], int &);

int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream fin;
    fin.open("The Student Data Input File.txt");
    ofstream fout;
    fout.open("The Student Report Output File.txt");
    int count=0;
    int maxcount[50];
    int countA=0;
    int countB=0;
    int countC=0;
    int countD=0;
    int countF=0;
    if(!fin.is_open()){
        cout<<"Can not open the file"<<endl;
        exit(1);
    }
    fout<<"Stdnt Id  Ex  ------- Assignments ---------  Tot  Mi  Fin  CL  Pts  Pct  Gr"<<endl;
    fout<<"--------  --  -----------------------------  ---  --  ---  --  ---  ---  --"<<endl;
    int data[15];
    for (int i = 0; i < 50; i++)//This loop is for output file
    {
        
        for (int i = 0; i < 15; i++)
        {
            fin >> data[i];
        }
        for (int i = 0; i < 19; i++){
            if (i == 12){
                fout<<setfill(' ')<<setw(5)<<sum(data)-findmin(data);
            }
            if (i == 16){
                fout<<setfill(' ')<<setw(6)<<getpts(data, maxcount, i);
            }
            if (i == 17){
                if(getpct(data, getpts(data, maxcount, i))>=90){
                    countA++;
                }
                else if(getpct(data, getpts(data, maxcount, i))>=80){
                    countB++;
                }
                else if(getpct(data, getpts(data, maxcount, i))>=70){
                    countC++;
                }
                else if(getpct(data, getpts(data, maxcount, i))>=60){
                    countD++;
                }
                else{
                    countF++;
                }
                fout<<setfill(' ')<<setw(4)<<getpct(data, getpts(data, maxcount, i));
            }
            if (i == 18){
                getarr(data, maxcount, count);
                fout<<setfill(' ')<<setw(5)<<getGr(getpct(data, getpts(data, maxcount, i)))<<endl;
            }
            if (i > 2 && i < 12){
                fout<<setfill(' ')<<setw(3)<<data[i];
            }
            if (i == 2){
                fout<<setfill(' ')<<setw(4)<<data[i];
            }
            if (i == 0){
                fout<<setfill('0')<<setw(8)<<data[i];
            }
            if (i == 1){
                fout<<setfill(' ')<<setw(4)<<data[i];
            }
            else if(i > 12 && i < 16){
                fout<<setfill(' ')<<setw(4)<<data[i-1];
            }
            
        }
        //cout<<findmin(data)<<' '<<sum(data)-findmin(data)<<endl;
        //cout<<getpct(data, getpts(data))<<" "<<getGr(getpts(data))<<endl;
        //for (int i = 0; i < 15; i++)
        //{
            //cout <<  data[i] << ' ';
        //}
    
    }
    ofstream outputFile;
    outputFile.open("summary_report.txt");
    outputFile<<"Number of A's = "<<countA<<endl;
    outputFile<<"Number of B's = "<<countB<<endl;
    outputFile<<"Number of C's = "<<countC<<endl;
    outputFile<<"Number of D's = "<<countD<<endl;
    outputFile<<"Number of F's = "<<countF<<endl;
    outputFile<<endl;
    outputFile<<"Maximum points = "<<max(maxcount)<<endl;
    outputFile.close();
    fin.close();
    fout.close();
    return 0;
}

int findmin(int data[]){
    int a = data[2];
    for(int i = 3; i < 12; i++){
        if(a > data[i]){
            a = data[i];
        }
    }
    return a;
}

int sum(int data[]){
    int a = data[2];
    for(int i = 3; i < 12; i++){
        a=a+data[i];
    }
    return a;
}

int getpts(int data[], int maxcount[], int &i){
    int a = sum(data) - findmin(data) + data[1] + data[12] + data[13] + data[14];
    return a;
}

void getarr(int data[], int maxcount[], int &i){
    int a = sum(data) - findmin(data) + data[1] + data[12] + data[13] + data[14];
    maxcount[i] = a;
    i++;
}

int getpct(int data[], int pts){//This loop function is for get percentage
    double b;
    b= pts/4.0;
    int c = round(b);
    return c;
}

string getGr(int pct){
    if(pct>=98){
        return "A+";
    }
    if(pct>=92){
        return "A";
    }
    if(pct>=90){
        return "A-";
    }
    if(pct>=88){
        return "B+";
    }
    if(pct>=82){
        return "B";
    }
    if(pct>=80){
        return "B-";
    }
    if(pct>=78){
        return "C+";
    }
    if(pct>=72){
        return "C";
    }
    if(pct>=70){
        return "C-";
    }
    if(pct>=68){
        return "D+";
    }
    if(pct>=62){
        return "D";
    }
    if(pct>=60){
        return "D-";
    }
    else{
        return "F";
    }
}

int max(int maxcount[]){
    int a = maxcount[0];
    for(int i = 1; i < 50; i++){
        if(a < maxcount[i]){
            a = maxcount[i];
        }
    }
    return a;
}
