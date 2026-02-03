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

    static int[][] multiply(int[][] X, int[][] Y, int N){
        int[][] R = new int[N][N];
        
        for(int r=0;r<N;r++){
            for(int c=0;c<N;c++){
                int tmp=0;
                for(int i=0;i<N;i++){
                    tmp += X[r][i]*Y[i][c];
                }
                R[r][c]=tmp%1000;
            }
        }
        return R;
    }

    static int[][] pow(int[][] A, long B, int N){
        int[][] result= new int[N][N];
        for(int i=0; i<N; i++){
            for(int j=0;j<N;j++){
                if(i==j) result[i][j]=1;
                else result[i][j]=0;
            }
        }

        while(B>0){
            if((B & 1L) == 1L){
                result = multiply(result, A, N);
            }
            A = multiply(A,A,N);
            B=B>>1;
        }

        return result;
    }

    

    public static void main(String[] args) throws IOException{
        int N = nextInt();
        long B = nextLong();
        int[][] A = new int[N][N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                A[i][j]=nextInt();
            }
        }

        int[][] ans = pow(A,B,N);
        
        for(int i=0; i<N;i++){
            for(int j=0;j<N;j++){
                System.out.print(ans[i][j]+" ");
            }
            System.out.println();
        }
        

    }
}
