#include <bits/stdc++.h>
#define MAX 100000
#define TRUE 1
#define FALSE 0
#define ERROR -1

using namespace std;

int IsEmpty(void);
int IsFull(void);
int push(int);
int pop(void);
int getCapacity(void);
int element(void);
char getName(void);
void setName(char name);

class Stack {
    int A[MAX];
    int SP = -1;
    string name;

    public:
        int IsEmpty(void) {
            if(SP == -1) return(TRUE);
            else return(FALSE);
        }

        int IsFull(void) {
            if(SP == MAX-1) return(TRUE);
            else return(FALSE);
        }

        int push(int a) {
            if(IsFull() == FALSE) {
                SP = SP + 1;
                A[SP] = a;
                return(a);
            } else return(ERROR);
        }

        int pop(){
            int buffer;
            buffer = 0;

            if(IsEmpty() == FALSE) {
                buffer = A[SP];
                A[SP] = 0;
                SP = SP - 1;
                return(buffer);
            } else return(ERROR);
        }

        int element() {
            if(IsEmpty() == FALSE) {
                return(A[SP]);
            } else {
                return(ERROR);
            }
        }

        int getCapacity() {
            return(SP+1);
        }

        void setName(string newName) {
            name = newName;
        }

        string getName() {
            return(name);
        }
};

int transfer(Stack& s1, Stack& s2) {
    if(s1.IsEmpty()) {
        int disk = s2.pop();
        s1.push(disk);
        cout << "Transfer disk " << disk << " from " << s2.getName().c_str() << " to " << s1.getName() << endl;
    } else if(s2.IsEmpty()) {
        int disk = s1.pop();
        s2.push(disk);
        cout << "Transfer disk " << disk << " from " << s1.getName().c_str() << " to " << s2.getName() << endl;
    } else {
        int disk1 = s1.element();
        int disk2 = s2.element();
        if(disk1 < disk2) {
            s1.pop();
            s2.push(disk1);
            cout << "Transfer disk " << disk1 << " from " << s1.getName().c_str() << " to " << s2.getName() << endl;
        } else {
            s2.pop();
            s1.push(disk2);
            cout << "Transfer disk " << disk2 << " from " << s2.getName().c_str() << " to " << s1.getName() << endl;
        }
    }
}

int main() {
    Stack src;
    Stack helper;
    Stack dest;

    src.setName("Source");
    helper.setName("Helper");
    dest.setName("Destination");

    int n = 0;

    cout << "Enter the no. of disks : ";
    cin >> n;
    cout << "Below steps need to be followed : \n";

    for(int i = n; i >= 1; i--) {
        src.push(i);
    }

    int steps = pow(2, n) - 1;

    for(int i = 1; i <= steps; i++) {
        if(n % 2 == 0) {
            if(i % 3 == 1) {
                transfer(src, helper);
            } else if(i % 3 == 2) {
                transfer(src, dest);
            } else {
                transfer(helper, dest);
            }
        } else {
            if(i % 3 == 1) {
                transfer(src, dest);
            } else if(i % 3 == 2) {
                transfer(src, helper);
            } else {
                transfer(dest, helper);
            }
        }
    }

    return 0;
}
