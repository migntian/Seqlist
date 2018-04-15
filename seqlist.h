#pragma once
#define HEADER printf("\n------------%s-----------\n",__FUNCTION__)
#include<stdio.h>
#include<stdlib.h>
#define seqlistmaxsize 1000
typedef char seqtype;
typedef struct seqlist{
	seqtype c[seqlistmaxsize];
	size_t size;
}seqlist;
seqlist seq;
void printseqlist(seqlist *seq);
void seqlistInit(seqlist *seq);//chushihua

void seqlistpushback(seqlist *seq,char value);//weicha 
void seqlistpopback(seqlist *seq);
void seqlistpushhead(seqlist *seq,char value);
void seqlistpophead(seqlist *seq);
void seqlistinsert_pos(seqlist *seq,size_t pos,char value);
void seqlistpush_pos(seqlist *seq,size_t pos);
int seqlistfind(seqlist *seq,char value);
void seqlistread(seqlist *seq,size_t pos);
void seqlistinstead(seqlist *seq,size_t pos,char value);	
