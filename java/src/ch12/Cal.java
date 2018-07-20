package ch12;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

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
	int sign=1;
	double r=0;
	String ch=new String("");
	
	public cal9()
	{
		super("¼ÆËãÆ÷");
		Container c=getContentPane();
		
		up=new JTextField("0.");
		up.setHorizontalAlignment(JTextField.RIGHT);
		
		jia=new JButton("+");
		jia.addActionListener(new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				
				double a=Double.parseDouble(up.getText());
				if(sign==1)
					r+=a;
				else if(sign==2)
					r-=a;
				else if(sign==3)
					r*=a;
				else if(sign==4)
					r/=a;
				up.setText(String.valueOf(r));
				sign=1;ch="";
			}
			
		});
		
		jian=new JButton("-");
		jian.addActionListener(new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				
				double a=Double.parseDouble(up.getText());
				if(sign==1)
					r+=a;
				else if(sign==2)
					r-=a;
				else if(sign==3)
					r*=a;
				else if(sign==4)
					r/=a;
				up.setText(String.valueOf(r));
				sign=2;ch="";
			}
			
		});
		
		cheng=new JButton("*");
		cheng.addActionListener(new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				
				double a=Double.parseDouble(up.getText());
				if(sign==1)
					r+=a;
				else if(sign==2)
					r-=a;
				else if(sign==3)
					r*=a;
				else if(sign==4)
					r/=a;
				up.setText(String.valueOf(r));
				sign=3;ch="";
			}
			
		});
		
		chu=new JButton("/");
		chu.addActionListener(new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				
				double a=Double.parseDouble(up.getText());
				if(sign==1)
					r+=a;
				else if(sign==2)
					r-=a;
				else if(sign==3)
					r*=a;
				else if(sign==4)
					r/=a;
				up.setText(String.valueOf(r));
				sign=4;ch="";
			}
			
		});
		
		point=new JButton(".");
		point.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				ch+=e.getActionCommand();
				up.setText(ch);
			}
		});
		
		equ=new JButton("=");
		equ.addActionListener(new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				
				double a=Double.parseDouble(up.getText());
				if(sign==1)
					r+=a;
				else if(sign==2)
					r-=a;
				else if(sign==3)
					r*=a;
				else if(sign==4)
					r/=a;
				up.setText(String.valueOf(r));
				sign=0;ch="";
			}
			
		});
		for(int i=0;i<10;i++)
		{
			math[i]=new JButton(String.valueOf(i));
			math[i].addActionListener(new ActionListener(){

				@Override
				public void actionPerformed(ActionEvent e) {
					// TODO Auto-generated method stub
					ch+=e.getActionCommand();
					up.setText(ch);
				}
				
			});
		}
		
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
		
		
		down=new JButton("CE/C");
		down.addActionListener(new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				sign=1;
				up.setText("0.");
				r=0;
				ch="";
			}
			
		});
		//down.setHorizontalAlignment(JTextField.CENTER);
		
		c.add(up,BorderLayout.NORTH);
		c.add(p,BorderLayout.CENTER);
		c.add(down,BorderLayout.SOUTH);
	}
}
public class Cal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		cal9 c=new cal9();
		c.setSize(300, 300);
		c.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		c.setVisible(true);
	}

}
