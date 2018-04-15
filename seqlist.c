#include<stdio.h>
#include<stdlib.h>

#include "seqlist.h"
void printseqlist(seqlist *seq){
	size_t i = 0;
	if(seq->size==0){
		printf("kong,over");
		return;
	}
	for(i=0;i<seq->size;i++){
		printf("[%c]",seq->c[i]);
	}
	printf("\n");
}
void seqlistInit(seqlist *seq){
	if(NULL==seq){
		return;
	}
	seq->size=0;
}
void seqlistpushback(seqlist *seq,char value){
	if(seq->size >= 1000){
		return;//manle
	}
	//++(seq->size);
	seq->c[seq->size]=value;
	++(seq->size);
}
void seqlistpopback(seqlist *seq){
	if(NULL==seq){
		return;
	}
	if(seq->size==0){
		return;//neirongkong,wufashan
	}
	seq->size--;
}
void seqlistpushhead(seqlist *seq,char value){
	if(NULL==seq){
		return;
	}
	if(seq->size==1000){
		return;//manle,bunengcha
	}
	else{
		//seq->size++;
		int i=seq->size-1;
		//seq->size++;//前置长度++，和后置长度++都可以。因为内存早已经申请好了，定义用size长度大小
		for(;i>=0;i--){
		printf("%c\n",seq->c[i+1]);
		seq->c[i+1]=seq->c[i];
		}
		seq->c[0]=value;
		seq->size++;
	}
}
void seqlistpophead(seqlist *seq){
	if(NULL==seq){
		return;
	}
	else if(seq->size==0){
		return;//kong,shanbuliao
	}
	else{
		size_t i=0;
		for(;i<seq->size-1;i++){
			seq->c[i]=seq->c[i+1];
		}
		seq->size--;
	}
}
void seqlistinsert_pos(seqlist *seq,size_t pos,char value){
	if(NULL==seq){
		return;
	}
	else if(seq->size==1000){
		return;//manle,wufacha
	}
	else{
		//seq->size++;
		int j=seq->size-1;
		for(;j>=pos;j--){
			seq->c[j+1]=seq->c[j];
		}
		seq->c[pos]=value;
		seq->size++;
	}
}
void seqlistpush_pos(seqlist *seq,size_t pos){
	if(NULL==seq){
		return;//bugenniwanle
	}
	else if(seq->size==0){
		return;//kong,shanbuliao
	}
	else{
		int m=pos;
		for(;m<seq->size;m++){
			seq->c[m]=seq->c[m+1];
		}
		seq->size--;
	}
}
void seqlistread(seqlist *seq,size_t pos){
	if(NULL==seq){
		return;
	}
	else if(seq->size==0){
		printf("kong,dubuliao\n");
		return;
	}
	else
		printf("[%c]\n",seq->c[pos]);
}
int seqlistfind(seqlist *seq,char value){
	if(NULL==seq){
		return;
	}
	else if(seq->size==0){
		printf("kong,zhaobuliao");
		return;
	}
	else{
		int i=0;
		for(;i<seq->size;i++){
			if(seq->c[i]==value){
				return i;
			}
		}
		return -1;
	}
}

void seqlistinstead(seqlist *seq,size_t pos,char value){
	if(NULL==seq){
		return;
	}
	else if(seq->size==0){
		printf("kong,zhaobuliao");
		return;
	}
	else{
		seq->c[pos]=value;
	}
}
void seqlistremove(seqlist *seq,char value){
	if(seq==NULL){
		return;
	}
	else{
		int pos=seqlistfind(seq,value);
		if(pos!=-1){
			seqlistpush_pos(seq,pos);
		}
	}
}
void seqlistremoveall(seqlist *seq,char value){
	if(seq==NULL){
		return;
	}
	else{
		while(1){
			int pos=seqlistfind(seq,value);
			if(pos!=-1){
				seqlistpush_pos(seq,pos);
				//--seq->size;
			}
			else
				return;
		}
	}
}
void my_swap(seqtype *a,seqtype *b){
	seqtype t=*a;
	*a=*b;
	*b=t;
}
	
void seqlistbubblesort(seqlist *seq){
	if(seq==NULL){
		return;
	}
	else{
		int i=0;
		int j=0;
		for(i=0;i<seq->size-1;i++){
			for(j=0;j<seq->size-1-i;j++){
				if(seq->c[j]>seq->c[j+1]){
				my_swap(&seq->c[j],&seq->c[j+1]);
				}
			}
		}
	}
}
void seqlistxuanzesort(seqlist *seq){
	if(seq==NULL){
		return;//feifashuru
	}
	else{
		int i=0;
		int j=1;
		for(i=0;i<seq->size-1;i++){
			for(j=1+i;j<seq->size;j++){
				if(seq->c[i]>seq->c[j]){
					my_swap(&seq->c[i],&seq->c[j]);
				}
			}
		}
	}
}


