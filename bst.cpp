#include <bits/stdc++.h>
using namespace std;

 typedef struct node
 {
   int data;
   struct node *left ,*right;
  }bst;

 bst  *create_newnode(int d)
 {
 bst *newnode=new bst;
 newnode->data=d;
 newnode->left=NULL;
 newnode->right=NULL;
 return newnode;
   }


    bst *search_e(bst *root,int key)
   {
     if(root->data==key||root==NULL)
      {
      cout<<"value found\n";
      return root;
      }

     if(root->data>key)
       return search_e(root->right,key);

     else if(root->data<key)  return search_e(root->left,key);

   }

  bst *insert_e(bst *root,int d)
  {
   bst *t=root,*prev=NULL;
   if(root==NULL)
   return create_newnode(d);

    else
    {

      while(1)
      {

         prev=t;

         if(d<t->data)
         t=t->left;
         else
         t=t->right;
         if(t==NULL)
         break;

      }
   if(d<prev->data)
     prev->left=create_newnode(d);
     else
     prev->right=create_newnode(d);

     }


return root;

  }

  void preorder(bst *root)
  {
  if(root!=NULL)
  {preorder(root->left);
  cout<<root->data<<"  ";

  preorder(root->right);
    }

  }


int main()
{
    bst *root=NULL;
int a[7]={50,30,20,40,70,60,80};

 for(int i=0;i<7;i++)
  {
    root=insert_e(root,a[i]);
  }
  preorder(root);

search_e(root,40);
//cout<<temp->data;
//  preorder(root);
return 0;
}