#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "queue.h"
#define MIN_PER_HR  60.0

bool newcustomer(double x);//�Ƿ����¿͵ĵ���
Item customertime(long when);//���ù˿Ͳ���

int main(void)
{
	Queue line;
	Item temp;				//�µĹ˿�����
	int hours;				//ģ���Сʱ��
	int perhour;			//ÿСʱƽ������λ�˿�
	long cycle, cyclelimit;	//ѭ����������������������
	long turnaways = 0;		//������������ܵĹ˿�����
	long customers = 0;		//������еĹ˿�����
	long served = 0;		//��ģ��������ѳ��Sigmund�Ĺ˿�����
	long sum_line = 0;		//�ۼƵĶ����ܳ�
	int wait_time = 0;		//�ӵ�ǰ��Sigmund���������ʱ��
	double min_per_cust;	//�˿͵�����ƽ��ʱ��
	long line_wait = 0;		//�����ۻ��ĵȴ�ʱ��

	InitializeQueue(&line);
	srand((unsigned int)time(0));
	puts("Case Study:Sigmund Lander s Advice Booth");
	puts("Enter the number of simulation hours:");
	scanf("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	puts("Enter the average number of customers per hour:");
	scanf("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;

	for (cycle = 0; cycle < cyclelimit;cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (QueueIsFull(&line))
				turnaways++;
			else
			{
				customers++;
				temp = customertime(cycle);
				EnQueue(temp, &line);
			}
		}

		if (wait_time <= 0 && !QueueIsEmpty(&line))
		{
			DeQueue(&temp, &line);
			wait_time = temp.processtime;//��䲻�Ǻܶ�
			line_wait += cycle - temp.arrive;
			served++;
		}

		if (wait_time > 0)
			wait_time--;
		sum_line += QueueItemCount(&line);
	}

	if (customers > 0)
	{
		printf("customers accepted : %ld\n", customers);
		printf("  customers served : %ld\n", served);
		printf("	     turnaways : %ld\n", turnaways);
		printf("average queue size : %.2f\n",
			(double)sum_line / cyclelimit);
		printf("average wait  time : %.2f",
			(double)line_wait / served);

		puts("**********************\n");
		printf("sum_line = %ld\n", sum_line);
		printf("line.items = %d\n", line.items);
		puts("**********************");
	}
	else
		puts("No customers");
	EmptyTheQueue(&line);
	puts("Bye");

	return 0;

}

//x�ǹ˿͵�����ƽ��ʱ�䣨���ӣ�
//���1�������й˿͵���������true
bool newcustomer(double x)
{
	if (rand() * x / RAND_MAX < 1)
		return true;
	else
		return false;
}

//when�ǹ˿͵�����ʱ��
//�ú�������һ��Item�ṹ���ù˿͵����ʱ������Ϊwhen
//��ѯʱ������Ϊ1-3�����ֵ
Item customertime(long when)
{
	Item cust;
	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}
