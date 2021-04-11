#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void show(vector<vector<int>>& F1, vector<vector<int>>& F2, vector<vector<int>>& F3, int n)
{
    int r;
    cout << "\n-----------------------------------------------\n";
    cout << "F1:\n";
    for (int i = 0; i < F1.size(); i++)
    {
        r = 0;
        while (r != n)
        {
            if (F1[i][r] != 0)
            {
                cout << F1[i][r] << '\t';
                r++;
            }
            else
            {
                r = n;
            }
        }
        cout << endl;
    }
    cout << "\n-----------------------------------------------\n";
    cout << "F2:\n";
    for (int i = 0; i < F2.size(); i++)
    {
        r = 0;
        while (r != n)
        {
            if (F2[i][r] != 0)
            {
                cout << F2[i][r] << '\t';
                r++;
            }
            else
            {
                r = n;
            }
        }
        cout << endl;
    }
    cout << "\n-----------------------------------------------\n";
    cout << "F3:\n";
    for (int i = 0; i < F3.size(); i++)
    {
        r = 0;
        while (r != n)
        {
            if (F3[i][r] != 0)
            {
                cout << F3[i][r] << '\t';
                r++;
            }
            else
            {
                r = n;
            }
        }
        cout << endl;
    }
    cout << "\n-----------------------------------------------\n";
}
void sort(int size, vector<int>& arr)
{
    float tmp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
int Kol(vector<int>& arr, int n)
{
    int i = 0, Kol = 0;
    while (i < n)
    {
        if (arr[i] == 0)
        {
            break;
        }
        Kol++;
        i++;
    }
    if (arr[n - 1] != 0)
    {
        Kol = n;
    }
    return Kol;
}
void met1(vector<int>& STR, int n)
{
    int max = 0, Sser = 1, Kolser = 1;
    while (Kolser != 0)
    {
        max = 0;
        Sser = 1;
        Kolser = 1;
        for (int i = 0; i < n - 2; i++)
        {
            if (STR[i] <= STR[i + 1])
            {
                Sser++;
            }
            else
            {
                Kolser++;
                if (max < Sser)
                {
                    max = Sser;
                }
                Sser = 1;
            }
        }
        if (STR[n - 1] < STR[n - 2])
        {
            Kolser++;
        }
        else
        {
            Sser++;
        }
        if (max < Sser)
        {
            max = Sser;
        }
        if (Kolser == 1)
        {
            Kolser = 0;
        }
        //cout << "\n------------------------------------------------------\n" << max << endl << Kolser << endl;
        if (Kolser != 0)
        {
            vector<int> tmp;
            vector < vector <int> > a(Kolser, vector <int>(max));
            int b = 0;
            bool f = 0, f1 = 0;
            for (int i = 0; i < Kolser; i++)
            {
                a[i][0] = STR[b];
                int j = 0;
                if (b != n - 1)
                {
                    if (STR[b] > STR[b + 1])
                    {
                        i++;
                    }
                    else
                    {
                        j = 1;
                    }
                    if (b != n - 1)
                    {
                        b++;
                    }
                    if (b == n - 1)
                    {
                        f1 = 1;
                        j = 0;
                        a[i][j] = STR[b];
                    }
                    for (j; j < max; j++)
                    {
                        if (f == 0 && f1 == 0)
                        {
                            if (STR[b] > STR[b + 1])
                            {
                                f = 1;
                                a[i][j] = STR[b];
                            }
                            else
                            {
                                a[i][j] = STR[b];
                            }
                            if (b != n - 2)
                            {
                                b++;
                            }
                            else
                            {
                                if (STR[b] < STR[b + 1])
                                {
                                    b++;
                                    j++;
                                    a[i][j] = STR[b];
                                    f = 1;
                                }
                                else
                                {
                                    b++;
                                }
                            }
                        }
                    }
                    f = 0;
                }
            }
            STR.clear();
            if (Kolser % 2 != 0)
            {
                int i = 0;
                while (a[Kolser - 1][i] != 0 && i != max - 1)
                {
                    tmp.push_back(a[Kolser - 1][i]);
                    i++;
                }
            }
            cout << "\n\nСерии:\n\n";
            int B = 0;
            for (int i = 0; i < Kolser; i++)
            {
                for (int j = 0; j < max; j++)
                    cout << a[i][j] << '\t';
                cout << endl;
            }
            int P = 0;
            int P1 = Kolser;
            if (Kolser % 2 != 0)
            {
                P1 = Kolser - 1;
            }
            for (int i = 0; i < P1; i++)
            {
                for (int o = 0; o < 2; o++)
                {
                    for (int j = 0; j < max; j++)
                    {
                        if (a[i][j] != 0)
                        {
                            STR.push_back(a[i][j]);
                        }
                        else
                        {
                            j = max;
                        }
                    }
                    i++;
                }
                int tmp;
                for (int i = P; i < STR.size() - 1; i++)
                {
                    for (int j = P; j < STR.size() - 1; j++)
                    {

                        if (STR[j] > STR[j + 1])
                        {
                            tmp = STR[j + 1];
                            STR[j + 1] = STR[j];
                            STR[j] = tmp;
                        }
                    }
                }
                P = STR.size();
                i--;
            }
            cout << "\n------------------------------------------------------\n" << endl;
            if (Kolser % 2 != 0)
            {
                for (int i = 0; i < tmp.size(); i++)
                {
                    STR.push_back(tmp[i]);
                }
                cout << "\n------------------------------------------------------\n" << endl;
                for (int i = 0; i < n; i++)
                {
                    cout << STR[i] << "\t";
                }
            }
        }
    }
    cout << "Отсартированный массив:" << endl;
    cout << "\n------------------------------------------------------\n" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << STR[i] << "\t";
    }
    cout << "\n------------------------------------------------------\n" << endl;
}
void met2(vector<int>& STR, int left, int right)
{
    if (left == right) return;
    int mid = (left + right) / 2;
    met2(STR, left, mid);
    met2(STR, mid + 1, right);
    int i = left;
    int j = mid + 1;
    int* a = new int[STR.size()];
    for (int step = 0; step < right - left + 1; step++)
    {
        if ((j > right) || ((i <= mid) && (STR[i] < STR[j])))
        {
            a[step] = STR[i];
            i++;
        }
        else
        {
            a[step] = STR[j];
            j++;
        }
    }
    for (int step = 0; step < right - left + 1; step++)
        STR[left + step] = a[step];
}
void met3(vector<int>& STR, int n)
{
    int max = 0, Sser = 1, Kolser = 1;
    int iter = 0;
    int x = 0, y = 1, z = 1;
    vector<int>it;
    do
    {
        if ((z >= 0) && (z <= n))
        {
            it.push_back(z);
            iter++;
        }
        z = x + y;
        x = y;
        y = z;
    } while (z <= n);
    vector<int>qt;
    cout << endl;
    cout << endl;
    for (int i = 0; i < it.size(); i++)
    {
        cout << it[i];
    }
    for (int i = qt.size() - 1; i > -1; i--)
    {
        for (int j = 0; j < it.size(); j++)
        {
            if (qt[i] == it[j])
            {
                Sser = qt[i];
                j = it.size();
                i = -1;
            }
        }
    }
    Kolser = n / Sser;
    cout << endl << Kolser << " по " << Sser;
    int FibNumb1 = 0, FibNumb2 = 0, FibNumb3 = 0;
    it.clear();
    iter = 0;
    x = 0;
    y = 1;
    z = 1;
    do
    {
        if ((z >= 0) && (z <= Kolser))
        {
            it.push_back(z);
            iter++;
        }
        z = x + y;
        x = y;
        y = z;
    } while (z <= Kolser);
    for (int i = it.size() - 1; i > -1; i--)
    {
        for (int j = it.size() - 1; j > 0; j--)
        {
            if (Kolser == it[j] + it[i])
            {
                FibNumb1 = it[j];
                FibNumb2 = it[i];
                j = 0;
                i = -1;
            }
        }
    }
    vector < vector <int> > a(Kolser, vector <int>(Sser));
    int ch = 0;
    for (int i = 0; i < Kolser; i++)
    {
        for (int j = 0; j < Sser; j++)
        {
            a[i][j] = STR[ch];
            ch++;
        }
    }
    qt.clear();
    it.clear();
    cout << "\nСерии: \n";
    for (int i = 0; i < Kolser; i++)
    {
        cout << "(  ";
        for (int j = 0; j < Sser; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << ")\n";
    }
    for (int i = 0; i < Kolser; i++)
    {
        sort(Sser, a[i]);
    }
    cout << "\n-----------------------------------------------\n";
    for (int i = 0; i < Kolser; i++)
    {
        cout << "(  ";
        for (int j = 0; j < Sser; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << ")\n";
    }
    vector < vector <int> > F1(Kolser, vector <int>(n));
    vector < vector <int> > F2(Kolser, vector <int>(n));
    vector < vector <int> > F3(Kolser, vector <int>(n));
    for (int i = 0; i < FibNumb1; i++)
    {
        for (int j = 0; j < Sser; j++)
        {
            F1[i][j] = a[0][j];
        }
        auto Iter = a.begin();
        a.erase(Iter);
        if (a.size() == Kolser - FibNumb1)
        {
            i = FibNumb1;
        }
    }
    Kolser -= FibNumb1;
    for (int i = 0; i < FibNumb2; i++)
    {
        for (int j = 0; j < Sser; j++)
        {
            F2[i][j] = a[0][j];
        }
        auto Iter = a.begin();
        a.erase(Iter + 0);
        if (a.size() == Kolser - FibNumb2)
        {
            i = FibNumb2;
        }
    }
    show(F1, F2, F3, n);
    int Sser1 = Sser;
    while (!(FibNumb1 == 0 && FibNumb2 == 0) && !(FibNumb1 == 0 && FibNumb3 == 0) && !(FibNumb2 == 0 && FibNumb3 == 0))
    {
        int V = 0;
        if (F3[0][0] == 0 && F1[0][0] != 0 && F2[0][0] != 0)
        {
            if (FibNumb2 >= FibNumb1)
            {
                for (int i = 0; i < FibNumb1; i++)
                {
                    int u = 0;
                    for (int j = 0; j < Sser1; j++)
                    {
                        F3[i][j] = F1[i][u];
                        u++;
                    }
                    u = 0;
                    int NN = Kol(F1[i], n) + Kol(F3[i], n);
                    for (int j = 0; j < NN; j++)
                    {
                        if (F3[i][j] == 0)
                        {
                            F3[i][j] = F2[i][u];
                            u++;
                        }
                    }
                    if (F3[0][n - 1] != 0)
                    {
                        sort(Kol(F3[i], n), F3[i]);
                    }
                    else
                    {
                        sort(Kol(F3[i], n) - 1, F3[i]);
                    }
                    V++;
                }
                for (int i = 0; i < V; i++)
                {
                    auto Iter = F1.begin();
                    F1.erase(Iter);
                    auto Iter2 = F2.begin();
                    F2.erase(Iter2);
                }
                Sser1 += Sser;
                FibNumb1 -= V;
                FibNumb2 -= V;
                FibNumb3 += V;
            }
            else
            {
                for (int i = 0; i < FibNumb2; i++)
                {
                    int u = 0;
                    for (int j = 0; j < Sser1; j++)
                    {
                        F3[i][j] = F2[i][u];
                        u++;
                    }
                    u = 0;
                    int NN = Kol(F1[i], n) + Kol(F3[i], n);
                    for (int j = 0; j < NN; j++)
                    {
                        if (F3[i][j] == 0)
                        {
                            F3[i][j] = F1[i][u];
                            u++;
                        }
                    }
                    if (F3[0][n - 1] != 0)
                    {
                        sort(Kol(F3[i], n), F3[i]);
                    }
                    else
                    {
                        sort(Kol(F3[i], n) - 1, F3[i]);
                    }
                    V++;
                }
                Sser1 += Sser;
                for (int i = 0; i < V; i++)
                {
                    auto Iter = F1.begin();
                    F1.erase(Iter);
                    auto Iter2 = F2.begin();
                    F2.erase(Iter2);
                }
                FibNumb1 -= V;
                FibNumb2 -= V;
                FibNumb3 += V;
            }
            cout << "\n===========================================================\n";
            show(F1, F2, F3, n);
        }
        V = 0;
        if (F1[0][0] == 0 && F2[0][0] != 0 && F3[0][0] != 0)
        {
            if (FibNumb2 >= FibNumb3)
            {
                for (int i = 0; i < FibNumb3; i++)
                {
                    int u = 0;
                    for (int j = 0; j < Sser1; j++)
                    {
                        F1[i][j] = F3[i][u];
                        u++;
                    }
                    u = 0;
                    int NN = Kol(F1[i], n) + Kol(F3[i], n);
                    for (int j = Sser1; j < NN; j++)
                    {
                        if (F1[i][j] == 0)
                        {
                            F1[i][j] = F2[i][u];
                            u++;
                        }
                    }
                    if (F1[0][n - 1] != 0)
                    {
                        sort(Kol(F1[i], n), F1[i]);
                    }
                    else
                    {
                        sort(Kol(F1[i], n) - 1, F1[i]);
                    }
                    V++;
                }
                Sser1 += Sser;
                for (int i = 0; i < V; i++)
                {
                    auto Iter = F2.begin();
                    F2.erase(Iter);
                    auto Iter2 = F3.begin();
                    F3.erase(Iter2);
                }
                FibNumb3 -= V;
                FibNumb2 -= V;
                FibNumb1 += V;
            }
            else
            {
                for (int i = 0; i < FibNumb2; i++)
                {
                    int u = 0;
                    for (int j = 0; j < Sser1; j++)
                    {
                        F1[i][j] = F2[i][u];
                        u++;
                    }
                    u = 0;
                    int NN = Kol(F1[i], n) + Kol(F3[i], n);
                    for (int j = 0; j < NN; j++)
                    {
                        if (F1[i][j] == 0)
                        {
                            F1[i][j] = F3[i][u];
                            u++;
                        }
                    }
                    if (F1[0][n - 1] != 0)
                    {
                        sort(Kol(F1[i], n), F1[i]);
                    }
                    else
                    {
                        sort(Kol(F1[i], n) - 1, F1[i]);
                    }
                    V++;
                }
                Sser1 += Sser;
                for (int i = 0; i < V; i++)
                {
                    auto Iter = F2.begin();
                    F2.erase(Iter);
                    auto Iter2 = F3.begin();
                    F3.erase(Iter2);
                }
                FibNumb3 -= V;
                FibNumb2 -= V;
                FibNumb1 += V;
            }
            cout << "\n===========================================================\n";
            show(F1, F2, F3, n);
        }
        V = 0;
        if (F1[0][0] != 0 && F2[0][0] == 0 && F3[0][0] != 0)
        {
            if (FibNumb1 >= FibNumb3)
            {
                for (int i = 0; i < FibNumb3; i++)
                {
                    int u = 0;
                    for (int j = 0; j < Sser1; j++)
                    {
                        F2[i][j] = F3[i][u];
                        u++;
                    }
                    u = 0;
                    int N = Sser + Sser1;
                    int NN = Kol(F1[0], n) + Kol(F3[0], n);
                    for (int j = 0; j < NN; j++)
                    {
                        if (F2[i][j] == 0)
                        {
                            F2[i][j] = F1[i][u];
                            u++;
                            N--;
                        }
                        else
                        {
                            N++;
                        }
                    }
                    if (F2[0][n - 1] != 0)
                    {
                        sort(Kol(F2[i], n), F2[i]);
                    }
                    else
                    {
                        sort(Kol(F2[i], n) - 1, F2[i]);
                    }
                    V++;
                }
                Sser1 += Sser;
                for (int i = 0; i < V; i++)
                {
                    auto Iter = F1.begin();
                    F1.erase(Iter);
                    auto Iter2 = F3.begin();
                    F3.erase(Iter2);
                }
                FibNumb3 -= V;
                FibNumb2 += V;
                FibNumb1 -= V;
            }
            else
            {
                for (int i = 0; i < FibNumb1; i++)
                {
                    int u = 0;
                    for (int j = 0; j < Sser1; j++)
                    {
                        F2[i][j] = F1[i][u];
                        u++;
                    }
                    u = 0;
                    int NN = Kol(F1[i], n) + Kol(F3[i], n);
                    for (int j = 0; j < NN; j++)
                    {
                        if (F2[i][j] == 0)
                        {
                            F2[i][j] = F3[i][u];
                            u++;
                        }
                    }
                    if (F2[0][n - 1] != 0)
                    {
                        sort(Kol(F2[i], n), F2[i]);
                    }
                    else
                    {
                        sort(Kol(F2[i], n) - 1, F2[i]);
                    }
                    V++;
                }
                Sser1 += Sser;
                for (int i = 0; i < V; i++)
                {
                    auto Iter = F1.begin();
                    F1.erase(Iter);
                    auto Iter2 = F3.begin();
                    F3.erase(Iter2);
                }
                FibNumb3 -= V;
                FibNumb2 += V;
                FibNumb1 -= V;
            }
            cout << "\n===========================================================\n";
            show(F1, F2, F3, n);
        }
    }
}
int main()
{
    system("chcp 1251>nul");
    srand(time(NULL));
    vector<int> STR;
    int n = -1;
    int OP = -1;
    cout << "Введите количество элементов: ";
    while (n < 1)
    {
        cin >> n;
        if (n < 1)
        {
            cout << "Введено некоректное значение. Введите значение заново";
        }
    }
    cout << "Введите элементы:\n\n";
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cout << "Введите " << i + 1 << " эелемент:";
        cin >> tmp;
        STR.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cout << STR[i] << "\t";
    }
    cout << "\nВведите номер метода\n1)Естественное слияние\n2)Сбалансированное слияние\n3)Многофазное слияние\n";
    while (OP < 0)
    {
        cin >> OP;
        if (OP < 0)
        {
            cout << "Ошибка!\n";
        }
    }
    switch (OP)
    {
    case 1:
        met1(STR, n);
        break;
    case 2:
        met2(STR, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            cout << STR[i] << '\t';
        }
        cout << endl;
        break;
    case 3:
        met3(STR, n);
        break;
    default:
        break;
    }
    return 0;
}