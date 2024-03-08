#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
};
typedef Node * node;
node first,last;
void init(){
	first=NULL;
	last=NULL;
}
node makenode(int x){
	node p = new Node;
	p->next=NULL;
	p->data=x;
	return p;
	
}
void insert_last(node&first,node &last,int x){
	node p= makenode (x);
	if (first==NULL){
		first=p;
		last=p;
	}
	else{
		last->next=p;
		last=p;
	}
}
void insert_first(node &first, node&last,int x){
	node p= makenode(x);
	if (first==NULL){
		first=p;
		last=p;
	}
	else{
		p->next=first;
		first=p;
	}
}
void show (node first,node last){
	node p= first;
	while (p!=NULL){
		cout<<p->data<<' ';
		p=p->next;
	}
	
}
void chengiamdan(node &head,node &last, int x){
	//da giam dan
	node p= makenode(x);
	if (head==NULL){
		head = p;
		last=p;
	}
	else {
		if (x>head->data){
			p->next=head;
			head=p;
		}
		else{
			node q= head;
			while (q->next!=NULL and q->next ->data >x){
				q=q->next;
			}
			if (q->next==NULL){
				last->next=p;
				last=p;
			}
			else{
				p->next= q->next;
				q->next=p;
			}
		}
	}
	
}
void chentangdan(node &head,node &last, int x){
	//da tang dan
	node p= makenode(x);
	if (head==NULL){
		head= p;
		last = p;
	}
	else{
		node q= head;
		if (x<head->data){
			p->next= head;
			head=p;
		}
		
		else{
			while (q->next!=NULL and q->next ->data<x){
			q=q->next;
		}
		if (q->next==NULL){
			last->next= p;
			last=p;
		}
		else{
			p->next=q->next;
			q->next=p;
		}
		}
	}
}
node head=NULL,tail=NULL;
void xoa(node &head, node &last,int x){
	if (head!=NULL){
		if (head->data==x){
			node q= head;
			head= head->next;
			delete q;
		}
		else{
			node p= head;
			while (p->next!=NULL and p->next->data!=x){
				p=p->next;
			}
			if (p->next!=NULL){
				if (p->next==last){
					node q= p->next;
					last=p;
					delete q;
					p->next=NULL;
				}
				else{
					node q= p->next;
					p->next=q->next;
					delete q;
				}
			}
			else{
				cout<<x<<"\t khong ton tai \n";
			}
		}
}
}
void selection_sort(node head, node last){
	if (head ==NULL or head==last) return ;
	for (node p= head;p->next!=NULL;p=p->next){
		node m=p;
		for (node q=p->next;q!=NULL;q=q->next){
			if (q->data <m->data){
				m=q;
			}
		}
		if (m!= p) swap(m->data,p->data);
	}
}
void insertion_sort(node &head,node &last){
	if (head==NULL or head==last) return ;
	else{
		node dau=NULL,cuoi=NULL,p=head;
		while (p!=NULL){
			node q=p;
			p=p->next;
			q->next=NULL;
			chentangdan(dau,cuoi,q->data);
		}
		head=dau;
		last=cuoi;
		
	}
}
int main(){
	freopen("D:/Cplusplus/input.txt", "r", stdin);
	init();
	int n,num;
	cin>>n;
	for (int i=0;i<n;++i){
		cin>>num;
		insert_first(first,last,num);
		insert_last(head,tail,num);
	}

	chengiamdan(first,last,0);
	chengiamdan(first,last,4);
	chengiamdan(first,last,1000000000);
	cout<<"chen giam dan\n";
	show (first,last);
	cout<<'\n';
	insertion_sort(first,last);
	show (first,last);
	
	return 0;
}
