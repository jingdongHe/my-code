package ch10;

import java.awt.Container;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;

class cal extends JFrame{
	JTextField add1,add2,sign;
	JButton equ;
	JTextField res;
	public cal()
	{
		super("¼ÆËãÆ÷");
		Container c=getContentPane();
		c.setLayout(new FlowLayout());
		
		add1=new JTextField("",4);
		add2=new JTextField("",4);
		sign=new JTextField("+",2);
		sign.setEditable(false);
		equ=new JButton("=");
		equ.setSize(1, 1);
		res=new JTextField("",4);
		
		c.add(add1);
		c.add(sign);
		c.add(add2);
		c.add(equ);
		c.add(res);
		
	}
}
public class cal1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		cal c=new cal();
		c.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		c.setSize(300, 100);
		c.setVisible(true);

	}

}
