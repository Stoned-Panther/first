#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node* link;
};
struct node* insert_beg(struct node* last,int item){
	struct node* tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->val=item;
	if(last==NULL){
		last=tmp;
		last->link=last;
		return last;
	}
	tmp->link=last->link;
	last->link=tmp;
	return last;
}
struct node* insert_end(struct node* last,int item){
	struct node* tmp=(struct node*)malloc(sizeof(struct node));
	tmp->val=item;
	tmp->link=last->link;
	last->link=tmp;
	last=tmp;
	return last;
}
struct node* insert_bef(struct node* last,int data,int item){
	struct node *t=last->link,*tmp=(struct node*)malloc(sizeof(struct node));
	tmp->val=item;
	do{
		t=t->link;
	}while(t->link->val!=data);
	tmp->link=t->link;
	t->link=tmp;
	return last;
}
struct node* rev(struct node* last){
	struct node *t,*p,*n,*k;
	t=last->link;
	p=last;
	k=t;
	while(t!=last){
		n=t->link;
		t->link=p;
		p=t;
		t=n;
	}
	t->link=p;
	last=k;
	return last;
}
struct node* del_aft(struct node* last,int data){
	struct node* t=last->link;
	while(t->val!=data){
		t=t->link;
	}
	t->link=t->link->link;
	return last;
}
struct node* del_beg(struct node* last){
	last->link=last->link->link;
	return last;
}
struct node* del_end(struct node* last){
	struct node* t=last->link;
	do{
		t=t->link;
	}while(t->link!=last);
	t->link=last->link;
	last=t;
	return last;
}
void display(struct node* last){
	struct node* t=last->link;
	do{
		printf("%d ",t->val);
		t=t->link;
	}while(t!=last->link);
	printf("\n");
}
void sume(struct node *last){
	struct node *t=last->link;
	int sum=0;
	do{
		if(t->val%2==0)
			sum+=t->val;
		t=t->link;
	}while(t!=last->link);
	printf("%d\n",sum);
}
	
int main(){
	struct node* last=NULL;
	int i1,i2,i3,i4,i5;
	scanf("%d%d%d%d%d",&i1,&i2,&i3,&i4,&i5);
	last=insert_beg(last,i1);
	last=insert_end(last,i2);
	last=insert_end(last,i3);
	last=insert_end(last,i4);
	last=insert_beg(last,i5);
	display(last);
	sume(last);
	int d1,i6;
	scanf("%d%d",&d1,&i6);
	last=insert_bef(last,d1,i6);
	last=del_end(last);
	display(last);
	int d2;
	scanf("%d",&d2);
	last=del_aft(last,d2);
	display(last);
	last=rev(last);
	display(last);
	return 0;
}
