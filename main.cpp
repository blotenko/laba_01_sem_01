#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;


/*
 Список. Реалізації на основі зв’язних списків, масивів, бібліотечних засобів. Алгоритми сортування: insertion sort, quicksort, merge sort.
 
 +* за інші алгоритми сортування;
 
 
 +* за реалізацію швидких алгоритмів, не заснованих на порівнянні (non-comparison sorts, наприклад counting, radix, bucket sort);

 */






template <class T>
 class NodeMass{
 private:
    T* data;
     T* pnext;
     T head;
     int last;
 public:
     T* getData()const{return data;}
     NodeMass(int size){
         data = new T[size];
         pnext = new T[size];
         last = -1;
     }
     bool isFull(int size){
         return ( size==last+1);
    }
    bool isempty(){
        return(last == -1);
    }
     bool push(T val){
         if(isFull(5)) return false;
         if(isempty()){
             data[++last]=val;
             head = data[last];
             pnext[last] = last;
         }
         else{
        pnext[last] = last+1;
         data[++last]=val;
         }
         return true;
     }
     void print(){
         for(int i =0; i<5;i++){
             cout<<data[i]<<" ";
         }
         cout<<endl;
     }
 };




template <typename T>
void exch(T &A, T &B)
{
    T t = A; A = B; B = t;
}
template <typename T>
void compexch(T &A, T &B)
{
    if (B < A) exch(A, B);
}
template <typename T>
void insertion_sort( T* a, int L, int R)
{
    for(int i = R; i > L; i--)
        compexch(a[i - 1], a[i]);
  
    for (int i = L + 2; i <= R; i++)
    {
        int j = i;
        T cur = a[j];
        while (a[j - 1] > cur)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = cur;
    }
}



template <typename T>
int Partition(T* a, int start, int end){
    int pivot = end;
    int j = start;
    for(int i=start;i<end;++i){
        if(a[i]<a[pivot]){
            swap(a[i],a[j]);
            ++j;
        }
    }
    swap(a[j],a[pivot]);
    return j;
}
template <typename T>
void Quicksort(T* a, int start, int end ){
    if(start<end){
        int p = Partition(a,start,end);
        Quicksort(a,start,p-1);
        Quicksort(a,p+1,end);
    }
}



template <typename T>
void Merge(T* a, int start, int end){
    int z, x, y, mid;
    T temp[(end - start + 1)];
    mid = (start + end) / 2;
    z = 0;
    x = start;
    y = mid + 1;
    while (x <= mid && y <= end){
        if (a[x] < a[y]){
            temp[z] = a[x];
            ++x, ++z;
        }
        else{
            temp[z] = a[y];
            ++y, ++z;
        }
    }
    while (x <= mid){
        temp[z] = a[x];
        ++x, ++z;
    }
    while (y <= end){
        temp[z] = a[y];
        ++y, ++z;
    }
    for (int i = start; i <= end; ++i){
        a[i] = temp[i - start];
    }
}
template <typename T>
void MergeSort(T* a, int start, int end){
    if (start < end){
        int mid = (start + end) / 2;
        MergeSort(a, start, mid);
        MergeSort(a, mid + 1, end);
        Merge(a, start, end);
    }

}











//int main(){
//    int size =5;
//    NodeMass<string> mass{size};
//    mass.push("5");
//    mass.push("7");
//    mass.push("4");
//    mass.push("3");
//    mass.push("1");
////    mass.push(5);
////    mass.push(7);
////    mass.push(4);
////    mass.push(3);
////    mass.push(1.5);
//    mass.print();
//   // insertion_sort(mass.getData(),0,size-1);
//    //Quicksort(mass.getData(),0,size-1);
//    MergeSort(mass.getData(), 0, size-1);
//    mass.print();
//    return 0;
//}




template <class T>
class Node {
public:
    T val;
     Node* next;
    Node(T x)
    {
        val = x;
        next = NULL;
    }
};
template <class T>
class LinkedlistIS {
public:
    Node<T>* head;
    Node<T>* sorted;
    Node<T>* end;
 
    void push(T val)
    {
        Node<T>* newnode = new Node<T>(val);
        newnode->next = head;
        head = newnode;
    }
 
    void insertionSort(Node<T>* headref)
    {
        sorted = NULL;
        Node<T>* current = headref;
        while (current != NULL) {
            Node<T>* next = current->next;
            sortedInsert(current);
            current = next;
        }
        head = sorted;
    }
 

