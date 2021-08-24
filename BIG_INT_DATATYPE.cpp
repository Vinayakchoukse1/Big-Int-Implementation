#include<stdio.h>
// Defining BigInt using structres
typedef struct
{
	char num[309];
	
}BigInt;
                                                
int Strlen(char s[]);
int Strcmp(char s1[],char s2[]);
BigInt reverseStr(BigInt str);                                            // function declarations
BigInt Add(BigInt num1,BigInt num2);
BigInt Sub(BigInt n1,BigInt n2);
BigInt Mul(BigInt num1,BigInt num2);


int main()
{
	int choice=5;	
	BigInt num1,num2,sum,product,difference;
	printf("Enter first number\n");
	scanf("%s",num1.num);
	printf("Enter second number\n");
	scanf("%s",num2.num);
	while(choice!=0)
	{
		printf("\nEnter the choice of operation which u want to perform on the two no \n");
		printf("1.Addition\n2.Substraction\n3.Multiplication\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			sum=Add(num1,num2);
			printf("Sum is %s\n",sum.num);
			break;
		
			case 2:
			difference=Sub(num1,num2);
			printf("Difference is %s\n",difference.num);
			break;
			
			case 3:
			product=Mul(num1,num2);
			printf("Product is %s\n",product.num);
			break;
			
			case 4:
			choice=0;
			break;
		}
	}
}

// Function to calculate length of string i.e no of digits in the no 
int Strlen(char s[])
{
	int i=0;
	while(s[i]!='\0')
	{
		i++;
	}
	return i;
}

// Function to compare the string
int Strcmp(char s1[],char s2[])
{
	int i=0;
	while(s1[i]==s2[i]&&(s1[i]!='\0'))
	{
		i++;
	}
	int ans=(s1[i]-s2[i]);
	if(ans>0)
	{
		return 1;
	}
	else if(ans<0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

// Function to reverse the string 
BigInt reverseStr(BigInt str)
{
	int i,j;
	char temp;
	i = 0;
   	j = Strlen(str.num) - 1;
    while (i < j) 
	{
     	temp = str.num[i];
   		str.num[i] = str.num[j];
   		str.num[j] = temp;
   		i++;
		j--;
   	}
	str.num[Strlen(str.num)]='\0';
	return str;
}

// Function to add the two no by adding each index
BigInt Add(BigInt num1,BigInt num2)
{
	int l1=Strlen(num1.num),l2=Strlen(num2.num),carry=0,i=0;
	BigInt sum;
	sum.num[0]='0';
	while(i<l1 || i<l2)
	{
        int d1=0,d2=0;
        int sumi;
        if(i<l1)
        {
        	d1=num1.num[l1-i-1]-'0';
		}
		if(i<l2)
        {
        	d2=num2.num[l2-i-1]-'0';
		}
        sumi = d1+d2+carry;
        sum.num[i] = sumi%10 + '0';
        carry = sumi/10;
        i++;
    }
    if(carry!=0)
    {
    	sum.num[i]=carry+'0';
    	i++;
	}
	sum.num[i]='\0';                                                               // adding NULL charachter at the end
	sum=reverseStr(sum);														   // since the digitd of the sum are added in the array in reverse order therefore they are reversed to get 
	return sum;
}

// Function to substract the two no by substacting each index
BigInt Sub(BigInt num1,BigInt num2)
{
	int l1=Strlen(num1.num),l2=Strlen(num2.num),borrow=0,diffi,i=0;
	BigInt diff,temp;
	diff.num[0]='0';
	int t,minus_sign=0;
	if((l1<l2)||((l1==l2&&(Strcmp(num1.num,num2.num)<0))))
	{
		temp=num1;
		num1=num2;
		num2=temp;
		
		t=l1;
		l1=l2;
		l2=t;
		minus_sign=1;
	}
    while(i<l1)
	{
		int d1=0,d2=0;
        d1 = num1.num[l1-1-i]-'0';
        if(i<l2)
        {
        	d2=num2.num[l2-1-i]-'0';
		}
        diffi =d1-d2+borrow;
        if(diffi< 0)
		{
            diffi=diffi+10;
            borrow = -1;
        }
		else
            borrow = 0;
        
        diff.num[i] =diffi+'0';
        i++;
    }
	if(minus_sign==1)
	{
		diff.num[i]='-';
		i++;
	}
	diff.num[i]='\0';
	diff=reverseStr(diff);
	return diff;
}

//function to multiply the two no 
BigInt Mul(BigInt num1,BigInt num2)
{
	BigInt pro,ans;
	int i,j,k,l1 = Strlen(num1.num),l2 = Strlen(num2.num),carry=0,term;
	ans.num[0] = '\0';
	num1 = reverseStr(num1);
	num2 = reverseStr(num2);
	
	for(i=0;i<l2;i++)
	{
		int d1=(num2.num[i])-'0';
		for(k=0;k<i;k++)
		{
			pro.num[k] = '0';
		}
		carry=0;
		for(j=0;j<l1;j++)
		{
			int d2=num1.num[j]-'0';
			term = d1 *d2 + carry;
			pro.num[j+k] = 48 + term%10;
			carry = term/10;
		}
		if(carry!=0)
		{
			pro.num[j+k] = carry + 48;
			j++;
		}
		pro.num[j+k] = '\0';
		pro = reverseStr(pro);
		ans = Add(ans,pro);
	}
	return(ans);
}


