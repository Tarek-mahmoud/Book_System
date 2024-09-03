#include <bits/stdc++.h>
using namespace std;



struct Library
{
//  add user
    int u_idx = 0;
    int u_id[100];
    string u_name[100];

// add book
    int b_idx = 0;
    int b_id[100];
    int b_quantity[100];
    string b_name[100];

// borrow book
    int bor_idx = 0;
    int bor_times[100] = {0};
    string bor_u_name[100];
    string bor_b_name[100];

    int x;
    int id, q;
    string u, b, s;
    Library()
    {
        do{
            cout << "1) add book"
            << endl << "2) search books"
            << endl << "3) print who borrowed book by name"
            << endl << "4) print who borrowed book by id"
            << endl << "5) print library by name"
            << endl << "6) add user"
            << endl << "7) user borrow book"
            << endl << "8) user return book"
            << "9) print users"
            << endl << "10) Exit"
            << endl;
            cin >> x;

            if (x == 10)
                return;
            else if (x == 9)
                print_users();
            else if (x == 8)
            {
                cin >> u >> b;
                return_book(u, b);
            }
            else if (x == 7)
            {
                cin >> u >> b;
                borrow_book(u, b);
            }
            else if (x == 6)
            {
                cin >> id, u;
                add_user(id, u);
            }
            else if (x == 5)
                print_book_by_name();
            else if (x == 4)
                print_book_by_id();
            else if (x == 3)
            {
                print_who_borrowed_book(b);
            }
            else if (x == 2)
            {
                cin >> s;
                search_book(s);
            }
            else
            {
                cin >> id >> b >> q;
                add_book(id, b, q);
            }
        }while (x!= 10);

    }
    void add_user(int id, string u)
    {
        u_name[u_idx] = u;
        u_id[u_idx] = id;
        u_idx++;
    }

    void add_book(int id, string b, int q)
    {
        b_name[b_idx] = b;
        b_id[b_idx] = id;
        b_quantity[b_idx] = q;
        b_idx++;
    }

    void search_book(string s)
    {
        for (int i=0; i<b_idx; i++)
        {
            if (b_name[i].find(s) == 0)
                cout << b_name[i] << endl;
        }
    }

    void print_book_by_id()
    {
        for (int i = 0; i < b_idx; i++)
        {
            for (int j = 0; j < b_idx-1; j++)
            {
                if (b_id[j] > b_id[j+1])
                {
                    swap(b_id[j], b_id[j+1]);
                    swap(b_name[j], b_name[j+1]);
                    swap(b_quantity[j], b_quantity[j+1]);
                }

            }
        }

        bool flag;
        for (int i = 0; i < b_idx; i++)
        {
            flag = true;
            cout << "id = " << b_id[i]
            << " name = " << b_name[i]
            << " total quantity = " << b_quantity[i]
            << " borrowed ";

            for (int j = 0; j < bor_idx; j++)
            {
                if (bor_b_name[j] == b_name[i])
                {
                    cout << bor_times[j] << endl;
                    flag = false;
                }
            }
            if (flag == true)
            {
                cout << "0" << endl;
            }
        }
    }

    void print_book_by_name()
    {
        for (int i = 0; i < b_idx; i++)
        {
            for (int j = 0; j < b_idx-1; j++)
            {
                if (b_name[j] > b_name[j+1])
                {
                    swap(b_name[j], b_name[j+1]);
                    swap(b_id[j], b_id[j+1]);
                    swap(b_quantity[j], b_quantity[j+1]);
                }

            }
        }


        bool flag;
        for (int i = 0; i < b_idx; i++)
        {
            flag = true;
            cout << "id = " << b_id[i]
            << " name = " << b_name[i]
            << " total quantity = " << b_quantity[i]
            << " borrowed ";

            for (int j = 0; j < bor_idx; j++)
            {
                if (bor_b_name[j] == b_name[i])
                {
                    cout << bor_times[j] << endl;
                    flag = false;
                }
            }
            if (flag == true)
            {
                cout << "0" << endl;
            }
        }

    }

    void borrow_book(string u, string b)
    {
        bor_u_name[bor_idx] = u;
        bor_b_name[bor_idx] = b;
        bor_times[bor_idx]++;
        bor_idx++;
    }

    void return_book(string u, string b)
    {
        for (int i = 0; i < bor_idx; i++)
        {
            if (bor_b_name[i] == b)
            {
                bor_b_name[i] = " ";
                bor_u_name[i] = " ";
            }
        }
    }

    void print_who_borrowed_book(string b)
    {
        for (int i = 0; i < bor_idx; i++)
        {
            if (bor_b_name[i] == b)
                cout << bor_u_name[i] << endl;
        }
    }

    void print_users()
    {
        for (int i = 0; i < u_idx; i++)
        {
            cout << "user: " << u_name[i] << " id: " << u_id[i] << endl;
        }
    }
};





int main()
{
    std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    Library li;
    return 0;
}