//    4 3 2 1   1 4 3 2   i= 0, i =1  4  j =1  1 2 4 3   i 1 2  i = 4,
/////////////////////////////////////////////////
//ceshi
/////////////////////////////////////////////////
void testpushback(){
	HEADER;
	seqlist seq;	
	seqlistInit(&seq);
	
	seqlistpushback(&seq,'a');
	seqlistpushback(&seq,'b');
	seqlistpushback(&seq,'c');
	printf("weichahoudeshunxubiao\n");
	printseqlist(&seq);
}
void testpopback(){
	HEADER;
	seqlist seq;
	seqlistInit(&seq);
	seqlistpushback(&seq,'a');
	seqlistpushback(&seq,'b');
	seqlistpushback(&seq,'c');
	printseqlist(&seq);
	printf("weishanhoudeshunxubiao\n");
	seqlistpopback(&seq);
	printseqlist(&seq);
}
void testpushhead(){
	HEADER;
	seqlist seq;	
	seqlistInit(&seq);

	seqlistpushback(&seq,'a');
	seqlistpushback(&seq,'b');
	seqlistpushback(&seq,'c');
	printseqlist(&seq);
	printf("touchahoudeshunxubiao\n");
	seqlistpushhead(&seq,'x');
	printseqlist(&seq);
}
void testpophead(){
	HEADER;
	seqlist seq;	
	seqlistInit(&seq);

	seqlistpushback(&seq,'a');
	seqlistpushback(&seq,'b');
	seqlistpushback(&seq,'c');
	printseqlist(&seq);
	printf("toushanhoudeshunxubiao\n");
	seqlistpophead(&seq);
	printseqlist(&seq);
}
void testseqlistinsert_pos(){
	HEADER;
	seqlist seq;	
	seqlistInit(&seq);

	seqlistpushback(&seq,'a');
	seqlistpushback(&seq,'b');
	seqlistpushback(&seq,'c');
	printseqlist(&seq);
	size_t pos;
	
	printf("gei---c[%d]---weizhicharuyuansu-[x]\n",pos);
		
	seqlistinsert_pos(&seq,2,'x');
	printseqlist(&seq);
}
void testseqlistpush_pos(){
	HEADER;
	seqlist seq;	
	seqlistInit(&seq);

	seqlistpushback(&seq,'a');
	seqlistpushback(&seq,'b');
	seqlistpushback(&seq,'c');
	printseqlist(&seq);
	size_t pos;
	printf("shanchu---c[%d]---weizhideyuansu\n",pos);
	seqlistpush_pos(&seq,2);
	printseqlist(&seq);
}
void testseqlistread(){
	HEADER;
	seqlist seq;	
	seqlistInit(&seq);

	seqlistpushback(&seq,'a');
	seqlistpushback(&seq,'b');
	seqlistpushback(&seq,'c');
	printseqlist(&seq);
	size_t pos;
	printf("duqu---c[%d]---deyuansu\n",pos);
	seqlistread(&seq,2);
}
void testseqlistfind(){
	HEADER;
	seqlist seq;	
	seqlistInit(&seq);

	seqlistpushback(&seq,'a');
	seqlistpushback(&seq,'b');
	seqlistpushback(&seq,'c');
	printseqlist(&seq);
	printf("chazhao---[b]---dejiaobiao\n");
	seqlistfind(&seq,'b');
}
void testseqlistinstead(){

	HEADER;
	seqlist seq;	
	seqlistInit(&seq);

	seqlistpushback(&seq,'a');
	seqlistpushback(&seq,'b');
	seqlistpushback(&seq,'c');
	printseqlist(&seq);
	seqlistinstead(&seq,2,'d');
	printf("xiugaihoudeshunxubiao:\n");
	printseqlist(&seq);
}
void testseqlistremove(){
	HEADER;
	seqlist seq;	
	seqlistInit(&seq);

	seqlistpushback(&seq,'a');
	seqlistpushback(&seq,'b');
	seqlistpushback(&seq,'c');
	printseqlist(&seq);
	seqlistremove(&seq,'b');
	printseqlist(&seq);
}
void testseqlistremoveall(){
	HEADER;
	seqlist seq;	
	seqlistInit(&seq);

	seqlistpushback(&seq,'a');
	seqlistpushback(&seq,'b');
	seqlistpushback(&seq,'b');
	seqlistpushback(&seq,'b');
	seqlistpushback(&seq,'c');
	printseqlist(&seq);
	seqlistremoveall(&seq,'b');
	printseqlist(&seq);
}
void testseqlistbubblesort(){
	HEADER;
	seqlist seq;	
	seqlistInit(&seq);

	seqlistpushback(&seq,'g');
	seqlistpushback(&seq,'f');
	seqlistpushback(&seq,'e');
	seqlistpushback(&seq,'d');
	seqlistpushback(&seq,'c');
	seqlistpushback(&seq,'b');
	seqlistpushback(&seq,'a');
	printseqlist(&seq);
	seqlistbubblesort(&seq);
	printseqlist(&seq);
}
void testseqlistxuanzesort(){
	HEADER;
	seqlist seq;	
	seqlistInit(&seq);

	seqlistpushback(&seq,'g');
	seqlistpushback(&seq,'f');
	seqlistpushback(&seq,'e');
	seqlistpushback(&seq,'d');
	seqlistpushback(&seq,'c');
	seqlistpushback(&seq,'b');
	seqlistpushback(&seq,'a');
	printseqlist(&seq);
	seqlistxuanzesort(&seq);
	printseqlist(&seq);
}

int main(void)
{
	testpushback();
	testpopback();
	testpushhead();
	testpophead();
	testseqlistinsert_pos();
	testseqlistpush_pos();
	testseqlistread();
	testseqlistfind();
	testseqlistinstead();
	testseqlistremove();
	testseqlistremoveall();
	testseqlistbubblesort();
	testseqlistxuanzesort();
	return 0;
}

