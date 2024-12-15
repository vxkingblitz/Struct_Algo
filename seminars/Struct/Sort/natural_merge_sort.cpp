#include <iostream>
#include <fstream>
#include <string>


using namespace std;

bool End_Range(ifstream& file) {
    char c;
    file >> ws; 
    file.get(c);
    if (c == '\'') {
        file.get(); 
        return true;
    }
    file.unget();
    return false;
}

void Print_End(const string& filename) {
    ifstream file(filename);
    ofstream end("FILE.txt");
    int value;
    while (file >> value) {
        end << value << " ";
        if (file.peek() == '\'') {
            file.get();
        }
    }
}




void Natural_Merging_Sort(const string& filename) {
    int s1, s2, a1, a2, mark;
    ifstream f;
    ofstream f1, f2;
    s1 = s2 = 1;

    while (s1 > 0 && s2 > 0) {
        mark = 1;
        s1 = s2 = 0;

        f.open(filename);
        f1.open("nmsort_1.txt");
        f2.open("nmsort_2.txt");

        if (!(f >> a1)) {
            cerr << "Файл пуст или поврежден!" << endl;
            return;
        }
        f1 << a1 << " ";

        while (f >> a2) {
            if (a2 < a1) {
                switch (mark) {
                case 1:
                    f1 << "' ";
                    mark = 2;
                    s1++;
                    break;
                case 2:
                    f2 << "' ";
                    mark = 1;
                    s2++;
                    break;
                }
            }
            if (mark == 1) {
                f1 << a2 << " ";
                s1++;
            }
            else {
                f2 << a2 << " ";
                s2++;
            }
            a1 = a2;
        }

        if (s2 > 0 && mark == 2) f2 << "'";
        if (s1 > 0 && mark == 1) f1 << "'";

        f.close();
        f1.close();
        f2.close();

        

        ofstream f;
        ifstream f1, f2;

        f.open(filename, ios::out);
        f1.open("nmsort_1.txt");
        f2.open("nmsort_2.txt");

        if (f1 >> a1 && f2 >> a2) {
            bool file1 = false, file2 = false;

            while (f1 && f2) {
                file1 = file2 = false;

                while (!file1 && !file2) {
                    if (a1 <= a2) {
                        f << a1 << " ";
                        file1 = End_Range(f1);
                        f1 >> a1;
                    }
                    else {
                        f << a2 << " ";
                        file2 = End_Range(f2);
                        f2 >> a2;
                    }
                }

                while (!file1) {
                    f << a1 << " ";
                    file1 = End_Range(f1);
                    f1 >> a1;
                }

                while (!file2) {
                    f << a2 << " ";
                    file2 = End_Range(f2);
                    f2 >> a2;
                }
            }

            while (!file1 && f1) {
                f << a1 << " ";
                file1 = End_Range(f1);
                f1 >> a1;
            }

            while (!file2 && f2) {
                f << a2 << " ";
                file2 = End_Range(f2);
                f2 >> a2;
            }
        }

        f.close();
        f1.close();
        f2.close();
    }

    Print_End("nmsort_1.txt");
    remove("nmsort_1.txt");
    remove("nmsort_2.txt");


    
}









