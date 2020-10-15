class First{
	public static void f(int n){
		if(n==10000000){
			return;
		}
		System.out.println(n);
		f(n+1);
	}
	public static void main(String[] args) {
		f(1);
	}
}