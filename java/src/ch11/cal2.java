package ch11;

import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JTextField;


class cal9 extends JFrame{
	JTextField add1,add2;
	JButton equ;
	JTextField res;
	JComboBox sign;
	public cal9()
	{
		super("¼ÆËãÆ÷");
		Container c=getContentPane();
		c.setLayout(new FlowLayout());
		
		add1=new JTextField("",4);
		add2=new JTextField("",4);
		String []s={"+","-","*","/"};
		//char [] s={'+','-','*','/'};
		sign=new JComboBox(s);
		equ=new JButton("=");
		equ.setSize(1, 1);
		equ.addActionListener(new ActionListener()
		{

			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				double a,b,c=0;
				a=Double.parseDouble(add1.getText());
				b=Double.parseDouble(add2.getText());
				String s=(String) sign.getSelectedItem();
				if(s.equals("+"))
					c=a+b;
				else if(s.equals("-"))
					c=a-b;
				else if(s.equals("*"))
					c=a*b;
				else if(s.endsWith("/"))
					c=a/b;
				res.setText(String.valueOf(c));
			}
			
		});
		res=new JTextField("",4);
		
		c.add(add1);
		c.add(sign);
		c.add(add2);
		c.add(equ);
		c.add(res);
		
	}
}
public class cal2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		cal9 c=new cal9();
		c.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		c.setSize(300, 100);
		c.setVisible(true);
	}

}
