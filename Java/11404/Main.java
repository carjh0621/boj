//boj 11404;

import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static String next() throws IOException{
        while(st==null || !st.hasMoreTokens()){
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
    static int inf = 100000000;
    public static void main(String args[]) throws IOException{
        int n = nextInt();
        int m = nextInt();
        long[][] dist = new long[n+1][n+1];
        for(int i=1; i<=n; i++) Arrays.fill(dist[i],inf);

        for(int i=1;i<=m;i++){
            int s,d,c;
            s=nextInt();
            d=nextInt();
            c=nextInt();
            if(dist[s][d]>c) dist[s][d]=c;
        }
        for(int i=1; i<=n; i++){
            dist[i][i]=0;
        }

        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dist[i][j] > dist[i][k] + dist[k][j]) 
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][j]==inf) 
                    System.out.print("0 ");
                else{
                    System.out.print(dist[i][j] + " ");
                }
            }
            System.out.println();
        }

    }
}