    void sortedInsert(Node<T>* newnode)
    {
        if (sorted == NULL || sorted->val >= newnode->val) {
            newnode->next = sorted;
            sorted = newnode;
        }
        else {
            Node<T>* current = sorted;
            while (current->next != NULL
                   && current->next->val < newnode->val) {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
    }
    void printlist(Node<T>* head)
    {
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
    }
     Node<T>* getTail(Node<T>* cur)
    {
        while (cur != NULL && cur->next != NULL)
            cur = cur->next;
        return cur;
    }
     Node<T>* partition( Node<T>* head,  Node<T>* end, Node<T>** newHead,
                            Node<T>** newEnd){
        struct Node<T>* pivot = end;
        struct Node<T> *prev = NULL, *cur = head, *tail = pivot;
        while (cur != pivot) {
            if (cur->val < pivot->val) {
                if ((*newHead) == NULL)
                    (*newHead) = cur;
     
                prev = cur;
                cur = cur->next;
            }
            else
            {
                if (prev)
                    prev->next = cur->next;
                struct Node<T>* tmp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }
        if ((*newHead) == NULL)
            (*newHead) = pivot;
        (*newEnd) = tail;
        return pivot;
    }
     
     Node<T>* quickSortRecur(struct Node<T>* head,struct Node<T>* end){
        if (!head || head == end)
            return head;
     
        Node<T> *newHead = NULL, *newEnd = NULL;
        struct Node<T>* pivot= partition(head, end, &newHead, &newEnd);
     
        if (newHead != pivot) {
            struct Node<T>* tmp = newHead;
            while (tmp->next != pivot)
                tmp = tmp->next;
            tmp->next = NULL;
     
            newHead = quickSortRecur(newHead, tmp);

            tmp = getTail(newHead);
            tmp->next = pivot;
        }
     
        pivot->next = quickSortRecur(pivot->next, newEnd);
     
        return newHead;
    }
    void quickSort( Node<T>** headRef){
        (*headRef)= quickSortRecur(*headRef, getTail(*headRef));
        return;
    }
    
    
    void MergeSort(struct Node<T>** headRef)
    {
        struct Node<T>* head = *headRef;
        struct Node<T>* a;
        struct Node<T>* b;
        if ((head == NULL) || (head->next == NULL)) {
            return;
        }
        FrontBackSplit(head, &a, &b);
        MergeSort(&a);
        MergeSort(&b);
        *headRef = SortedMerge(a, b);
    }

    struct Node<T>* SortedMerge(struct Node<T>* a, struct Node<T>* b)
    {
        struct Node<T>* result = NULL;
             if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);
             if (a->val <= b->val) {
            result = a;
            result->next = SortedMerge(a->next, b);
        }
        else {
            result = b;
            result->next = SortedMerge(a, b->next);
        }
        return (result);
    }
    
    
    void FrontBackSplit(struct Node<T>* source,
                        struct Node<T>** frontRef, struct Node<T>** backRef)
    {
        struct Node<T>* fast;
        struct Node<T>* slow;
        slow = source;
        fast = source->next;
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
    
    
};



//int main()
//{
//    LinkedlistIS<string> list;
//    list.head = NULL;
//    list.push("1");
//    list.push("3");
//    list.push("4");
//    list.push("7");
//    list.push("5");
//    cout << "Linked List before sorting" << endl;
//    list.printlist(list.head);
//    cout << endl;
//   //list.insertionSort(list.head);
//   //list.quickSort(&list.head);
//    list.MergeSort(&list.head);
//    cout << "Linked List After sorting" << endl;
//    list.printlist(list.head);
//}







template <class T>
class List{
public:
    list<T> list;
    List* next ;
    List* prev;
};





template <typename T>
void showlist(List<T> g)
{
    
    list <int> :: iterator it;
    for( auto it = g.list.begin(); it != g.list.end(); ++it)
        cout << *it<<" ";
    cout << '\n';
}

template <typename T>
List<T> listToMass(List<T> list,int size){
    T* mass = new T[size];
    List<T> newList;
    int j =0;
    for(auto i : list.list){
       mass[j]=i;
        j++;
    }
    insertion_sort(mass,0,size-1);
    //Quicksort(mass,0,size-1);
    //MergeSort(mass, 0, size-1);

    for(int i = 0;i<size;i++){
        newList.list.push_back(mass[i]);
    }
    
      return newList;
}


int main()
{


    //List<double> ml;
  // List<int> ml;
    List<double> ml;


//    ml.list.push_back("1");
//    ml.list.push_back("3");
//    ml.list.push_back("4");
//    ml.list.push_back("7");
//    ml.list.push_back("5");

    ml.list.push_back(1.4);
    ml.list.push_back(3.8);
    ml.list.push_back(4.6);
    ml.list.push_back(7.4);
    ml.list.push_back(5.2);
    showlist(ml);
    ml=listToMass(ml, 5);
    showlist(ml);
    return 0;

}
