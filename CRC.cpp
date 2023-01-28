#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
void calc(int* t, int* g, int s)
{
    for(int i = 0;i < s; i++)
        {
            if(t[i] == g[i])
            t[i] = 0;
    else
        t[i] = 1;
        }
}
int main()
{
    int *msg, *key, msg_size, key_size, i;
    cout << "CYCLIC REDUNDENCY CHECK\N";
    cout << "Enter the user size of the key: " << endl;
    cin >> key_size;
    key = new int[key_size];
    cout << "Enter User key: " << endl;
    for(i = 0;i < key_size; i++)
        cin >> key[i];
    cout << "Enter the user size of the message: " << endl;
    cin >> msg_size;
    msg = new int[msg_size + key_size-1];
    cout << "Enter User message: " << endl;
    for(i = 0;i < msg_size; i++)
        cin >> msg[i];
    for(i = msg_size;i < msg_size + key_size - 1; i++)
        msg[i] = 0;
    int *t = new int[key_size];
    int *zkey = new int[key_size];
    for(i = 0;i < key_size; i++)
        {
            t[i] = msg[i];
            zkey[i] = 0;
        }
        for(i = key_size-1;i < msg_size + key_size - 1; i++)
            {
                t[key_size-1] = msg[i];
                if(t[0] == 0)
                    calc(t, zkey, key_size);
                else
                    calc(t, key, key_size);
                for(int j = 1;j < key_size; j++)
                    {
                        t[j-1] = t[j];
                }
            }
            cout << "The  Cyclic Redundant Check of the Program is: " << endl;
            for(i = 0;i < key_size - 1; i++)
                cout << t[i];
            for(int i = msg_size,j = 0;i < key_size + msg_size - 1,j < key_size - 1; i++, j++)
                {
                    msg[i] = t[j];
            }
            int n = rand()%(key_size + msg_size + 5);
            msg[n] =! msg[n];
            cout << "\n" << n << "\n";
            for(i = 0;i < key_size; i++)
                {
                    t[i] = msg[i];
                    zkey[i] = 0;
                    }
                    for(i = key_size - 1;i < msg_size + key_size - 1; i++)
                        {
                            t[key_size - 1] = msg[i];
                            if(t[0] == 0)
                                calc(t, zkey, key_size);
                            else
                                calc(t, key, key_size);
                            for(int j = 1;j < key_size; j++)
                                {
                                    t[j - 1] = t[j];
                                }
                        }
                        for(int i = 0;i < key_size - 1; i++)
                            {
                                cout << t[i];
                        }
                        int flag = 1;
                        for(int i = 0;i < key_size - 1; i++)
                            {
                                if(t[i] == 1)
                                flag = 0;
                        }
                        if(flag == 0)
                            cout << "\nError\n exit(0)";
                        else
                            cout << "\nNo error...The program is terminated Successfully...!";
                        getch();
                        return 0;
}
