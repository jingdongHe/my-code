package ch7;
/*����ַ�����www.google.com���ĳ��ȣ����ֱ���㲢��ʾ����o�� 
 * �롮g���ĸ�������ȡ���С�google�����������ʾ��*/
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
