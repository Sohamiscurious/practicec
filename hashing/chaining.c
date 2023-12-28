struct Node {
    int data;
    struct Node *next;
};

void SortedInsert(struct Node **H, int x) {
    struct Node *t, *q = NULL, *p = *H;//p is the pointer to the head node
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (*H == NULL)//if the linked list is empty
        *H = t;//the head node will be the new node
    else {
        while (p && p->data < x) {//traversing the linked list
            q = p;//q is the tail pointer
            p = p->next;//p is the head pointer
        }
        if (p == *H) {//if the new node is to be inserted at the beginning
            t->next = *H;//the new node will point to the head node
            *H = t;//the head node will be the new node
        } else {
            t->next = q->next;//the new node will point to the next node of the tail node
            q->next = t;//the tail node will point to the new node
        }
    }
}
struct Node *Search(struct Node *p, int key) {
    while (p != NULL) {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}
int hash(int key) { 
    return key % 10; 
    }
void Insert(struct Node *H[], int key) {
   int index = hash(key);//hashing the key
   SortedInsert(&H[index],key);//inserting the key in the hash table
}
int main(){
    struct Node *HT[10];//hash table
    struct Node *temp;
    int i;
    for(i=0;i<10;i++)
        HT[i]=NULL; //intialising a array
    Insert(HT,12);
    Insert(HT,22);
    Insert(HT,42);
    temp=Search(HT[hash(21)],21); //searching for 21

    printf("%d ",temp->data);//21 does not exist in the hash table so it will return null
    return 0;
}