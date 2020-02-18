    // esercizio test alberi
 
 #include <stdio.h>
 #include <stdlib.h>

    // struttura

 struct node
 {
    struct node *left;
    struct node *right;
    int key;
    int data;
 }node;

    // inserisce un nuovo nodo

  struct node * find_by_key(struct node * tree,int key){
      if(tree==NULL){
        return NULL;
      }else
      {
        if(key<tree->key){
          return find_by_key(tree->left,key);
        }else if(key>tree->key){
          return find_by_key(tree->right,key);
        }else
        {
          printf(tree->data);
          return tree;
        }
        
      }
      
  }

 void insert (struct node **tree, struct node* new){
  if (*tree == NULL) {
    *tree = new;
    (*tree)->left = NULL;
    (*tree)->right = NULL;
  }else{
    if (new->key < (*tree)->key) {
      insert(&(*tree)->left, new);
    }else{
      if (new->key > (*tree)->key) {
        insert(&(*tree)->right, new);
      }else{
        printf("\n Chiave duplicata!!\n");
      }
    }
  }
 }

    // stampa l'albero

void in_order_view(struct node *tree){
    if(tree!=NULL){
            in_order_view(tree->left);
            printf("\n Key : %d \n Dato : %d",tree->key,tree->data);
            in_order_view(tree->right);
    }
}


    // carica l'albero

 struct node* newNode(int data,int d) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->key = data; 
    node->left = NULL; 
    node->right = NULL; 
    node->data = d;
    return(node); 
} 
 
    // mainnn

 int main(int argc, char const *argv[])
 {
    struct node *tree;
    struct node *albero_appoggio;
    int ask;
    int ask1;
    int risp =-1;

    // chiede la key iniziale 

    printf("\n Inserire la chiave della root: ");
    scanf("%d",&ask);
    printf("\n Inserire il dato del nodo: ");
    scanf("%d",&ask1);

    tree = newNode(ask,ask1);

    // chiede nodi all'utente e li aggiunge
    
    do{
        printf("\n Inserire la chiave del nodo: ");
        scanf("%d",&ask);
        printf("\n Inserire il dato del nodo: ");
        scanf("%d",&ask1);
        albero_appoggio = newNode(ask,ask1);
        insert(tree,albero_appoggio);

        printf("\n Inserirne ancora(1)");
        scanf("%d",&risp);
        
    } while (risp==1);

    in_order_view(tree);

    //chiedo la key all'utente

    printf("\n Inserire la chiave del nodo: ");
    scanf("%d",&ask);
    
    albero_appoggio = find_by_key(tree,ask);
    printf("\nLa posizione in cui e' l'abero e' : %p  ",albero_appoggio);

    return 0;
 }
 


