package ch13;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Image;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JApplet;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

public class J_List extends JApplet{
	
	private String m_items[]={"snow.gif","flag.gif","rain.gif"};
	private JList m_list=new JList(m_items);
	private JLabel m_label=new JLabel();
	private Icon m_icons[]=new ImageIcon[3];
	private Image m_image[]=null;
	Container m_container=null;
	
	public void init()
	{
		int i;
		if(m_image==null)
		{
			m_image=new Image[3];
			for(i=0;i<3;i++)
			{
				m_image[i]=getImage(getCodeBase(),m_items[i]);
			}
		}
		for(i=0;i<3;i++)
			m_icons[i]=new ImageIcon(m_image[i]);
		if(m_container==null)
			m_container=getContentPane();
		m_container.setLayout(new BorderLayout());
		m_container.add(m_list,BorderLayout.WEST);
		m_list.setSelectedIndex(0);
		m_list.addListSelectionListener(new ListSelectionListener(){

			@Override
			public void valueChanged(ListSelectionEvent arg0) {
				// TODO Auto-generated method stub
				int s=m_list.getAnchorSelectionIndex();
				m_label.setIcon(m_icons[s]);
			}
			
		});
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		JFrame f=new JFrame("app");
		J_List app=new J_List();
		
		app.m_container=f.getContentPane();
		app.m_image=new Image[3];
		app.init();
		f.setSize(200, 110);
		f.setVisible(true);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}
