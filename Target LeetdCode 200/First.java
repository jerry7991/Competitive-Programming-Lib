public class Test
{ 
public static void main(String[] args)
{
 
int n=sc.nextInt(); 
char c = sc.next().charAt(0);
 
for(int i=1;i<=n;i++)
{
 
for(int j=1;j<=n-i;j++)
 
{
System.out.print(" ");
}
if(i==1 || i==n)
for(int j=1;j<=i*2-1;j++)
 
{
System.out.print(c);
}
else
{
for(int j=1;j<=i*2-1;j++)
 
{ 
if(j==1 || j==i*2-1)
System.out.print(c);
else
 
System.out.print(" ");
}
}
System.out.println();
 
} 
}
}