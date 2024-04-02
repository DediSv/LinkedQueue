///Queue threw LinkedList
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

struct LinkedQue {  //Structure of data jednosmerneho sezn
    int data = NULL;
    LinkedQue *next = nullptr;
};

struct Switcher { //Struct of Switcher
    LinkedQue* begin;
    LinkedQue* end;
};

vector <int> CreateArray(){ //Creating a random massive
    srand (static_cast <unsigned int>(time(0)));
    vector <int> array(rand() % 100);
    for (int i = 0; i <= array.size(); i++)
        array[i] = rand() % 100;
    return array;
}

string IsEmpty(Switcher point){ //We use this func in next funct, cuz its here
    if (point.begin == point.end && point.begin->data == NULL)
        return "YES\n";
    return "NO\n";
}

Switcher CreateEmptQ(){ //Create an empty queue
    Switcher que;
    LinkedQue *zacatek = new LinkedQue;
    LinkedQue *konec = zacatek; //Beginning of queue
    que.begin = zacatek;
    que.end = konec;
    return que;
}

void Enqueue(Switcher &point, int x){
    if (IsEmpty(point) == "YES\n")
        point.begin->data = x;
    else {
        point.end->next = new LinkedQue;
        point.end = point.end->next;
        point.end->data = x;
    }
}

Switcher CreateLinQue(vector<int>array) { //Creating a Linked Queue
    Switcher que;
    LinkedQue *zacatek = new LinkedQue;
    LinkedQue *konec = zacatek; //Beginning of queue
    que.begin = zacatek;
    for (int i = 0; i < array.size() - 1; i++){ // -1 cuz we always creating a NEW list//ENQUEUE
        konec->data = array[i]; //Konec se stava zacatkem
        konec->next = new LinkedQue;
        konec = konec->next;
    }
    konec->data = array[array.size() - 1]; //konec = last element
    que.end = konec;
    return que;
}

int Dequeue(Switcher &point){ //DEQUEUE
    int tmp = point.begin->data;
    if (point.begin == point.end)
        point.begin->data = NULL;
    else
        point.begin = point.begin->next;
    return tmp;
}

int Front(Switcher point){
    return point.begin->data;
}

void Vypis(Switcher point){
    LinkedQue* head = point.begin;
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}


int main() {
    vector<int>array = CreateArray();
    Switcher head = CreateLinQue(array);
    cout << "Seznam cisel: ";
    Vypis(head);
    cout << "\nF-ce DEQUEUE: ";
    cout << "\nDELETED ELEMENT: " << Dequeue(head) << "\n";
    Vypis(head);
    cout << "\nF-ce FRONT: ";
    cout << "\n" << Front(head);
    cout << "\nIs queue EMPTY?\n";
    cout << IsEmpty(head);
    int x;
    cout << "Ready to push new QUEUE:)";
    Switcher head2 = CreateEmptQ();
    cout << "\nEnter a NUM: \n";
    cin >> x;
    for (int i = 0; i < x; i++)
        Enqueue(head2,rand() % 10 + 1);
    cout << "\nYour queue: ";
    Vypis(head2);
    return 0;
}