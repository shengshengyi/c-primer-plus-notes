
/*
��һ���õ��Լ����ļ�
������һ�ⲻ����֤���Ծ�ûд

�ҵı��˵ĺ���

����Ӧ�����м�������

�ж�λ�õ�ʱ��
//ֵ���Ϸ�������,�ų���һ��
if(time != 0)

//ֵ���·�������,�ų����һ��
if(time != rows)

//ֵ����������,�ų���һ��
if(ct != 0)

//ֵ����������,�ų����һ��
if(ct != INTLENTH)




*/


void DealDistortion(int image[][INTLENTH], int rows)
{
    int time,  ct;		//ѭ����������
 
    //��������Ԫ��
    for (time = 0; time < rows; time++)
    {
        for (ct = 0; ct < INTLENTH; ct++)
       	{			
	    int count = 0;		//��¼�Ѿ���������������
            int number = 0;		//����ÿ�λ�ȡ���ĸ��������ֵ
	    int sum = 0;		//��������ֵ�ĵ�����
		
            //����inamg[time][ct]��ֵ
	    int localnum = image[time][ct];
 
	    //�������ֵ�Ĳ�ֵ���������1����ֵΪ1����֮����ֵΪ0
            //���ĳ����û�����ݣ�Ҳ���Ϊ1
	    int flag[4] = { 0,0,0,0 };
 
	    //ֵ���Ϸ�������
	    if (time != 0)
	    {
		number = image[time - 1][ct];    //��ȡ�Ϸ���ֵ
       	        //�Ƚ��Ϸ���ֵ��ԭֵ
	        if (number - localnum > 1 || number - localnum < -1)
	        {
		    sum += number;
		    flag[0] = 1;	//��ֵ����1
		    count++;		//��¼1������
		}
	    }
	    else
                flag[0] = 1;		//����Ϸ�û������
 
	    //ֵ����������
	    if (ct != 0)
	    {
		number = image[time][ct - 1];    //��ȡ�󷽵�ֵ
	        if (number - localnum > 1 || number - localnum < -1)
		{
		    sum += number;
		    flag[1] = 1;		//��ֵ����1
		    count++;		//��¼1������
		}
	    }
	    else
		flag[1] = 1;		//�����û������
 
	    //ֵ���ҷ�������
	    if (time != 19)
	    {
		number = image[time][ct + 1];    //��ȡ�ҷ���ֵ
		if (number - localnum > 1 || number - localnum < -1)
		{
		    sum += number;
		    flag[2] = 1;		//��ֵ����1
		    count++;		//��¼1������
		}
	    }
	    else
		flag[2] = 1;		//����ҷ�û������
 
	    //ֵ���·�������
	    if (ct != 29)
	    {
		number = image[time + 1][ct];    //��ȡ�·���ֵ
	    	if (number - localnum > 1 || number - localnum < -1)
		{
		    sum += number;
		    flag[3] = 1;		//��ֵ����1
		    count++;		//��¼1������
		}
	    }
	    else
	        flag[3] = 1;		        //����·�û������
 
	    //���ܵĲ�ֵ������1��ˢ��ԭֵ��ֻҪ��1����ֵС��1����ˢ��
	    if (flag[0] != 1 || flag[1] != 1 || flag[2] != 1 || flag[3] != 1)
	    {
		flag[0] = 2;		//��ǲ�ˢ��
	    }
 
	    //ˢ��ԭֵ��ע�⣬���ĳ�������Ϊ0
	    if (flag[0] != 2 && count != 0)
	    {
		image[time][ct] = (int)(sum / count);
	    }
	}
    }
}
--------------------- 
��Ȩ����������ΪCSDN������Alex_mercer_boy����ԭ�����£���ѭCC 4.0 by-sa��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/Alex_mercer_boy/article/details/81978835

