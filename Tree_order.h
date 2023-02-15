void Preorder(node n, tree * T){
   if(n<0) return;
   if (NextSiblingT(n, T) != -2){
       cout << n << "\t" << LabelT(n, T)
                 << "\t" << FirstChildT(n, T)
                 << "\t\t" << NextSiblingT(n, T) << endl;
   }
   Preorder(FirstChildT(n, T), T);
   Preorder(NextSiblingT(n, T), T);     
}

void Inorder(node n, tree * T){
   if(n<0)return;
   Inorder(FirstChildT(n, T), T);
   if (NextSiblingT(n, T) != -2){
       cout << n << "\t" << LabelT(n, T)
                 << "\t" << FirstChildT(n, T)
                 << "\t\t" << NextSiblingT(n, T) << endl;
   }
   Inorder(NextSiblingT(n, T), T);
}

void Postorder(node n, tree * T){
   if(n<0)return;
   Preorder(FirstChildT(n, T), T);
   Preorder(NextSiblingT(n, T), T);
   if (NextSiblingT(n, T) != -2){
       cout << n << "\t" << LabelT(n, T)
                 << "\t" << FirstChildT(n, T)
                 << "\t\t" << NextSiblingT(n, T) << endl;
   }
}
     
