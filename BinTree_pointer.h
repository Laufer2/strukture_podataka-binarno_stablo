typedef int labeltype;

struct element{
       labeltype label;
       struct element * left,* right;
};

typedef struct element * bnode;
typedef struct element * btree;

bool testExistB(bnode n, btree T){
     if (n) return true;
     return false;
}

bnode LeftChildB(bnode n, btree T){
     return n->left;
}

bnode RightChildB(bnode n, btree T){
     return n->right;
}

bnode ParentB(bnode n, btree T){
     static bnode tekuci = T;
     if (tekuci->left==n || tekuci->right==n) return tekuci;
     if (tekuci->left) ParentB(LeftChildB(tekuci, T), T);
     if (tekuci->right) ParentB(RightChildB(tekuci, T), T);
}

labeltype LabelB(bnode n, btree T){
          return n->label;
}

void ChangeLabelB(labeltype x, bnode n, btree T){
     n->label = x;
}

bnode RootB(btree T){
          return T;
}

void CreateLeftB(labeltype x, bnode n, btree T){
     if (n->left) {
        cout << "Nije moguce stvoriti cvor, cvor je vec zauzet\n";
        return;
     }
     bnode novi = new element;
     novi->label = x;
     novi->left = nullptr;
     novi->right = nullptr;
     n->left = novi;
}

void CreateRightB(labeltype x, bnode n, btree T){
     if (n->right) {
        cout << "Nije moguce stvoriti cvor, cvor je vec zauzet\n";
        return;
     }
     bnode novi = new element;
     novi->label = x;
     novi->left = nullptr;
     novi->right = nullptr;
     n->right = novi;
}

void DeleteB(bnode n, btree T){
     if (n->left) DeleteB(LeftChildB(n, T), T);
     if (n->right) DeleteB(RightChildB(n, T), T);
     delete n;
     
}


btree InitB(labeltype x, btree T){
     T = new element;
     T->label = x;
     T->left = nullptr;
     T->right = nullptr;
     return T;
}
