import java.util.*;
import java.math.*;

public class Main{
    static int number[] = {2,5,5,4,5,6,3,7,6};
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        BigInteger[] ans = new BigInteger[2005];
        for(int i = 0; i < ans.length; i++) {ans[i] = BigInteger.ZERO;}
        for(int i = 2; i <= 2000; i++){
            for(int a : number){
                if(a>i)continue;
                else ans[i] = ans[i].add(ans[i-a].add(BigInteger.ONE));
            }
            if(i>=6) ans[i] = ans[i].add(ans[i-6]);
        }
        while(sc.hasNext() ) {
            int n = sc.nextInt();
            if(n>=6) System.out.println(ans[n].add(BigInteger.ONE));
            else System.out.println(ans[n]);
        }
    }
    
}
