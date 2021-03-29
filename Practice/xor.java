class xor{
	public static void main(String[] args) {
		String str="cdru";
		int x=0;
		for(int i=0;i<str.length();i++) x^=str.charAt(i);
			System.out.println(x);
	}
}