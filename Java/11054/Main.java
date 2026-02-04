//boj 11054

import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));    
    static StringTokenizer st;

    static String next() throws IOException{
        while(st == null || !st.hasMoreTokens()){
            String line = br.readLine();
            if(line == null) return null;
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }
    static int nextInt() throws IOException{
        return Integer.parseInt(next());
    }
    static long nextLong() throws IOException{
        return Long.parseLong(next());
    }

    public static void main(String[] args) throws IOException{
        int N = nextInt();
        int[] arr = new int[N];
        int[] inc = new int[N];
        int[] dec = new int[N];

        for(int i=0; i<N; i++){
            arr[i]=nextInt();
        }
        for(int i=0; i<N;i++){
            inc[i]=1;
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]) inc[i]=Math.max(inc[i],inc[j]+1);
            }
        }

        for(int i=N-1;i>=0;i--){
            dec[i]=1;
            for(int j=N-1;j>i;j--){
                if(arr[i]>arr[j]) dec[i]=Math.max(dec[i], dec[j]+1);
            }
        }

        int ans=0;
        for(int i=0;i<N;i++){
            ans = Math.max(ans, inc[i]+dec[i]-1);
        }
        System.out.println(ans);
    }
}
