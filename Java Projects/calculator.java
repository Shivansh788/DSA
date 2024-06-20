//imported classes
import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JTextField;

//all functions of calculator
public class calculator extends JFrame implements ActionListener {
   //creating variable
   JButton one, two, three, four, five, six, seven, eight, nine, num0, add, sub, div, mult, equalto, exit, point, reset;
   JTextField textField;
   String s = "", ope = "";
   int flag = 0;
   double total1;
   double input1, input2;
   void total(double input1, double inout2, String ope) {
      String total;
      if (ope.equalsIgnoreCase("+")) {
         total1 = input1 + input2;
         total = Double.toString(total1);
         textField.setText(total);
      } else if (ope.equalsIgnoreCase("-")) {
         total1 = input1 - input2;
         total = Double.toString(total1);
         textField.setText(total);
      } else if (ope.equalsIgnoreCase("*")) {
         total1 = input1 * input2;
         total = Double.toString(total1);
         textField.setText(total);
      } else if (ope.equalsIgnoreCase("/")) {
         total1 = input1 / input2;
         total = Double.toString(total1);
         textField.setText(total);
      }
      //clearfields();
   }
   //assigning variable with string
   public calculator() {
      Container container = getContentPane();
      container.setLayout(new FlowLayout());
      JLabel jl = new JLabel(" My Demo Calculator ");
      textField = new JTextField(20);
      one = new JButton(" 1 ");
      two = new JButton(" 2 ");
      three = new JButton(" 3 ");
      four = new JButton(" 4 ");
      five = new JButton(" 5 ");
      six = new JButton(" 6 ");
      seven = new JButton(" 7 ");
      eight = new JButton(" 8 ");
      nine = new JButton(" 9 ");
      num0 = new JButton(" 0 ");
      add = new JButton(" + ");
      sub = new JButton(" - ");
      div = new JButton(" / ");
      mult = new JButton(" * ");
      equalto = new JButton(" = ");
      exit = new JButton(" Exit ");
      point = new JButton(" . ");
      reset = new JButton("C");
      reset.setBackground(Color.YELLOW);
      //adding action listener
      one.addActionListener(this);
      two.addActionListener(this);
      three.addActionListener(this);
      four.addActionListener(this);
      five.addActionListener(this);
      six.addActionListener(this);
      seven.addActionListener(this);
      eight.addActionListener(this);
      nine.addActionListener(this);
      num0.addActionListener(this);
      add.addActionListener(this);
      sub.addActionListener(this);
      mult.addActionListener(this);
      div.addActionListener(this);
      equalto.addActionListener(this);
      exit.addActionListener(this);
      point.addActionListener(this);
      reset.addActionListener(this);
      //adding content to gui
      container.add(jl);
      container.add(textField);
      container.add(one);
      container.add(two);
      container.add(three);
      container.add(add);
      container.add(four);
      container.add(five);
      container.add(six);
      container.add(sub);
      container.add(seven);
      container.add(eight);
      container.add(nine);
      container.add(div);
      container.add(num0);
      container.add(point);
      container.add(mult);
      container.add(equalto);
      container.add(reset);
      container.add(exit);
   }
   //driver code
   public static void main(String arg[]) {
      calculator d = new calculator();
      d.setSize(260, 300);
      d.setVisible(true);
   }
   //evenet handlers
   public void actionPerformed(ActionEvent e) {
      Object o = e.getSource();
      if (o == one) {
         textField.setText(s.concat("1"));
         s = textField.getText();
      } else if (o == two) {
         textField.setText(s.concat("2"));
         s = textField.getText();
      } else if (o == three) {
         textField.setText(s.concat("3"));
         s = textField.getText();
      } else if (o == four) {
         textField.setText(s.concat("4"));
         s = textField.getText();
      } else if (o == five) {
         textField.setText(s.concat("5"));
         s = textField.getText();
      } else if (o == six) {
         textField.setText(s.concat("6"));
         s = textField.getText();
      } else if (o == seven) {
         textField.setText(s.concat("7"));
         s = textField.getText();
      } else if (o == eight) {
         textField.setText(s.concat("8"));
         s = textField.getText();
      } else if (o == nine) {
         textField.setText(s.concat("9"));
         s = textField.getText();
      } else if (o == num0) {
         textField.setText(s.concat("0"));
         s = textField.getText();
      } else if (o == add) {
         textField.setText("");
         input1 = Double.parseDouble(s);
         System.out.println(input1);
         s = "";
         ope = "+";
      } else if (o == sub) {
         textField.setText("");
         input1 = Double.parseDouble(s);
         s = "";
         ope = "-";
      } else if (o == mult) {
         textField.setText("");
         input1 = Double.parseDouble(s);
         s = "";
         ope = "*";
      } else if (o == div) {
         textField.setText("");
         input1 = Double.parseDouble(s);
         s = "";
         ope = "/";
      } else if (o == equalto) {
         if (flag == 0) {
            input2 = Double.parseDouble(s);
            total(input1, input2, ope);
            flag = 1;
         } else if (flag == 1) {
            input2 = Double.parseDouble(s);
            total(input1, input2, ope);
         }
         System.out.println(input1);
      } else if (o == exit) {
         System.exit(0);
      } else if (o == point) {
         textField.setText(s.concat("."));
         s = textField.getText();
      }
      if (o == reset) {
         textField.setText("");
         s = textField.getText();
         total1 = 0;
      }
   }
}