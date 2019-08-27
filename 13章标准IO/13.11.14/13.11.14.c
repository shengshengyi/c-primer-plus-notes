
/*
上一题用的自己的文件
导致这一题不好验证所以就没写

找的别人的函数

这里应该是有几个错误

判断位置的时候
//值的上方有数据,排除第一行
if(time != 0)

//值的下方有数据,排除最后一行
if(time != rows)

//值的左方有数据,排除第一列
if(ct != 0)

//值的左方有数据,排除最后一列
if(ct != INTLENTH)




*/


void DealDistortion(int image[][INTLENTH], int rows)
{
    int time,  ct;		//循环计数变量
 
    //遍历所有元素
    for (time = 0; time < rows; time++)
    {
        for (ct = 0; ct < INTLENTH; ct++)
       	{			
	    int count = 0;		//记录已经遍历过几个方向
            int number = 0;		//储存每次获取到的各个方向的值
	    int sum = 0;		//储存相邻值的点数和
		
            //储存inamg[time][ct]的值
	    int localnum = image[time][ct];
 
	    //标记相邻值的差值，如果大于1，该值为1，反之，该值为0
            //如果某方向没有数据，也标记为1
	    int flag[4] = { 0,0,0,0 };
 
	    //值的上方有数据
	    if (time != 0)
	    {
		number = image[time - 1][ct];    //获取上方的值
       	        //比较上方的值和原值
	        if (number - localnum > 1 || number - localnum < -1)
	        {
		    sum += number;
		    flag[0] = 1;	//差值大于1
		    count++;		//记录1个方向
		}
	    }
	    else
                flag[0] = 1;		//如果上方没有数据
 
	    //值的左方有数据
	    if (ct != 0)
	    {
		number = image[time][ct - 1];    //获取左方的值
	        if (number - localnum > 1 || number - localnum < -1)
		{
		    sum += number;
		    flag[1] = 1;		//差值大于1
		    count++;		//记录1个方向
		}
	    }
	    else
		flag[1] = 1;		//如果左方没有数据
 
	    //值的右方有数据
	    if (time != 19)
	    {
		number = image[time][ct + 1];    //获取右方的值
		if (number - localnum > 1 || number - localnum < -1)
		{
		    sum += number;
		    flag[2] = 1;		//差值大于1
		    count++;		//记录1个方向
		}
	    }
	    else
		flag[2] = 1;		//如果右方没有数据
 
	    //值的下方有数据
	    if (ct != 29)
	    {
		number = image[time + 1][ct];    //获取下方的值
	    	if (number - localnum > 1 || number - localnum < -1)
		{
		    sum += number;
		    flag[3] = 1;		//差值大于1
		    count++;		//记录1个方向
		}
	    }
	    else
	        flag[3] = 1;		        //如果下方没有数据
 
	    //四周的差值都大于1，刷新原值。只要有1个差值小于1，则不刷新
	    if (flag[0] != 1 || flag[1] != 1 || flag[2] != 1 || flag[3] != 1)
	    {
		flag[0] = 2;		//标记不刷新
	    }
 
	    //刷新原值，注意，最后的除数不能为0
	    if (flag[0] != 2 && count != 0)
	    {
		image[time][ct] = (int)(sum / count);
	    }
	}
    }
}
--------------------- 
版权声明：本文为CSDN博主「Alex_mercer_boy」的原创文章，遵循CC 4.0 by-sa版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/Alex_mercer_boy/article/details/81978835

