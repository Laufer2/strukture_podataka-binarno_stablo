#include <iostream>
#include "Tree_array.h"
#include "Tree_order.h"
#include "BinTree_array.h"
//#include "BinTree_pointer.h"

using namespace std;

void dodavanje(tree * T){
     node parent;
     labeltype x;
     system("cls");
     cout << "Unesite roditelja kojem zelite dodati dijete: ";
     cin >> parent;
     cout << "Unesite vrijednost: ";
     cin >> x;
     CreateT(x, parent, T);
}

void promjena(tree * T){
     node n;
     labeltype x;
     system("cls");
     cout << "Unesite cvor kojem zelite promijeniti vrijednost: ";
     cin >> n;
     cout << "Unesite vrijednost: ";
     cin >> x;
     ChangeLabelT(x, n, T);
}

void brisanje(tree * T){
     node n;
     system("cls");
     cout << "Unesite cvor kojem zelite obrisati: ";
     cin >> n;
     DeleteT(n, T);
}

void preorder (tree * T){
     system("cls");
     cout << "Red.br.\tLabel\tFirst child\tNext sibling" << endl;
     Preorder(0, T);
     system("pause");
}

void inorder (tree * T){
     system("cls");
     cout << "Red.br.\tLabel\tFirst child\tNext sibling" << endl;
     Inorder(0, T);
     system("pause");
}

void postorder (tree * T){
     system("cls");
     cout << "Red.br.\tLabel\tFirst child\tNext sibling" << endl;
     Postorder(0, T);
     system("pause");
}

void ispis(tree * T){
     system("cls");
     cout << "Red.br.\tLabel\tFirst child\tNext sibling" << endl;
     for (int i=0; i<ARRAY_SIZE; i++){
         if (NextSiblingT(i, T) != -2){
               cout << i << "\t" << LabelT(i, T)
                         << "\t" << FirstChildT(i, T)
                         << "\t\t" << NextSiblingT(i, T) << endl;
         }
     }
     system("pause");
}

void dodavanjeB(bnode n, labeltype value, btree BT){
         if (value<LabelB(n, BT)) {
            if (!testExistB(LeftChildB(n, BT), BT)) {
               CreateLeftB(value, n, BT);
               ChangeLabelB(value*2, LeftChildB(n, BT), BT);
               return;
            } else dodavanjeB(LeftChildB(n, BT), value, BT);
         }
         if (value>=LabelB(n, BT))  {
            if (!testExistB(RightChildB(n, BT), BT)) {
               CreateRightB(value, n, BT);
               ChangeLabelB(value*2, RightChildB(n, BT), BT);
               return;
            } else dodavanjeB(RightChildB(n, BT), value, BT);
         }
}

void ispisB(bnode n, btree BT){
     cout << n << "\t" << LabelB(n, BT)
                 << "\t" << LeftChildB(n, BT)
                 << "\t\t" << RightChildB(n, BT) << endl;
     if (testExistB(RightChildB(n, BT), BT)) ispisB(RightChildB(n, BT), BT);
     if (testExistB(LeftChildB(n, BT), BT))ispisB(LeftChildB(n, BT), BT);
}

int main(){
    int izbor, polje[10];
    tree * T = new tree;
    InitT(0, T);
    btree BT;
    BT = InitB(rand()%101, BT);
   
    do{
        do{
              system("cls");
              cout << "IZBORNIK:\n";
              cout << "---------- Stablo - polje ----------\n";
              cout << "1. Dodaj cvor u stablo\n";
              cout << "2. Promijeni vrijednost\n";
              cout << "3. Brisanje cvora\n";
              cout << "4. Ispis - Preorder\n";
              cout << "5. Ispis - Inorder\n";
              cout << "6. Ispis - Postorder\n";
              cout << "7. Ispis\n";
              cout << "---------- Binarno stablo----------\n";
              cout << "8. Dodaj unose u stablo\n";
              cout << "9. Ispis\n";
              cout << "---------------------------------\n";
              cout << "0. Kraj\n\n";
              cout << "Izbor: ";
              cin >> izbor;
        }while(izbor<0 || izbor>12);
       
        switch(izbor){
                 case 1: dodavanje(T);
                         break;
                 case 2: promjena(T);
                         break;
                 case 3: brisanje(T);
                         break;
                 case 4: preorder (T);
                         break;
                 case 5: inorder(T);
                         break;
                 case 6: postorder(T);
                         break;
                 case 7: ispis(T);
                         break;
                 case 8:
                        for (int i=0; i<10; i++){
							polje[i]=rand()%20;
                            dodavanjeB(RootB(BT), polje[i], BT);
                        }
                         break;
                 case 9: system("cls");
                          cout << "Node\tLabel\tLeft child\tRight child" << endl;
                          ispisB(RootB(BT), BT);
                          system("pause");
                          break;   
                             
        }
    }while(izbor!=0);
   
   
    return 0;
}
