import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        // Print "Hello, World!" to the console
        //System.out.println("Hello, World!");
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        scanner.nextLine();
        while( q != 0 )
        {
            q--;
            String s = scanner.nextLine();

            int a = 0, b = 0;
            for(int i=0;i<s.length();i++)
            {
                if( s.charAt(i) == 'A' ) a++;
                else b++;
            }

//            System.out.println(a);
  //          System.out.println(b);
            if( a > b ) System.out.println("A");
            else System.out.println("B");
        }
    }
}

