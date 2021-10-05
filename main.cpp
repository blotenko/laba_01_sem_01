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
 
    void push(T val){
        Node<T>* newnode = new Node<T>(val);
        newnode->next = head;
        head = newnode;
    }
    void printlist(Node<T>* head){
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
    }
     Node<T>* getTail(Node<T>* cur){
        while (cur != NULL && cur->next != NULL)
            cur = cur->next;
        return cur;
    }
    
    void insertionSort(Node<T>* headref){
        sorted = NULL;
        Node<T>* current = headref;
        while (current != NULL) {
            Node<T>* next = current->next;
            sortedInsert(current);
            current = next;
        }
        head = sorted;
    }
    void sortedInsert(Node<T>* newnode){
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
    
    
    void MergeSort(struct Node<T>** headRef){
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
    struct Node<T>* SortedMerge(struct Node<T>* a, struct Node<T>* b){
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
                        struct Node<T>** frontRef, struct Node<T>** backRef){
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
    struct Node<T>* swap(struct Node<T>* ptr1, struct Node<T>* ptr2)
    {
        struct Node<T>* tmp = ptr2->next;
        ptr2->next = ptr1;
        ptr1->next = tmp;
        return ptr2;
    }
      
    void bubbleSort(struct Node<T>** head, int count){
        struct Node<T>** h;
        int i, j, swapped;
        for (i = 0; i <= count; i++){
            h = head;
            swapped = 0;
            for (j = 0; j < count - i - 1; j++){
      
                struct Node<T>* p1 = *h;
                struct Node<T>* p2 = p1->next;
                if (p1->val > p2->val){
                *h = swap(p1, p2);
                    swapped = 1;
                }
                h = &(*h)->next;
            }
            if (swapped == 0)
                break;
        }
    }
    void swap2(LinkedlistIS<T>* l, Node<T>* A) {
        
        T temp = A->val;
            A->val = A->next->val;
            A->next->val = temp;


    }
    
    void shakerSort(LinkedlistIS<T>* list) {
        Node<T>* bubble_tail = 0;
        int n = 0;
        do {
            Node<T>* current = list->head;
            Node<T>* last_swp = list->head;
            do
            {
                n++;
                if (current ->val > current->next->val)
                {
                    last_swp = current->next;
                    if (current->next == bubble_tail)
                    {
                        bubble_tail = current;
                    }
                    swap2(list, current);
                }
                else {
                    current = current->next;
                }
            } while (current != bubble_tail && current ->next);
            if (last_swp != bubble_tail)
            {
                bubble_tail = last_swp;
            }
        } while (bubble_tail->prev);
    }
    
    
};



template <typename T>
void BubbleSort(T *massiv, int size)
{
  T temp;
  for (int i = 1; i < size; i++)
  {
    for (int j = 0; j < size-1; j++)
    {
      if (massiv[j] > massiv[j+1])
      {
        temp = massiv[j];
        massiv[j] = massiv[j+1];
        massiv[j+1] = temp;
      }
    }
  }
}


template <class T>
void swapEl(T *arr, int i)
{
    T buff;
    buff = arr[i];
    arr[i] = arr[i - 1];
    arr[i - 1] = buff;
}

template <class T>
void ShakerSort(T *arr, int size)
{
    int leftMark = 1;
    int rightMark = size - 1;
    while (leftMark <= rightMark)
    {
        for (int i = rightMark; i >= leftMark; i--)
        if (arr[i - 1] > arr[i]) swapEl(arr, i);
        leftMark++;


        for (int i = leftMark; i <= rightMark; i++)
        if (arr[i - 1] > arr[i]) swapEl(arr, i);
        rightMark--;
    }
}



template<typename T,size_t len>
static void countingSort(array<T,len>& items,const int exp,int size) {

    //Range for counting array
    const unsigned int RANGE = 255;
    std::vector<T> count(255,0);

    //Counting each elements numbers of time they appered
    for(unsigned int i = 0; i <size ; ++i) {
        count[fmod(( items[i]/exp ), 10)]++;
        //cout<<((unsigned)items[i]/exp ) % 10<<"++"<<endl;
    }


    //Modifiying each count such that each element at each index stors the sum of previous counts
    for(auto it = std::next(count.begin()) ; it != count.end() ; it = std::next(it)) {
        *it += *(std::prev(it));
    }

    //Ouput variable where the sorted element will be stored
    std::array<T,len> output;
    for(int i = size-1 ; i  >=-1 ; i--) {
        output[--count[ fmod(( items[i]/exp ), 10)]] = items[i];
    }


    //copying variable to the original array
    std::move(output.begin(),output.end(),items.begin());
}

template<class T>
void radixSort(T& items,int size) {
    auto max = *(std::max_element(items.begin(),items.end()));
    for(int i = 1 ; max/i > 0 ; i *= 10){
        countingSort(items,i,size);
    }
}
template<class T>
void printElement(const T& items,const std::string& heading) {
    std::cout << heading <<std::endl;
    //Printing Element to standart output
    std::copy(items.begin(),items.end(),
        std::ostream_iterator<typename T::value_type>(std::cout," "));
    std::cout << std::endl;
}

template<typename  T>
static void BucketSort(T* data, int count) {
    T minValue = data[0];
    T maxValue = data[0];

    for (int i = 1; i < count; i++)
    {
        if (data[i] > maxValue)
            maxValue = data[i];
        if (data[i] < minValue)
            minValue = data[i];
    }

    T bucketLength = maxValue - minValue + 1;
    vector<T>* bucket = new vector<T>[bucketLength];

    for (int i = 0; i < bucketLength; i++)
    {
        bucket[i] = vector<T>();
    }

    for (int i = 0; i < count; i++)
    {
        bucket[(int)data[i] - (int)minValue].push_back(data[i]);
    }

    int k = 0;
    for (int i = 0; i < bucketLength; i++)
    {
        int bucketSize = bucket[i].size();

        if (bucketSize > 0)
        {
            for (int j = 0; j < bucketSize; j++)
            {
                data[k] = bucket[i][j];
                k++;
            }
        }
    }
}




template <class T>
class List{
public:
    list<T> list;
};

template <typename T>
void showlist(List<T> g){
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
    
    //insertion_sort(mass,0,size-1);
    //Quicksort(mass,0,size-1);
    //MergeSort(mass, 0, size-1);
   // BubbleSort(mass, size);
    ShakerSort(mass, size);
    for(int i = 0;i<size;i++){
        newList.list.push_back(mass[i]);
    }
      return newList;
}


void listByLib(){
        List<string> ml;
        ml.list.push_back("1.2");
        ml.list.push_back("3.3");
        ml.list.push_back("4.4");
        ml.list.push_back("7.7");
        ml.list.push_back("5.5");
        showlist(ml);
        ml=listToMass(ml, 5);
        showlist(ml);
}
void listByLinkedList(){
            LinkedlistIS<string> list;
            list.head = NULL;
            list.push("1.1");
            list.push("3.3");
            list.push("4.4");
            list.push("7.7");
            list.push("5.5");
            list.printlist(list.head);
            cout << endl;
           //list.insertionSort(list.head);
           //list.quickSort(&list.head);
            //list.MergeSort(&list.head);
           //list.bubbleSort(&list.head, 5);
            list.shakerSort(&list);
            list.printlist(list.head);
}
void listByMass(){
    int size =5;
    NodeMass<double> mass{size};
    mass.push(5.2);
    mass.push(7.2);
    mass.push(4.1);
    mass.push(3.1);
    mass.push(1.3);
      mass.print();
   // insertion_sort(mass.getData(),0,size-1);
    //Quicksort(mass.getData(),0,size-1);
   // MergeSort(mass.getData(), 0, size-1);
   // BubbleSort(mass.getData(), size);
    //ShakerSort(mass.getData(), size);
    
    
//    std::array<double,5> elem ;
//    for(int i = 0; i<size;i++){
//        double num2 =mass.getData()[i];
//        elem.at(i) = num2;
//    }
//    radixSort(elem,6);
//    printElement(elem,"Sorted Array:");
    BucketSort(mass.getData(),5);
    
    
    
   mass.print();
}

int main(){
    int choice;
    cout<<"You will work with lists implemented through: "<<endl;
    cout<<"1. Massive"<<endl;
    cout<<"2. Linked list"<<endl;
    cout<<"3. Library facilities"<<endl;
    cin>>choice;
    if(choice!=1 && choice!=2 && choice!=3 ){
        cout<<"Error"<<endl;
    }
    else{
        switch (choice) {
            case 1: listByMass();break;
            case 2: listByLinkedList(); break;
            case 3: listByLib();break;
        }
    }

    return 0;
}
/*
 Фігури на площині: прямі та кола. Обчислення точок перетину двох фігур. Операції симетричного відображення відносно заданої прямої та інверсії відносно заданого кола (для точок та цих фігур).
 
 
 +* обчислення кутів між фігурами, перевірка збереження кутів під час перетворень

 */
