package 二进制;

import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    static public void main(String[] args)
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int n = cin.nextInt();
        for (int i = 0; i < n; i++)
        {
            String st1 = cin.next();
            String st2 = cin.next();
            BigInteger a = new BigInteger(st1, 2);
            BigInteger b = new BigInteger(st2, 2);
            System.out.println((i + 1) + " " + a.add(b).toString(2));
        }
    }
}
