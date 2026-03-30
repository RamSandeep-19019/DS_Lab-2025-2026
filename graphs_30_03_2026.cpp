#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
struct node
{
    string name;
    vector<int> v;
};
int search1(string name, string names[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (name == names[i])
        {
            return i;
        }
    }
}
void breadth_first_search(int *arr, int n, int idx, int *net)
{
    bool array[n] = {false};

    queue<int *> q;
    q.push((net + idx * n));
    array[idx] = true;
    int *u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (*(u + i) == 1)
            {
                if (array[i] != true)
                {
                    q.push(arr + i * n);
                    *(net + idx * n + i) = 1;
                    array[i] = true;
                }
            }
        }
    }
}
int main()
{
    int n;
    cout << "=== Friend Network in a Class ===\nNumber of students: ";
    cin >> n;
    list<node> l;
    string names[n];
    node s;
    int m;
    int arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i][i] = 1;
    }
    cout << "Enter student names:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> names[i];
    }

    int x, y;
    string input1, input2;
    cout << "enter the no of friendships: ";
    cin >> m;
    cout << "Enter friendships (namel name2):\n";
    for (int i = 0; i < m; i++)
    {

        cin >> input1 >> input2;
        x = search1(input1, names, n);
        y = search1(input2, names, n);
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    int network[n][n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            network[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        breadth_first_search(arr[0], n, i, network[0]);
    }
    cout << "Direct Friendships: \n";
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        cout << left << setw(10) << names[i] << "-> ";
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (arr[i][j] == 1){
                    cout << names[j] << " ";
                r = 1;
            }
            }
        }
        if (r == 0)
        {
            cout << "No friends";
        }
        r = 0;
        cout << endl;
    }
    cout << "Friendship Network Matrix:\n\n";
    cout << left << setw(10) << "";
    for (int i = 0; i < n; i++)
    {
        cout << left << setw(10) << names[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << left << setw(10) << names[i];
        for (int j = 0; j < n; j++)
        {
            cout << left << setw(10) << network[i][j];
        }
        cout << endl;
    }
    cout << endl
         << "Friend Groups:\n";
    int count = 0;
    int arr2[n] = {0};
    for (int i = 0; i < n; i++)
    {
        if (arr2[i] == 0)
        {
            ++count;
            cout << "Friend Group " << count << ": ";
            for (int j = 0; j < n; j++)
            {
                if (network[i][j] == 1)
                {
                    cout << names[j] << " ";
                    arr2[j] = 1;
                }
            }
            cout << endl;
        }
    }
}
