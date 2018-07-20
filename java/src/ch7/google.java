package ch7;
/*输出字符串“www.google.com”的长度，并分别计算并显示出‘o’ 
 * 与‘g’的个数，截取其中“google”进行输出显示。*/
public class google {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s="www.google.com";
		char [] ch=s.toCharArray();
		int o=0,g=0;
		
		for(int i=0;i<s.length();i++)
		{
			if(ch[i]=='o')
				o++;
			else if(ch[i]=='g')
				g++;
		}
		
		System.out.println(s.length());
		System.out.println("o:"+o+" g:"+g);
	}

}
