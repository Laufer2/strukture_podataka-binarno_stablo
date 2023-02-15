#define ARRAY_SIZE 10000

typedef int labeltype;

struct element{
       labeltype label;
       int used;
};

struct bt{
       struct element elements[ARRAY_SIZE];
};


typedef struct bt * btree;
typedef int bnode;

bool testExistB(bnode n, btree T){
     if (n==-1) return false;
     if (T->elements[n].used) return true;
     return false;
}

bnode ParentB(bnode n, btree T){
     if (n%2==0) return n/2;
     return (n-1)/2;
}

bnode LeftChildB(bnode n, btree T){
     if (T->elements[n*2].used) return n*2;
     return T->elements[0].label;
}

bnode RightChildB(bnode n, btree T){
     if (T->elements[n*2+1].used) return n*2+1;
     return T->elements[0].label;
}

labeltype LabelB(bnode n, btree T){
          return T->elements[n].label;
}

void ChangeLabelB(labeltype x, bnode n, btree T){
     T->elements[n].label = x;
}

bnode RootB(btree T){
          if (T->elements[1].used) return 1;
          return T->elements[0].label;
}

void CreateLeftB(labeltype x, bnode n, btree T){
     if (!T->elements[n*2].used) {
        T->elements[n*2].used = 1;
        T->elements[n*2].label = x;
        }
     else cout << "Nije moguce stvoriti cvor, cvor je vec zauzet\n";
}

void CreateRightB(labeltype x, bnode n, btree T){
     if (!T->elements[n*2+1].used) {
        T->elements[n*2+1].used = 1;
        T->elements[n*2+1].label = x;
        }
     else cout << "Nije moguce stvoriti cvor, cvor je vec zauzet\n";
}

void DeleteB(bnode n, btree T){
     if (T->elements[LeftChildB(n, T)].used) DeleteB(LeftChildB(n, T), T);
     if (T->elements[RightChildB(n, T)].used) DeleteB(RightChildB(n, T), T);
     T->elements[n].used = 0;
     
}

btree InitB(labeltype x, btree T){
     T = new bt;
     T->elements[1].label = x;
     T->elements[1].used = 1;
     T->elements[0].label = -1;
     T->elements[0].used = 1;
     for (int i=2; i<ARRAY_SIZE; i++) T->elements[i].used = 0;
     return T;
}
