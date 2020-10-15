import java.util.*;
import java.util.Collection.*;
class Sol2{
	public static void main(String[] args) {
		Scanner scnr=new Scanner(System.in);
		int n1=scnr.nextInt();
		int n2=scnr.nextInt();
		ArrayList al=new ArrayList();
		int no1=n1;
		int no2=n2;
		int digit1=0;
		int digit2=0;
		while(no1!=0 && no2!=0){
			digit1=no1%10;
			al.add(digit1);
			no1=no1/10;
		}
		digit2=Integer.parseInt(Integer.toString(n2).substring(0,1));
		Collections.sort(al);
		//System.out.println(al);
		//ListIterator li=al.ListIterator();
		int small=999;
		int first=0,netno=0,l=0;
		for(int i=0;i<al.size();i++){
			int ele=(int)al.get(i);
			if(ele>digit2||ele==digit2){
				int diff=Math.abs(ele-digit2);
				if(diff<small){
					small=diff;
					first=ele;
					l=i;
				}
			}
		}
		netno=first;
		al.remove(l);
		//System.out.println(al);
		for(int i=0;i<al.size();i++){
			netno=netno*10+(int)al.get(i);
		}
		if(netno>n2){
			System.out.println(netno);
		}
		else{
			System.out.println(-1);
		}

		//int tr=al.indexOf(digit2);
		//System.out.println(al);
		//Collections.sort(al);
		//System.out.println(al.indexOf(0));
		//System.out.println(al);
		//System.out.println(digit2);

	}
}