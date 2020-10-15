import myPackage.priorityQueue.PriorityQueue;
import myPackage.priorityQueue.Max_PriorityQueue;
import java.util.*;
class Input{
	public String value;
	public int priority;
	public Input(String value , int priority){
		this.value=value;
		this.priority=priority;
	}
}
class Run{
	public static void main(String[] args) {
		ArrayList<Input> input=new ArrayList<Input>();
		System.out.println("For termanating input use value - end and priority - -1");
		String termanating="end";
		Scanner scan=new Scanner(System.in);
		while(true){
			String str=scan.next();
			int priority=scan.nextInt();
			if(str.equalsIgnoreCase(termanating) && priority==-1)	break;
			Input newInput=new Input(str , priority);
			input.add(newInput);
		}
		// for(int i=0 ; i<input.size();i++)
		// {
		// 	System.out.println(input.get(i).value+" "+input.get(i).priority);
		// }
		//min priorityQueue
		PriorityQueue<String> priority_Queue=new PriorityQueue<String>();
		for(int i=0 ; i<input.size() ; i++){
			priority_Queue.insert(input.get(i).value , input.get(i).priority);
		}
		System.out.println("People in increasing order of their priority");
		while(!priority_Queue.isEmpty()){
			try{
			System.out.println(priority_Queue.removeMin());
		}catch(Exception e){
			System.out.println("Empty PriorityQueue");
		}
		}
		//max priorityQueue
		Max_PriorityQueue<String> max_PriorityQueue=new Max_PriorityQueue<String>();
		for(int i=0 ; i<input.size() ; i++){
			max_PriorityQueue.insert(input.get(i).value , input.get(i).priority);
		}
		System.out.println("People in decreasing order of their priority");
		while(!max_PriorityQueue.isEmpty()){
			try{
			System.out.println(max_PriorityQueue.removeMax());
		}catch(Exception e){
			System.out.println("Empty PriorityQueue");
		}
	}
	}
}