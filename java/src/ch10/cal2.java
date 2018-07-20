package ch10;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

class cal9 extends JFrame{
	
	JTextField up;
	JButton down;
	JButton jia,jian,cheng,chu,point,equ;
	JButton []math=new JButton[10];
	JPanel p;
	
	public cal9()
	{
		super("¼ÆËãÆ÷");
		Container c=getContentPane();
		
		jia=new JButton("+");
		jian=new JButton("-");
		cheng=new JButton("*");
		chu=new JButton("/");
		point=new JButton(".");
		equ=new JButton("=");
		for(int i=0;i<10;i++)
			math[i]=new JButton(String.valueOf(i));
		
		p=new JPanel();
		p.setLayout(new GridLayout(4,4));
		p.add(math[7]);
		p.add(math[8]);
		p.add(math[9]);
		p.add(jia);
		p.add(math[4]);
		p.add(math[5]);
		p.add(math[6]);
		p.add(jian);
		p.add(math[1]);
		p.add(math[2]);
		p.add(math[3]);
		p.add(cheng);
		p.add(math[0]);
		p.add(point);
		p.add(equ);
		p.add(chu);
		
		up=new JTextField("0.");
		up.setHorizontalAlignment(JTextField.RIGHT);
		down=new JButton("CE/C");
		//down.setHorizontalAlignment(JTextField.CENTER);
		
		c.add(up,BorderLayout.NORTH);
		c.add(p,BorderLayout.CENTER);
		c.add(down,BorderLayout.SOUTH);
	}
}
public class cal2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		cal9 c=new cal9();
		c.setSize(200, 200);
		c.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		c.setVisible(true);

	}

}
