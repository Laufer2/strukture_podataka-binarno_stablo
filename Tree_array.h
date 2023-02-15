#define ARRAY_SIZE 10000
#include <iostream>
using namespace std;

typedef int labeltype;
typedef int node;

struct elem{
    labeltype label;
    node firstchild,nextsibling;
};

struct tr{
       struct elem elements[ARRAY_SIZE];
       node first;
};

typedef struct tr tree;

bool nodeTest(node n, tree * T){
     if (T->elements[n].nextsibling == -2) {
        cout << "Taj cvor ne postoji!\n\n";
        system("pause");
        return false;
     }
     return true;
}

node ParentT(node n, tree * T){
     if (n==T->first) return -1;
     else {
          for(int i=0;i<ARRAY_SIZE;i++){
                if (T->elements[i].firstchild==n) return i;
                else if (T->elements[i].nextsibling==n) ParentT(i, T);
          }
     }
}

node FirstChildT(node n, tree * T){
     return T->elements[n].firstchild;
}

node NextSiblingT(node n, tree * T){
     return T->elements[n].nextsibling;
}

node LabelT(node n, tree * T){
     return T->elements[n].label;
}

node RootT(tree * T){
     return T->first;
}

void CreateT(labeltype x, node n, tree * T){
 if (!nodeTest(n, T)) return;
 for (int i=0; i<ARRAY_SIZE; i++){
     if (T->elements[i].nextsibling == -2) {
        T->elements[i].label = x;
        T->elements[i].firstchild = -1;
        T->elements[i].nextsibling = -1;
        if (T->elements[n].firstchild == -1) T->elements[n].firstchild = i;
        else {
             node current = T->elements[n].firstchild;
             node lastChild;
             while (T->elements[current].nextsibling != -1) current = T->elements[current].nextsibling;
             T->elements[current].nextsibling = i;
        }
        break;
     }
 }
}

void ChangeLabelT(labeltype x, node n, tree * T){
     if (!nodeTest(n, T)) return;
     T->elements[n].label = x;
}

bool RouteToRoot(node p, node n, tree * T){
     if (ParentT(n, T) == T->first) return true;
     if (ParentT(n, T) == p) return false;
     RouteToRoot(p, ParentT(n, T), T);
}

void DeleteT(node n, tree * T){
     if (!nodeTest(n, T)) return;
     for (int i=1; i<ARRAY_SIZE; i++){
         if (T->elements[i].nextsibling == -2) continue;
         if (!RouteToRoot(n, i, T)) {
            cout << i << endl;
            T->elements[i].nextsibling = -2;
            }
     }
     T->elements[n].nextsibling = -2;
     system("pause");
}

void InitT(labeltype x, tree * T){
     //T = new tree;
     T->first = 0;
     T->elements[RootT(T)].label = x;
     T->elements[RootT(T)].firstchild = -1;
     T->elements[RootT(T)].nextsibling = -1;
     for (int i=1; i<ARRAY_SIZE; i++){
         T->elements[i].nextsibling = -2;
     }
}
