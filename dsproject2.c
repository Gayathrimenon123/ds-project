#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
struct dictionary{
	char word[20];
	char meaning[20];
	struct dictionary *left,*right;
};
typedef struct dictionary dict;
dict *root=NULL;
int check(char a[],char b[]){
	int i,j,c;
     for(i=0,j=0 ; a[i]!='\0'&&b[j]!='\0' ; i++,j++){
       if(a[i]>b[j]){
         c=1;
         break;
       }
        else if(b[j]>a[i]){
          c=-1;
          break;
        }
      else
         c=0;
     }
     if(c==1)
       return 1;
      else if(c==-1)
        return -1;
      else
        return 0;
}
void insert(dict *temp){
	int flag=0;
  dict *ptr,*p;
  ptr=root;

  if(root==NULL)
     root=temp;
  else{
     while(ptr!=NULL ){
       if(check(temp->word,ptr->word)>0){
         p=ptr;
         ptr=ptr->right;
       }

       else if(check(temp->word,ptr->word)<0)
     {
       p=ptr;
       ptr=ptr->left;
     }
       else if(check(temp->word,ptr->word)==0){
          flag=1;
            printf("\n\nWord exists!!!!");
          break;
       }

   }
   
       if(flag==0 && ptr==NULL){

         if(check(p->word,temp->word)==1)
            p->left=temp;
         else if(check(p->word,temp->word)==-1)
            p->right=temp;
       }

     }
}
void search(char w[10]){
	dict *t;
	int flag=0;
	t=root;
	while(t!=NULL){
		if(strcmp(w,t->word)>0)
			t=t->right;
		else if(strcmp(w,t->word)<0)
			t=t->left;
		else if(strcmp(w,t->word)==0){
			flag=1;
			printf("\nWord:%s",t->word);
			printf("\nMeaning:%s\n",t->meaning);
			break;
		}
	}
	if(flag==0)
		printf("\n Word not found!!!!!");
}
void disp(dict *root){
	if(root!=NULL){
		disp(root->left);
		printf("\n Word:%s\n",root->word);
		printf("\n Meaning:%s\n",root->meaning);
		disp(root->right);
	}
}
void main(){
	dict *t;
	int ch;
	char w1[20];
	printf("\n DICTIONARY USING BINARY SEARCH TREE\n--------------------------------------\n");
	do{
	printf("\n1.Insert\n2.Search\n3.Display\n4.Exit\n Enter your choice:");
	scanf("%d",&ch);
	switch(ch){
		case 1:t=(dict*)malloc(sizeof(dict));
				t->left=NULL;
				t->right=NULL;
				printf("\n Enter word:");
				scanf("%s",t->word);
				printf("\n Enter meaning:");
				scanf("%s",t->meaning);
				insert(t);
				break;
		case 2:	printf("\n Enter word to be searched:");
			    scanf("%s",&w1);
			    search(w1);
		    	break;
		case 3:disp(root);
				break;
		case 4:exit(1);
				break;									
	}
}while(1);
}
