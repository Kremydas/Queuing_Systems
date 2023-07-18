

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct node *link;

struct node{
	double afixi;
	double oloklirosi;
	link next; 
};

typedef struct{
	link head, tail;	
} queue;	

void QUEUEfree(queue *q);
int QUEUEempty(queue *q);
link QUEUEput(queue *q, double afixi,double oloklirosi);
double  QUEUEget(queue *q);
void QUEUEprint(queue *q);
void QUEUEinit(queue *q);
double genrand(double rate);




	int main(){
	
		queue q;
		int i,a,b;
		double diff=0,newafixi=0,s=0,sum=0,c,k=0,m=0;
		link l,p;

	   	srand(time(NULL));
	
		QUEUEinit(&q);
		
		
		printf("Choose system, for M/M/1 type 1, for M/D/1 type 2:\n");
		scanf("%d",&a);
		printf("How many costumers are there?\n");
		scanf("%d",&b);
		printf("Set the value of λ ( range [0.1 - 0.9] ):\n");
		scanf("%lf",&c);
		

		if(a==1)		// M/M/1 (Meaning random service time)
		{

		for(i=0 ; i < b ; i++){

		if(QUEUEempty(&q))		// if the queue is empty case
		{
			
			newafixi = genrand(c);
			
		}

		else{
		
		newafixi = p->afixi + genrand(c);		 // if the queue is not empty case
		
		}

		if(!QUEUEempty(&q)){
	
		l = q.head->next;
		
	         while(l!=NULL){
		
		 if(newafixi > l->oloklirosi)		
		{

		diff = QUEUEget(&q);	// queuing time for each customer
		
		sum = sum + diff;	// Total queuing time


		}

			l=l->next;
	                        }


		}
		

		if(QUEUEempty(&q)){

		k=genrand(1.0);
		
		s = newafixi + k;	

		

                }

		else {

		m= genrand(1.0);
		
		s = p->oloklirosi + m; 		
		
		
		}		
		
		
		
		p=QUEUEput(&q,newafixi,s);

		


 	}
		
		
		printf("The average waiting time in the M/M/1 system is :  %lf\n",sum/b);
			
			}



		else if(a==2)		// M/D/1 ( Service time = 1sec )
		{

		for(i=0 ; i < b ; i++){

		if(QUEUEempty(&q))		
		{
			newafixi= genrand(c);
			
		}

		else{
		
		
		newafixi = p->afixi + genrand(c);		
		
		}

		
	
		if(!QUEUEempty(&q)){
	
		l=q.head->next;
		
	         while(l!=NULL){
		
		 if(newafixi > l->oloklirosi)		
		{

		diff=QUEUEget(&q);
		
		sum = sum + diff;


		}

			l=l->next;
	                        }


		}


		if(QUEUEempty(&q)){

		s = newafixi + 1;		

		

                }

		else {

		s = p->oloklirosi + 1; 	
		
		
		}		
		
		
		
		p=QUEUEput(&q,newafixi,s);

		//QUEUEprint(&q);

		
		}

		printf("The average waiting time for the M/D/1 system is  :  %lf\n",sum/b);

		}		
		


	  return 0;
	}


	double genrand(double rate)
	{
		int y;
		double p;

		while(( y=rand() ) == RAND_MAX);

		p = (double) y / RAND_MAX;

		return -log(1-p) / rate;
	}


	link QUEUEput(queue *q, double afixi,double oloklirosi){
	
	link t = (link)malloc(sizeof *t);
	
	t->afixi = afixi;

	t->oloklirosi=oloklirosi;
	
	t->next = q->tail->next;
	
	q->tail->next = t;
	
	q->tail = t; 

	return t;

	}


	double  QUEUEget(queue *q){
	
	link t = q->head->next;
	
	double u = (q->head->next->oloklirosi)-(q->head->next->afixi);
	
	q->head->next = t->next;
	
	if(q->tail == t) 
		
		q->tail = q->head;
		
	free(t);
		
	return u;
	
	}

	void QUEUEprint(queue *q){
	
	link z = q->head->next;
	
	while(z != NULL){
			
		printf("Arrival time : %lf  Completion time : %lf ",z->afixi,z->oloklirosi);
		
		z = z->next;

	}
	
	printf("\n");
	
	}

	void QUEUEinit(queue *q){

	q->head = (link)malloc(sizeof(struct node)); 
	
	q->tail = q->head; 
	
	q->head->next = NULL;

	}	




	int QUEUEempty(queue *q)
	{

		return q->head == q->tail;

	}

	
	void QUEUEfree(queue *q)
	{
		
		while(!QUEUEempty(q))
		
			QUEUEget(q);
			
	

		free(q->head);

		
	}


	

